extern _ExitProcess@4
extern _main

section .text
global _start
_start:
    sub     esp, 40          ; reserve shadow space and align stack by 16
    call    _main
    xor     ecx, ecx
    call    _ExitProcess@4
  ; add     rsp, 40      ; alternative to calling a noreturn function like ExitProcess
  ; ret

