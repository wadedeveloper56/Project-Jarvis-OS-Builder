.386
.model flat, c;

Data1 UNION
	var3 SBYTE ?
	var4 TBYTE ?
	var5 SDWORD ?
Data1 ENDS
Data2 STRUCT
	var3 SBYTE ?
	var4 TBYTE ?
	var5 SDWORD ?
Data2 ENDS
.data
_var2 SWORD 6
.data?
_var6 Data1 <>
_var7 Data2 <>
_var1 SBYTE  ?
_init SDWORD  ?

.code
_main PROC C, _argc:SDWORD , _argv:DWORD 
	mov eax,5
	ret
_main endp
end

