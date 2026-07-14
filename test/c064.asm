.x64
option casemap:none

; External Windows APIs
extern GetCommandLineW    : proc
extern CommandLineToArgvW : proc
extern LocalFree          : proc
extern ExitProcess        : proc

; External C++ main function
extern __main             : proc

.code

mainCRTStartup proc
    ; Allocate 56 bytes on the stack:
    ;   - [RSP + 0 to 31]   : 32 bytes mandatory Shadow Space
    ;   - [RSP + 40]        : 8 bytes to temporarily save 'argv'
    ;   - [RSP + 48]        : 8 bytes to receive 'argc' from CommandLineToArgvW
    ; This preserves the required 16-byte stack alignment.
    sub rsp, 56

    ; 1. Get the command line string
    call GetCommandLineW        ; RAX = pointer to command line string
    
    ; 2. Parse the command line string into argc and argv
    mov rcx, rax                ; RCX = lpCmdLine (1st parameter)
    lea rdx, [rsp + 48]         ; RDX = &pNumArgs (2nd parameter pointing to our local argc)
    call CommandLineToArgvW     ; RAX = argv (pointer to array of wchar_t pointers)
    
    mov [rsp + 40], rax         ; Save argv to stack for later use

    ; 3. Prepare parameters and call our C++ entry point: c_main(argc, argv)
    mov ecx, dword ptr [rsp + 48] ; RCX = argc (32-bit integer)
    mov rdx, [rsp + 40]         ; RDX = argv (64-bit pointer)
    call __main                 ; Call C++ main function (returns exit code in EAX)
    
    mov [rsp + 48], eax         ; Temp save the C++ return code in our stack frame

    ; 4. Free the argv memory buffer allocated by CommandLineToArgvW
    mov rcx, [rsp + 40]         ; RCX = argv pointer
    call LocalFree

    ; 5. Exit the application cleanly
    mov ecx, dword ptr [rsp + 48] ; RCX = exit code retrieved from C++
    call ExitProcess            ; Terminate process
    
    ; Unreachable, but balances the stack allocate instruction
    add rsp, 56
    ret
mainCRTStartup endp

end mainCRTStartup