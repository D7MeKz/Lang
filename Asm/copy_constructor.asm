// x64 msvc v18.14
$T1 = 32
this$ = 64
x$ = 72
y$ = 80
name$ = 88
Photon_cannon::Photon_cannon(int,int,char const *) PROC                    ; Photon_cannon::Photon_cannon
$LN3:
        ; 멤버 변수 
        mov     QWORD PTR [rsp+32], r9 ; num 
        mov     DWORD PTR [rsp+24], r8d ; name 
        mov     DWORD PTR [rsp+16], edx ; y 
        mov     QWORD PTR [rsp+8], rcx ; x 
        sub     rsp, 56                             ; 00000038H
        
        mov     rax, QWORD PTR this$[rsp] ; this pointer 
        mov     ecx, DWORD PTR x$[rsp]
        mov     DWORD PTR [rax+8], ecx ; this-> x = x
        
        mov     rax, QWORD PTR this$[rsp]
        mov     ecx, DWORD PTR y$[rsp]
        mov     DWORD PTR [rax+12], ecx ; this-> y = y

        mov     rcx, QWORD PTR name$[rsp]
        call    strlen
        inc     rax
        mov     rcx, rax
        call    void * operator new[](unsigned __int64)               ; operator new[]
        mov     QWORD PTR $T1[rsp], rax 
        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR $T1[rsp]
        mov     QWORD PTR [rax+24], rcx ;this->name = new char[strlen(name)+1]

        mov     rdx, QWORD PTR name$[rsp]
        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR [rax+24]
        call    strcpy ; strcpy(this->name, name)  

        mov     eax, DWORD PTR static int Photon_cannon::total_num ; Photon_cannon::total_num
        inc     eax
        mov     DWORD PTR static int Photon_cannon::total_num, eax ; Photon_cannon::total_num++ 

        mov     rax, QWORD PTR this$[rsp]
        add     rsp, 56                             ; 00000038H
        ret     0
Photon_cannon::Photon_cannon(int,int,char const *) ENDP                    ; Photon_cannon::Photon_cannon

$T1 = 32
this$ = 64
pc$ = 72 
Photon_cannon::Photon_cannon(Photon_cannon const &) PROC                    ; Photon_cannon::Photon_cannon
$LN3:
        mov     QWORD PTR [rsp+16], rdx
        mov     QWORD PTR [rsp+8], rcx
        sub     rsp, 56                             ; 00000038H
        
        ; rax, rcx는 offset으로 객체를 표현한다. 
        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR pc$[rsp] 
        mov     ecx, DWORD PTR [rcx]
        mov     DWORD PTR [rax], ecx

        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR pc$[rsp]
        mov     ecx, DWORD PTR [rcx+8]
        mov     DWORD PTR [rax+8], ecx ; this->x = pc.x

        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR pc$[rsp]
        mov     ecx, DWORD PTR [rcx+12]
        mov     DWORD PTR [rax+12], ecx

        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR pc$[rsp]
        mov     ecx, DWORD PTR [rcx+16]
        mov     DWORD PTR [rax+16], ecx

        mov     rax, QWORD PTR pc$[rsp]
        mov     rcx, QWORD PTR [rax+24]
        call    strlen
        inc     rax
        mov     rcx, rax ; strlen(name) + 1 
        call    void * operator new[](unsigned __int64)               ; operator new[strlen(name)+1]
        mov     QWORD PTR $T1[rsp], rax
        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR $T1[rsp]
        mov     QWORD PTR [rax+24], rcx ; this-> name = new char[strlen(name)+1]
        mov     rax, QWORD PTR pc$[rsp]
        mov     rdx, QWORD PTR [rax+24]
        mov     rax, QWORD PTR this$[rsp]
        mov     rcx, QWORD PTR [rax+24]
        call    strcpy ; strcpy(this->name, pc.name)

        mov     eax, DWORD PTR static int Photon_cannon::total_num ; Photon_cannon::total_num
        inc     eax
        mov     DWORD PTR static int Photon_cannon::total_num, eax ; Photon_cannon::total_num

        mov     rax, QWORD PTR this$[rsp]
        add     rsp, 56                             ; 00000038H
        ret     0
