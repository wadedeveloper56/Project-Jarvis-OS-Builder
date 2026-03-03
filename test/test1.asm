.x64p
.model flat, c;

.data
_var3 SQWORD 99
.data?
_var1 DWORD  ?
_var2 SDWORD  ?

.code
_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

