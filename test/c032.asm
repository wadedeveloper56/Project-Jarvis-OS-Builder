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

.data?
    ; Define uninitialized variables for the CRT
    pArgc   dd ?
    pArgv   dd ?
    pEnv    dd ?
    pMode   dd ?

.code

mainCRTStartup PROC
    ; Initialize C Runtime command line arguments
    lea eax, pMode
    lea ecx, pEnv
    lea edx, pArgv
    lea ebx, pArgc
    invoke __getmainargs, ebx, edx, ecx, 0, eax
    invoke _main, pArgc, pArgv
    invoke ExitProcess, 0
mainCRTStartup ENDP

END mainCRTStartup
