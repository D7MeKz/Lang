#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Advapi32.lib")

/*
	This funcion applies only to SMB shares. 
	For the other types of shares, such as DFS or WebDAV shares, use WNet Functions 

*/
void wmain(int argc, TCHAR* lpszArgv[])
{
	// @link https://learn.microsoft.com/en-us/windows/win32/api/lmshare/ns-lmshare-share_info_502
	// Information about the shared resource.
	LPSHARE_INFO_502 BufPtr = nullptr, p;
	
	// represent the return code from RPC method 
	NET_API_STATUS res; 
	LPTSTR lpszServer = NULL;
	DWORD er = 0, tr = 0, resume = 0, i; 
	
	switch (argc)
	{
	case 2:
		lpszServer = lpszArgv[1];
		break;
	default:
		printf("Usage: NetShareEnum <servername>\n");
		return;
	}

	printf("Share:              Local Path:                   Uses:   Descriptor:\n");
	printf("---------------------------------------------------------------------\n");
	
	// Call the NetShareEnum function. 
	do
	{
		// @out resume
		res = NetShareEnum(lpszServer, 502, (LPBYTE*)&BufPtr, MAX_PREFERRED_LENGTH, &er, &tr, &resume);
		if (res == ERROR_SUCCESS || res == ERROR_MORE_DATA)
		{
			for (i = 1; i <= er; i++)
			{
				printf("%-20S%-30S%-8u", p->shi502_netname, p->shi502_path, p->shi502_current_uses);
				
				// Security _descripotr structure contains the security information 
				// ex) control, owner, group ... 
				if (IsValidSecurityDescriptor(p->shi502_security_descriptor))
					printf("Yes\n");
				else
					printf("No\n");
				p++;
			}
			NetApiBufferFree(BufPtr);
		}
		else
		{
			printf("Error: %ld\n", res);
		}
	}
	while (res == ERROR_MORE_DATA); // end do
	return;
}
