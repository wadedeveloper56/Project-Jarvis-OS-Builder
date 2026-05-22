.686
.model flat, stdcall
option casemap :none

; Win32 Prototypes
GetCommandLineA PROTO STDCALL
ExitProcess PROTO STDCALL :DWORD
CommandLineToArgvA PROTO C, lpCmdLine:PTR BYTE, pNumArgs:PTR DWORD
LocalFree PROTO STDCALL :DWORD

; C Runtime (CRT) Prototypes
printf PROTO C :VARARG
__getmainargs PROTO C,
    _Argc:PTR SDWORD,
    _Argv:PTR PTR SBYTE,
    _Env:PTR PTR SBYTE,
    _DoWildCard:SDWORD,
    _StartInfo:PTR DWORD

.data
    msg_count   db "Argument count: %d", 10, 0
    msg_arg     db "argv[%d]: %ws", 10, 0

    ; Variables for __getmainargs
    argc        dd 0
    argv        dd 0
    env         dd 0
    ssi         dd 0

.code

mainCRTStartup PROC
    LOCAL pCmdLine :DWORD
    LOCAL pArgv    :DWORD
    LOCAL iArgc    :DWORD

    ; 1. Get arguments using MSVCRT
    lea eax, ssi
    lea ecx, env
    lea edx, argv
    lea ebx, argc
    invoke __getmainargs, ebx, edx, ecx, 0, eax

    mov eax, argc
    mov iArgc, eax

    ; Print argument count using C printf
    invoke printf, ADDR msg_count, iArgc

    ; 2. Iterate through argv array
    mov ebx, 0                      ; Loop counter
    mov ecx, argv                   ; Pointer to argv array
    
PrintLoop:
    cmp ebx, iArgc
    jge ExitLoop

    mov edx, [ecx + ebx*4]          ; Get pointer to the current string
    mov pArgv, edx

    invoke printf, ADDR msg_arg, ebx, pArgv

    inc ebx
    jmp PrintLoop

ExitLoop:
    invoke ExitProcess, 0

mainCRTStartup ENDP

END mainCRTStartup
