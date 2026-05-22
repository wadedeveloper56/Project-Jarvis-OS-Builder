.x64
.model flat, stdcall
option casemap :none

; Win32 Prototypes
GetCommandLineA PROTO STDCALL;
ExitProcess PROTO STDCALL :DWORD;
CommandLineToArgvA PROTO C, lpCmdLine:PTR BYTE, pNumArgs:PTR DWORD;
LocalFree PROTO STDCALL :DWORD;

; C Runtime (CRT) Prototypes
printf PROTO C :VARARG;
__getmainargs PROTO C,
    _Argc:PTR SDWORD,
    _Argv:PTR PTR SBYTE,
    _Env:PTR PTR SBYTE,
    _DoWildCard:SDWORD,
    _StartInfo:PTR DWORD;
_main PROTO C _argc:SDWORD , _argv:DWORD ;

.data
    fmtArgs db "Argument %d: %s", 10, 0
    fmtCount db "Total arguments: %d", 10, 0

.data?
    ; Define uninitialized variables for the CRT
    pArgc   dq ?
    pArgv   dq ?
    pEnv    dq ?
    pMode   dq ?

.code

mainCRTStartup PROC
    ; Align stack for 64-bit Windows and reserve 32 bytes of shadow space
    sub rsp, 28h

    ; Initialize C Runtime command line arguments
    lea rcx, pArgc
    lea rdx, pArgv
    lea r8, pEnv
    mov r9d, 0
    lea rax, pMode
    mov QWORD PTR [rsp+28h], rax
    call __getmainargs

    ; Print total argument count
    mov rdx, pArgc
    lea rcx, fmtCount
    call printf

    ; Print each argument in a loop
    xor rbx, rbx                  ; RBX = index i = 0
    mov rsi, pArgv                ; RSI = char** argv

print_loop:
    cmp rbx, pArgc
    jge loop_end

    mov rdx, rbx                  ; Arg 1: index
    mov r8, QWORD PTR [rsi+rbx*8] ; Arg 2: argv[i]
    lea rcx, fmtArgs
    call printf

    inc rbx
    jmp print_loop

loop_end:
    ; Clean up stack and exit gracefully via CRT
    invoke ExitProcess, 0
mainCRTStartup ENDP

END