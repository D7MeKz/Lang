dwDelay$ = 32
tv69 = 36
tv79 = 40
pParam$ = 64
unsigned long ThreadProc(void *) PROC                   ; ThreadProc
$LN3:
        mov     QWORD PTR [rsp+8], rcx
        sub     rsp, 56                             ; 00000038H
        mov     eax, DWORD PTR pParam$[rsp]
        mov     DWORD PTR dwDelay$[rsp], eax
        call    QWORD PTR __imp_GetCurrentThreadId
        mov     DWORD PTR tv69[rsp], eax
        lea     rdx, OFFSET FLAT:$SG112912
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        mov     ecx, DWORD PTR tv69[rsp]
        mov     edx, ecx
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(unsigned long) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        mov     ecx, DWORD PTR dwDelay$[rsp]
        call    QWORD PTR __imp_Sleep
        call    QWORD PTR __imp_GetCurrentThreadId
        mov     DWORD PTR tv79[rsp], eax
        lea     rdx, OFFSET FLAT:$SG112913
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        mov     ecx, DWORD PTR tv79[rsp]
        mov     edx, ecx
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(unsigned long) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        mov     eax, DWORD PTR dwDelay$[rsp]
        add     rsp, 56                             ; 00000038H
        ret     0
unsigned long ThreadProc(void *) ENDP                   ; ThreadProc

dwThreadId$ = 48
tv82 = 52
dwExitCode$ = 56
hThread$ = 64
main    PROC
$LN4:
        sub     rsp, 88                             ; 00000058H
        lea     rdx, OFFSET FLAT:$SG112940
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        mov     DWORD PTR dwThreadId$[rsp], 0 ; 변수 초기화 dwThreadId = 0
        lea     rax, QWORD PTR dwThreadId$[rsp]

        ; CreateThread
        mov     QWORD PTR [rsp+40], rax
        mov     DWORD PTR [rsp+32], 0
        mov     r9d, 5000               ; 00001388H
        lea     r8, OFFSET FLAT:unsigned long ThreadProc(void *)    ; ThreadProc
        xor     edx, edx
        xor     ecx, ecx
        call    QWORD PTR __imp_CreateThread
        
        mov     QWORD PTR hThread$[rsp], rax
        cmp     QWORD PTR hThread$[rsp], 0
        jne     SHORT $LN2@main ; if (hThread == NULL) return ; 
        call    QWORD PTR __imp_GetLastError 
        mov     DWORD PTR tv82[rsp], eax ; tv82 = Error Code 

        ; Set the Strings and cout offset in register and call the operator << 
        lea     rdx, OFFSET FLAT:$SG112942
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        mov     ecx, DWORD PTR tv82[rsp]
        
        mov     edx, ecx
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(unsigned long) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        jmp     SHORT $LN1@main
$LN2@main:
        mov     ecx, 10000                                ; 00002710H
        call    QWORD PTR __imp_Sleep ; Sleep(10000)

        mov     DWORD PTR dwExitCode$[rsp], 0 ; dwExitCode = 0
        lea     rdx, QWORD PTR dwExitCode$[rsp]
        mov     rcx, QWORD PTR hThread$[rsp]
        call    QWORD PTR __imp_GetExitCodeThread ; GetExitCodeThread(hThread, &dwExitCode)
        mov     rcx, QWORD PTR hThread$[rsp]
        call    QWORD PTR __imp_CloseHandle ; CloseHandle(hThread) 
$LN1@main:
        xor     eax, eax
        add     rsp, 88                             ; 00000058H
        ret     0
main    ENDP

