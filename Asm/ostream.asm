
size$1 = 48
$T2 = 52
tv162 = 56
$T3 = 64
in$ = 96
out$ = 368
s$ = 640
__$ArrayPad$ = 672
main    PROC
$LN5:
        sub     rsp, 696                      ; 000002b8H
        mov     rax, QWORD PTR __security_cookie
        xor     rax, rsp
        mov     QWORD PTR __$ArrayPad$[rsp], rax
        mov     DWORD PTR [rsp+32], 1
        mov     r9d, 64                             ; 00000040H
        mov     r8d, 8
        lea     rdx, OFFSET FLAT:$SG31748
        lea     rcx, QWORD PTR out$[rsp]
        call    ??0?$basic_ofstream@DU?$char_traits@D@std@@@std@@QEAA@PEBDHH@Z ; std::basic_ofstream<char,std::char_traits<char> >::basic_ofstream<char,std::char_traits<char> >
        lea     rcx, QWORD PTR s$[rsp]
        call    ??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string<char,std::char_traits<char>,std::allocator<char> >
        lea     rcx, QWORD PTR out$[rsp]
        call    ?is_open@?$basic_ofstream@DU?$char_traits@D@std@@@std@@QEBA_NXZ ; std::basic_ofstream<char,std::char_traits<char> >::is_open
        movzx   eax, al
        test    eax, eax
        je      SHORT $LN2@main
        lea     rdx, OFFSET FLAT:$SG31750
        lea     rcx, QWORD PTR out$[rsp]
        call    ??$?6U?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@PEBD@Z ; std::operator<<<std::char_traits<char> >
$LN2@main:
        lea     rcx, QWORD PTR out$[rsp]
        call    ?close@?$basic_ofstream@DU?$char_traits@D@std@@@std@@QEAAXXZ ; std::basic_ofstream<char,std::char_traits<char> >::close
        mov     DWORD PTR [rsp+32], 1
        mov     r9d, 64                             ; 00000040H
        mov     r8d, 1
        lea     rdx, OFFSET FLAT:$SG31751
        lea     rcx, QWORD PTR in$[rsp]
        call    ??0?$basic_ifstream@DU?$char_traits@D@std@@@std@@QEAA@PEBDHH@Z ; std::basic_ifstream<char,std::char_traits<char> >::basic_ifstream<char,std::char_traits<char> >
        lea     rcx, QWORD PTR in$[rsp]
        call    ?is_open@?$basic_ifstream@DU?$char_traits@D@std@@@std@@QEBA_NXZ ; std::basic_ifstream<char,std::char_traits<char> >::is_open
        movzx   eax, al
        test    eax, eax
        je      $LN3@main
        mov     r8d, 2
        xor     edx, edx
        lea     rcx, QWORD PTR in$[rsp]
        call    ?seekg@?$basic_istream@DU?$char_traits@D@std@@@std@@QEAAAEAV12@_JH@Z ; std::basic_istream<char,std::char_traits<char> >::seekg
        lea     rdx, QWORD PTR $T3[rsp]
        lea     rcx, QWORD PTR in$[rsp]
        call    ?tellg@?$basic_istream@DU?$char_traits@D@std@@@std@@QEAA?AV?$fpos@U_Mbstatet@@@2@XZ ; std::basic_istream<char,std::char_traits<char> >::tellg
        mov     rcx, rax
        call    ??B?$fpos@U_Mbstatet@@@std@@QEBA_JXZ    ; std::fpos<_Mbstatet>::operator __int64
        mov     DWORD PTR size$1[rsp], eax
        movsxd  rax, DWORD PTR size$1[rsp]
        xor     r8d, r8d
        mov     rdx, rax
        lea     rcx, QWORD PTR s$[rsp]
        call    ?resize@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_KD@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::resize
        xor     r8d, r8d
        xor     edx, edx
        lea     rcx, QWORD PTR in$[rsp]
        call    ?seekg@?$basic_istream@DU?$char_traits@D@std@@@std@@QEAAAEAV12@_JH@Z ; std::basic_istream<char,std::char_traits<char> >::seekg
        movsxd  rax, DWORD PTR size$1[rsp]
        mov     QWORD PTR tv162[rsp], rax
        xor     edx, edx
        lea     rcx, QWORD PTR s$[rsp]
        call    ??A?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAD_K@Z ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator[]
        mov     rcx, QWORD PTR tv162[rsp]
        mov     r8, rcx
        mov     rdx, rax
        lea     rcx, QWORD PTR in$[rsp]
        call    ?read@?$basic_istream@DU?$char_traits@D@std@@@std@@QEAAAEAV12@PEAD_J@Z ; std::basic_istream<char,std::char_traits<char> >::read
        lea     rdx, QWORD PTR s$[rsp]
        lea     rcx, OFFSET FLAT:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::cout
        call    ??$?6DU?$char_traits@D@std@@V?$allocator@D@1@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z ; std::operator<<<char,std::char_traits<char>,std::allocator<char> >
$LN3@main:
        lea     rcx, QWORD PTR in$[rsp]
        call    ?close@?$basic_ifstream@DU?$char_traits@D@std@@@std@@QEAAXXZ ; std::basic_ifstream<char,std::char_traits<char> >::close
        mov     DWORD PTR $T2[rsp], 0
        lea     rcx, QWORD PTR in$[rsp]
        call    ??_D?$basic_ifstream@DU?$char_traits@D@std@@@std@@QEAAXXZ
        lea     rcx, QWORD PTR s$[rsp]
        call    ??1?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@XZ ; std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string<char,std::char_traits<char>,std::allocator<char> >
        lea     rcx, QWORD PTR out$[rsp]
        call    ??_D?$basic_ofstream@DU?$char_traits@D@std@@@std@@QEAAXXZ
        mov     eax, DWORD PTR $T2[rsp]
        mov     rcx, QWORD PTR __$ArrayPad$[rsp]
        xor     rcx, rsp
        call    __security_check_cookie
        add     rsp, 696                      ; 000002b8H
        ret     0
main    ENDP