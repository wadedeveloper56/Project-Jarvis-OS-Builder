.x64
.model flat, stdcall
option casemap:none
option frame:auto

; Win32 Prototypes
GetCommandLineA PROTO STDCALL;
ExitProcess PROTO STDCALL :DWORD;
CommandLineToArgvA PROTO C, lpCmdLine:PTR BYTE, pNumArgs:PTR DWORD;
LocalFree PROTO STDCALL :DWORD;

; C Runtime (CRT) Prototypes
printf PROTO C :VARARG;
__getmainargs PROTO C, _Argc:PTR SDWORD, _Argv:PTR PTR SBYTE, _Env:PTR PTR SBYTE, _DoWildCard:SDWORD, _StartInfo:PTR DWORD;

;external main
_main PROTO _argc:SDWORD , _argv:QWORD ;

.data?
    ; Define uninitialized variables for the CRT
    pArgc   dd ?
    pArgv   dq ?
    pEnv    dq ?
    pMode   dq ?

.code

mainCRTStartup PROC
    ; Initialize C Runtime command line arguments
    lea rax, pMode
    lea rcx, pEnv
    lea rdx, pArgv
    lea rbx, pArgc
    invoke __getmainargs, rbx, rdx, rcx, 0, rax
	mov ecx,pArgc
	mov rdx,pArgv
    call _main
	invoke ExitProcess, 0
mainCRTStartup ENDP

END mainCRTStartup
