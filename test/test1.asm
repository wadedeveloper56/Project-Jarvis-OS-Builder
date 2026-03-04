.x64p
.model flat, c;

Data STRUCT
	var3 SBYTE ?
	var4 TBYTE ?
	var5 SDWORD ?
Data ENDS
.data
_var2 SWORD 6
.data?
_var6 Data <>
_var1 SBYTE  ?
_init SDWORD  ?

.code
_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

