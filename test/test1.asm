.x64p
.model flat, c;

.data
_var2 SWORD 6
.data?
_var1 SBYTE ?
_init SDWORD ?

.code
_main PROC C, _argc:DWORD, _argv:QWORD
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

