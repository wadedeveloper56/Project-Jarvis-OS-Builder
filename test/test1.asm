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
_var1 SBYTE  ?
_var2 SWORD  ?
_var3 SDWORD  ?
_var4 SDWORD  ?
_var5 SQWORD  ?
_var6 SDWORD  ?
_var7 type2 <>
_var8 type3 <>

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	mov eax,5
	ret
_main endp
end

