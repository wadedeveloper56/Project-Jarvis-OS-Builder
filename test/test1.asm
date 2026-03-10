.386
.model flat, c;
option casemap : none

EXTERN _funct :PROTO value: DWORD ;

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
_main PROC C, _argc:SDWORD , _argv:DWORD 
	invoke _funct, 77
	mov eax,5
	ret
_main endp
end

