.386
.model flat, c

.data
_var2 SWORD 6
_var3 SDWORD 7
_var4 SDWORD 8
_var5 SQWORD 9
_var6 SDWORD 10.000000
_var7 SQWORD 11.000000
_var8 TBYTE 12.000000
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

