.x64
option casemap:none

; External C Runtime Functions
EXTERN __getmainargs:PROC
EXTERN __main:PROC
EXTERN ExitProcess:PROC

; Structure required by __getmainargs
_startupinfo STRUCT
    newmode DD ?
_startupinfo ENDS

.data
    g_argc          DQ 0
    g_argv          DQ 0
    g_env           DQ 0
    g_wildcard      DD 0
    g_startup       _startupinfo <0>

.code

mainCRTStartup PROC
    ; 1. Allocate shadow space (32 bytes) + align stack to 16 bytes (need to subtract 48)
    sub rsp, 48

    ; 2. Prepare arguments for __getmainargs
    ; int __getmainargs(int *argc, char ***argv, char ***env, int doWildCard, _startupinfo *startInfo)
    lea rcx, g_argc
    lea rdx, g_argv
    lea r8,  g_env
    mov r9d, g_wildcard
    lea rax, g_startup
    mov [rsp+32], rax ; 5th parameter passed via stack (shadow space offset + 32)

    call __getmainargs

    ; 3. Prepare parameters for main(int argc, char **argv)
    mov rcx, g_argc
    mov rdx, g_argv

    ; 4. Call the user's C 'main' function
    call __main

    ; 5. Exit Process. Pass the return value of 'main' (which is in RAX)
    mov rcx, rax
    call ExitProcess

mainCRTStartup ENDP

END
