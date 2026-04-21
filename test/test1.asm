.x64p
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
type5 STRUCT
	a SDWORD ?
	b SDWORD ?
type5 ENDS
type6 UNION
	a SDWORD ?
	b SDWORD ?
type6 ENDS

.data
.data?
_var1 SBYTE  ?
_var2 SWORD  ?
_var3 SDWORD  ?
_var4 SDWORD  ?
_var5 SQWORD  ?
_var6 REAL4  ?
_var7 REAL8  ?
_var8 REAL10  ?
_var9 SDWORD  ?
_var10 type2 <>
_var11 type3 <>
_var12 SDWORD  ?
_var13 type5 <>
_var14 type6 <>

.code
_main PROTO C _argc:SDWORD , _argv:QWORD ;

_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax,5
	ret
_main endp
end

