.686
.model flat, stdcall
option casemap :none

; Win32 Prototypes
GetCommandLineA PROTO STDCALL;
ExitProcess PROTO STDCALL :DWORD;
CommandLineToArgvA PROTO C, lpCmdLine:PTR BYTE, pNumArgs:PTR DWORD;
LocalFree PROTO STDCALL :DWORD;

; C Runtime (CRT) Prototypes
printf PROTO C :VARARG;
__getmainargs PROTO C, _Argc:PTR SDWORD, _Argv:PTR PTR SBYTE, _Env:PTR PTR SBYTE, _DoWildCard:SDWORD, _StartInfo:PTR DWORD;

;external main
_main PROTO C _argc:SDWORD , _argv:DWORD ;

.code

mainCRTStartup proc
    LOCAL pCmdLine:DWORD
    LOCAL pArgv:DWORD
    LOCAL argc:DWORD
    LOCAL i:DWORD

    ; 1. Get the command-line string (Returns pointer to CHAR)
    invoke GetCommandLineA
    mov pCmdLine, eax
    test eax, eax
    jz error_exit

    ; 2. Parse the command line into an array of pointers to CHAR
    invoke CommandLineToArgvA, pArgv, addr argc
    mov pArgv, eax
    test eax, eax
    jz error_exit

    ; 3. call main
    mov	edx, pArgv
	mov	ecx, argc
	call _main
	
    ; 5. Free memory allocated by CommandLineToArgvA
    invoke LocalFree, pArgv

    ; Successful exit
    invoke ExitProcess, 0

error_exit:
    invoke ExitProcess, 1

mainCRTStartup endp

END mainCRTStartup
