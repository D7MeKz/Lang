#include<Windows.h>
#include<iostream>
#include<tchar.h>

int main(int argc, char* argv[])
{
	HCRYPTPROV hCryptProv;
	HCRYPTKEY hKey;
	LPCTSTR username = __T("keyContainer");

	// @link https://learn.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptacquirecontexta
	if (CryptAcquireContext(&hCryptProv, username, MS_DEF_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
	{
		std::cout << "Created a new key container and acquired context"<<std::endl;
	}
	else if (CryptAcquireContext(&hCryptProv, username, MS_DEF_PROV, PROV_RSA_FULL, 0))
	{
		std::cout << "AcquireContext" << std::endl;
		return 0;
	}
}