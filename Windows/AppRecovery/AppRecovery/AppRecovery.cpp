// @link msdn https://learn.microsoft.com/en-us/windows/win32/recovery/application-recovery-and-restart-functions
// @link example https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/Win7Samples/winbase/windowserrorreporting/AppRecovery/AppRecovery.c

#include<stdio.h>
#include<Windows.h>

typedef struct _STATE_BLOCK {
	char RandomNumber[16];
} STATE_BLOCK, *PSTATE_BLOCK;

static STATE_BLOCK g_StateBlock;

// Recovery Callback 
static DWORD WINAPI MyRecoveryCallbakc(PVOID pvParameter)
{
	HRESULT hr = E_FAIL;
	BOOL rc;
	HANDLE hFile;
	DWORD bytes_written;
	BOOL RecoveryCancelled;
	PSTATE_BLOCK StateBlock = (PSTATE_BLOCK)pvParameter;


	/* Fail functions if the use has cancelled recovery */
	// Application�� Data�� Recover�ϴ��� ���¸� ��ȯ�ϴ� �Լ�
	// Recovery Callback ���� �� ������ �߻��� ��� E_FAIL ��ȯ  
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
			ApplicationRecoveryFinished(FALSE);
			return 0; 
		}
	}
}