Photon_cannon::Photon_cannon(Photon_cannon const &) ENDP                    ; Photon_cannon::Photon_cannon

this$ = 48
void Photon_cannon::show_status(void) PROC                ; Photon_cannon::show_status
$LN3:
        mov     QWORD PTR [rsp+8], rcx
        sub     rsp, 40                             ; 00000028H
        ; std::cout << "??"(문자열) 
        lea     rdx, OFFSET FLAT:$SG27537 
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        ; << this->name 
        mov     rcx, QWORD PTR this$[rsp]
        mov     rdx, QWORD PTR [rcx+24]
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        ; << std::endl;
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:$SG27540
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        mov     rcx, QWORD PTR this$[rsp]
        mov     edx, DWORD PTR [rcx+8] ; edx = this->num 
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(int) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:$SG27539
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        mov     rcx, QWORD PTR this$[rsp]
        mov     edx, DWORD PTR [rcx+12]
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(int) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:$SG27538
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:$SG27541
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        mov     rcx, QWORD PTR this$[rsp]
        mov     edx, DWORD PTR [rcx]
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(int) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:$SG27542
        lea     rcx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > std::cout ; std::cout
        call    std::basic_ostream<char,std::char_traits<char> > & std::operator<<<std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &,char const *) ; std::operator<<<std::char_traits<char> >
        
        mov     edx, DWORD PTR static int Photon_cannon::total_num ; Photon_cannon::total_num
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(int) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        lea     rdx, OFFSET FLAT:std::basic_ostream<char,std::char_traits<char> > & std::endl<char,std::char_traits<char> >(std::basic_ostream<char,std::char_traits<char> > &) ; std::endl<char,std::char_traits<char> >
        mov     rcx, rax
        call    std::basic_ostream<char,std::char_traits<char> > & std::basic_ostream<char,std::char_traits<char> >::operator<<(std::basic_ostream<char,std::char_traits<char> > & (__cdecl*)(std::basic_ostream<char,std::char_traits<char> > &)) ; std::basic_ostream<char,std::char_traits<char> >::operator<<
        
        add     rsp, 40                             ; 00000028H
        ret     0
void Photon_cannon::show_status(void) ENDP                ; Photon_cannon::show_status

pc1$ = 32
pc2$ = 64
pc3$ = 96
main    PROC
$LN3:
        sub     rsp, 136                      ; 00000088H
        ; 객체 생성 
        lea     r9, OFFSET FLAT:$SG27548
        mov     r8d, 3
        mov     edx, 3
        lea     rcx, QWORD PTR pc1$[rsp]
        call    Photon_cannon::Photon_cannon(int,int,char const *)   ; Photon_cannon::Photon_cannon
        
        ; 복사 생성자 Photon_cannon pc2(p1) 
        lea     rdx, QWORD PTR pc1$[rsp]
        lea     rcx, QWORD PTR pc2$[rsp]
        call    Photon_cannon::Photon_cannon(Photon_cannon const &)   ; Photon_cannon::Photon_cannon
        
        lea     rdx, QWORD PTR pc2$[rsp]
        lea     rcx, QWORD PTR pc3$[rsp]
        call    Photon_cannon::Photon_cannon(Photon_cannon const &)   ; Photon_cannon::Photon_cannon
        
        lea     rcx, QWORD PTR pc1$[rsp]
        call    void Photon_cannon::show_status(void)     ; Photon_cannon::show_status
        lea     rcx, QWORD PTR pc2$[rsp]
        call    void Photon_cannon::show_status(void)     ; Photon_cannon::show_status
        lea     rcx, QWORD PTR pc3$[rsp]
        call    void Photon_cannon::show_status(void)     ; Photon_cannon::show_status
        xor     eax, eax
        add     rsp, 136                      ; 00000088H
        ret     0
main    ENDP