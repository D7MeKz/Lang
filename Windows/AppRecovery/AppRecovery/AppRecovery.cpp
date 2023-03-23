// @link msdn https://learn.microsoft.com/en-us/windows/win32/recovery/application-recovery-and-restart-functions
// @link example https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/Win7Samples/winbase/windowserrorreporting/AppRecovery/AppRecovery.c

// ����ڴ� ���ø����̼� ���� ������ �����ͳ� ���¸� �����Ҷ� Application Recovery and Restart(ARR)�� ����Ѵ�.
// �ַ� �ٷ��� �ʴ� ���ܳ� ���ø����̼��� ���信 �����Ҷ� ���ȴ�. 

/*

	RegisterAPplicationRecoveryCallback API��  WER�� crash�� hang�� �߻��� ���μ����� �����ϱ� ������ ȣ��ȴ�.
	�� �ݹ��� faulting process�� context ���ο� ����ȴ�. �� ���ø����̼��� ��ũ�� �ٸ� ���ֹ߼� �޸𸮿� �ֹ߼� �����ͳ� ���� ������ ������ �� �ִ�. 
	�׷��Ƿ� ���� restart�� data�� ����� �� �ְ� �ȴ�. 

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

	// RECOVERY_DEFAULT_PING_INTERVAL�� 5���� ������ �־�����. 
	// ���ø����̼��� �ٷ��� �ʴ� ���ܳ� �������� �����ٸ� Windows Error Reporting(WER)�� recovery callback�� �θ���. 
	// WER�� ������Ʈ �� ȣ����� �ʴ´�. ������Ʈ�� �����ͳ� ���� ������ ������ ��� WM_QUERYENDSESSION�̳� WM_ENDSESSION �޼����� ����ϰ� �ȴ�. 
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
