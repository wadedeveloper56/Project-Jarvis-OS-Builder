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
_main PROTO C _argc:SDWORD , _argv:DWORD ;
_priceless PROTO C _value:SDWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	invoke _funct, 77
	invoke _priceless, 99
	mov eax,5
	ret
_main endp

_priceless PROC C, _value:SDWORD 
	mov eax,99
	ret
_priceless endp
end

