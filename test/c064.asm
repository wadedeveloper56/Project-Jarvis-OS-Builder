.x64
.model flat, c
option casemap:none

; Windows API Prototypes (Kernel32.dll)
extern GetCommandLineA: PROTO 
ExitProcess PROTO :DWORD

; External C-style main function target
_main PROTO C :DWORD, :QWORD

;includelib kernel32.lib

.code

; --- Main Entry Point (Linker stub looks for _start) ---
_start proc
    sub     rsp, 40                 ; Shadow space + 16-byte alignment allocation

    ; 1. Get raw ANSI command-line pointer from Windows Kernel
    call    GetCommandLineA         ; RAX = pointer to command-line string
    mov     rsi, rax                ; RSI = walk pointer

    ; 2. Allocate spaces on stack for argv array dynamic tracking
    ; We will use a safe stack-allocation method. 
    ; For a robust implementation, we dynamically tokenise the raw string.
    push    rbp
    mov     rbp, rsp
    
    ; Count and separate arguments in place (destructive parsing by replacing spaces with nulls)
    ; Standard Windows rules: Handles quoted strings loosely for execution paths
    xor     ecx, ecx                ; RCX = argc counter
    lea     rdi, [rsp - 512]        ; Allocate temp stack buffer for argv pointers (max 64 args)
    
parse_loop:
    ; Skip leading whitespace
    mov     al, [rsi]
    test    al, al
    jz      parse_done
    cmp     al, ' '
    je      skip_space
    cmp     al, 09h                 ; Tab character
    je      skip_space
    
    ; Found start of an argument token
    mov     [rdi + rcx*8], rsi      ; Store pointer in argv array
    inc     rcx                     ; argc++

find_arg_end:
    mov     al, [rsi]
    test    al, al
    jz      parse_done
    cmp     al, ' '
    je      terminate_token
    cmp     al, 09h
    je      terminate_token
    inc     rsi
    jmp     find_arg_end

terminate_token:
    mov     byte ptr [rsi], 0       ; Replace space with null terminator
    inc     rsi
    jmp     parse_loop

skip_space:
    inc     rsi
    jmp     parse_loop

parse_done:
    ; 3. Setup standard Microsoft x64 calling convention for C main
    ; System V / Windows x64 ABI uses RCX and RDX for first 2 integer/pointer arguments.
    ; main(int argc, char** argv) -> RCX = argc, RDX = argv
    
    mov     edx, ecx                ; Backup argc to preserve order
    mov     rcx, rdx                ; RCX = argc
    mov     rdx, rdi                ; RDX = &argv[0] (pointer to array of strings)

    ; 4. Clear stack alignment setup and call main
    sub     rsp, 32                 ; Standard 32-byte shadow space for C main callee
    call    _main
    add     rsp, 32                 ; Clean shadow space

    ; 5. Exit smoothly using OS Kernel
    mov     ecx, eax                ; Pass main's return value to ExitProcess
    call    ExitProcess
_start endp

end _start