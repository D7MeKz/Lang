example::main:
        sub     rsp, 56
        lea     rdi, [rsp + 8]
        lea     rsi, [rip + .L__unnamed_4] # 문자열 할당 
        mov     edx, 1
        lea     rcx, [rip + .L__unnamed_2]
        xor     eax, eax
        mov     r8d, eax
        call    core::fmt::Arguments::new_v1
        lea     rdi, [rsp + 8]
        call    qword ptr [rip + std::io::stdio::_print@GOTPCREL]
        add     rsp, 56
        ret

.L__unnamed_5:
        .ascii  "invalid args"

.L__unnamed_1:
        .quad   .L__unnamed_5
        .asciz  "\f\000\000\000\000\000\000"

.L__unnamed_2:

.L__unnamed_6:
        .ascii  "/rustc/2c8cc343237b8f7d5a3c3703e3a87f2eb2c54a74/library/core/src/fmt/mod.rs"

.L__unnamed_3:
        .quad   .L__unnamed_6
        .asciz  "K\000\000\000\000\000\000\000\221\001\000\000\r\000\000"

.L__unnamed_7:
        .ascii  "Hello, world!\n"

.L__unnamed_4:
        .quad   .L__unnamed_7
        .asciz  "\016\000\000\000\000\000\000"