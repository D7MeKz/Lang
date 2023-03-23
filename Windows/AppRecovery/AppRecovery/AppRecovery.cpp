// @link msdn https://learn.microsoft.com/en-us/windows/win32/recovery/application-recovery-and-restart-functions
// @link example https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/Win7Samples/winbase/windowserrorreporting/AppRecovery/AppRecovery.c

// 사용자는 애플리케이션 존재 이전에 데이터나 상태를 저장할때 Application Recovery and Restart(ARR)를 사용한다.
// 주로 다루지 않는 예외나 애플리케이션이 응답에 실패할때 사용된다. 

/*

	RegisterAPplicationRecoveryCallback API는  WER이 crash나 hang이 발생해 프로세스를 종료하기 이전에 호출된다.
	이 콜백은 faulting process의 context 내부에 실행된다. 그 애플리케이션은 디스크나 다른 비휘발성 메모리에 휘발성 데이터나 상태 정보를 저장할 수 있다. 
	그러므로 다음 restart때 data를 사용할 수 있게 된다. 

*/
#include<stdio.h>
#include<Windows.h>

typedef struct _STATE_BLOCK {
	char RandomNumber[16];
} STATE_BLOCK, *PSTATE_BLOCK;

static STATE_BLOCK g_StateBlock;

// Recovery Callback 
static DWORD WINAPI MyRecoveryCallback(PVOID pvParameter)
{
	HRESULT hr = E_FAIL; // Handle Result 
	BOOL rc;
	HANDLE hFile; // File Handle
	DWORD bytes_written;
	BOOL RecoveryCancelled;
	PSTATE_BLOCK StateBlock = (PSTATE_BLOCK)pvParameter;


	/* Fail functions if the use has cancelled recovery */
	// Application이 Data를 Recover하는지 상태를 반환하는 함수
	// Recovery Callback 실행 시 오류가 발생할 경우 E_FAIL 반환  
	hr = ApplicationRecoveryInProgress(&RecoveryCancelled);
	if (FAILED(hr))
	{
		ApplicationRecoveryFinished(FALSE);
		return 0;
	}

	if (RecoveryCancelled)
	{
		// User has cancelled recovery 
		return 0;
	}

	// Do the recovery here
	hFile = CreateFile(L"recovered_data.txt",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		0,
		NULL);
	
	if (hFile != INVALID_HANDLE_VALUE)
	{
		rc = WriteFile(hFile, StateBlock, sizeof(StateBlock), &bytes_written, NULL);
	
		if (!rc)
		{
			ApplicationRecoveryFinished(FALSE); // Fail to recover the file 
			return 0; 
		}
		CloseHandle(hFile);

		Sleep(3000);

		// Completed recovery
		ApplicationRecoveryFinished(TRUE);
		return 0;
	}
	else 
	{
		// we couldn't open the file .
		ApplicationRecoveryFinished(FALSE);
		return 0;
	}
}

int wmain(int argc, const wchar_t* argv[], const wchar_t* envp[])
{
	HRESULT hr = E_FAIL;

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);
	UNREFERENCED_PARAMETER(envp);

	// RECOVERY_DEFAULT_PING_INTERVAL은 5초의 간격이 주어진다. 
	// 애플리케이션이 다루지 않는 예외나 미응답을 만난다면 Windows Error Reporting(WER)는 recovery callback을 부른다. 
	// WER은 업데이트 시 호출되지 않는다. 업데이트의 데이터나 상태 정보를 저장할 경우 WM_QUERYENDSESSION이나 WM_ENDSESSION 메세지를 사용하게 된다. 
	// @link https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-registerapplicationrecoverycallback
	hr = RegisterApplicationRecoveryCallback(MyRecoveryCallback, &g_StateBlock, RECOVERY_DEFAULT_PING_INTERVAL, 0);
	if (FAILED(hr))
	{
		wprintf(L"RegisterApplicationRecoveryCallback failed with 0x%08X\n", hr);
		return -1;
	}

	wprintf(L"Successfully registered this process for recovery.\n");

	// Save a random number into our state block
	// This is block we will trying to recover later.
	sprintf_s(g_StateBlock.RandomNumber, sizeof(g_StateBlock.RandomNumber), "%d", rand());

	// crash the application by writing to a NULL pointer
	wprintf(L"Crashing the application...\n");
	fflush(stdout);

	*((int*)NULL) = 0;
	return 0;
}
