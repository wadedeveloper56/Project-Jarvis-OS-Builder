.386
.model flat, c;
option casemap : none


type2 STRUCT
	a SDWORD ?
	b SDWORD ?
type2 ENDS
type3 UNION
	a SDWORD ?
	b SDWORD ?
type3 ENDS

.data
.data?
_var1 SDWORD  ?
_var2 SDWORD  ?
_var3 type2 <>
_var4 type3 <>

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	mov eax,5
	ret
_main endp
end

