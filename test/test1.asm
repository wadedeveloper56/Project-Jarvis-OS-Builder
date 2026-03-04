.x64p
.model flat, c;

.data
.data?
_var1 BYTE  ?
_var2 SWORD  ?
_var3 SDWORD  ?
_var4 SDWORD  ?
_var5 SQWORD  ?

.code
_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

