.x64p
.model flat, c;

NewData STRUCT
	var3 SBYTE ?
	var4 TBYTE ?
	var5 SDWORD ?
NewData ENDS
.data
_var2 SWORD 6
.data?
_var6 NewData <>
_var1 SBYTE  ?
_init SDWORD  ?

.code
_main PROC C, _argc:DWORD, _argv:QWORD
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

