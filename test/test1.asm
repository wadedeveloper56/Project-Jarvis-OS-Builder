.386
.model flat, c;
option casemap : none

EXTERN _funct :PROTO value: SDWORD ;


.data
_var2 SWORD 6
.data?
_var1 SBYTE  ?
_var3 SDWORD  ?

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;
_priceless PROTO C _value:SDWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	invoke _funct, 77
	invoke _priceless, 88
	mov eax,5
	ret
_main endp

_priceless PROC C, _value:SDWORD 
	mov eax,99
	ret
_priceless endp
end

