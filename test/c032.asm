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

.DATA?
    stdout             dd ?
    cmdLinePtr         dd ?
    argc               dd ?
    argv               dd 64 dup(?) ; Supports up to 64 command line arguments

.CODE

; --- Custom Startup Code (The Entry Point) ---
_start PROC
    ; 1. Get the raw command line string from Windows
    invoke GetCommandLineA
    mov cmdLinePtr, eax
    
    ; 2. Parse the command line into argc and argv array
    ; This is a basic space-separated parser (ignores quotes for simplicity)
    xor ecx, ecx            ; ecx = argc counter
    mov esi, cmdLinePtr     ; esi points to command line string
    lea edi, argv           ; edi points to our argv array

parse_loop:
    ; Skip leading spaces
    mov al, [esi]
    cmp al, 0
    je parsing_done
    cmp al, ' '
    jne found_arg
    inc esi
    jmp parse_loop

found_arg:
    ; Store the pointer to this argument in the argv array
    mov [edi + ecx*4], esi
    inc ecx                 ; argc++

skip_arg_chars:
    inc esi
    mov al, [esi]
    cmp al, 0
    je parsing_done
    cmp al, ' '
    jne skip_arg_chars
    
    ; We found a space character marking the end of an argument.
    ; Replace it with a Null terminator (\0) so it acts as a C-string.
    mov byte ptr [esi], 0   
    inc esi
    jmp parse_loop

parsing_done:
    mov argc, ecx           ; Save final argument count

    ; 3. Push arguments and call our "C style" main function
    push offset argv
    push argc
    call _main
    add esp, 8              ; Clean up the stack (C calling convention)

    ; 4. Exit the program cleanly without CRT
    invoke ExitProcess, eax

_start ENDP

END _start