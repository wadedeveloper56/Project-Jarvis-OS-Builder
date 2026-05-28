.x64
.model flat, c
option casemap:none

; --- Prototypes (No stdcall decorations) ---
extern ExitProcess: proto
extern GetCommandLineA: proto
extern CommandLineToArgvW: proto
extern GetCommandLineW: proto
extern LocalFree: proto

.data
    argc dq 0
    argv dq 0

.code
_start proc
    ; --- 64-bit Shadow Space Setup ---
    sub rsp, 40                 ; 32 bytes shadow space + 8 bytes alignment
    
    ; 1. Get the Unicode Command Line (better for CommandLineToArgvW)
    call GetCommandLineW
    ; rax contains the pointer to the command line string

    ; 2. Parse it like C's main(argc, argv)
    mov rcx, rax                ; Argument 1: LPCWSTR lpCmdLine
    lea rdx, argc               ; Argument 2: int *pNumArgs
    call CommandLineToArgvW
    mov argv, rax               ; rax contains the pointer to the argv array

    ; --- Your code here ---
    ; argv[0] is accessible via [rax]
    ; argv[1] is accessible via [rax + 8], etc.

    ; 3. Clean up argv array
    mov rcx, argv
    call LocalFree

    ; 4. Exit Program
    xor ecx, ecx                ; Exit code 0
    call ExitProcess
_start endp

end _start