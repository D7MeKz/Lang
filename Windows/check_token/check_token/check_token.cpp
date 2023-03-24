#include<Windows.h>
#include<stdio.h>
//@link https://learn.microsoft.com/ko-kr/windows/win32/api/shlobj_core/nf-shlobj_core-isuseranadmin
BOOL IsUserAdmin(VOID)
/*++
Routine Description: This routine returns TRUE if the caller's
process is a member of the Administrators local group. Caller is NOT
expected to be impersonating anyone and is expected to be able to
open its own process and process token.
Arguments: None.
Return Value:
   TRUE - Caller has Administrators local group.
   FALSE - Caller does not have Administrators local group. --
*/
{
	BOOL b;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;
	b = AllocateAndInitializeSid(
		&NtAuthority,
		2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&AdministratorsGroup);
	if (b)
	{
		if (!CheckTokenMembership(NULL, AdministratorsGroup, &b))
		{
			b = FALSE;
		}
		FreeSid(AdministratorsGroup);
	}

	return(b);
}


BOOL GetProcessElevation(TOKEN_ELEVATION_TYPE* pElevationType, BOOL* pIsAdmin)
{
	HANDLE hToken;
	DWORD dwSize;
	BOOL bResult = FALSE;

	// 현재 프로세스 토큰을 얻는다.
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
	{
		return (FALSE);
	}

	// 권한 상승 형태에 관한 정보를 얻는다. 
	// TOKEN_ELEVATION_TYPE 열거형 내의 타입으로 Return
	// TokenElevationTypeFull의 값이 반환된다면, 프로세스가 성공적으로 권한 상승이 이뤄졌음을 알 수 있다. 
	// 필터링된 토큰인지 아닌지에 따라 조건문을 나눈다.
	if (GetTokenInformation(hToken, TokenElevationType, pElevationType, sizeof(TOKEN_ELEVATION_TYPE), &dwSize))
	{
		// 관리자 그룹의 SID 값을 생성한다. 
		BYTE adminSID[SECURITY_MAX_SID_SIZE];
		dwSize = sizeof(adminSID);
		CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, &adminSID, &dwSize);

		if (*pElevationType == TokenElevationTypeLimited)
		{
			HANDLE hUnfilteredToken = NULL;
			// 필터링 되기 이전의 토큰 값을 얻는다. - TokenLinkedToken 
			GetTokenInformation(hToken, TokenLinkedToken, (VOID*)hUnfilteredToken, sizeof(HANDLE), &dwSize); 

			// 원래의 토큰이 관리자의 SID에 포함되는지 확인한다. 
			if (CheckTokenMembership(hUnfilteredToken, &adminSID, pIsAdmin)) bResult = TRUE;

			// 필터되지 않는 토큰은 삭제한다. 
			CloseHandle(hToken);
		}
		else
		{
			// 필터링되지 않는 토큰은 애플리케이션이 관리자에 의해 수행되는지 알 수 있다. 
			*pIsAdmin = IsUserAdmin();
			bResult = TRUE;
		}
	}	
	return(bResult);
}
