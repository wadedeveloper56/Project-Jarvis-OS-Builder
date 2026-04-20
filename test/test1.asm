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

.data
.data?
_var1 SBYTE 5 dup(?)
_var2 SWORD 6 dup(?)
_var3 SDWORD 7 dup(?)
_var4 SDWORD 8 dup(?)
_var5 SQWORD 9 dup(?)
_var6 REAL4 10 dup(?)
_var7 REAL8 11 dup(?)
_var8 REAL10 12 dup(?)
_var9 SDWORD 13 dup(?)
_var10 type2 14 dup(<>)
_var11 type3 15 dup(<>)

.code
_main PROTO C _argc:SDWORD , _argv:QWORD ;

_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax,5
	ret
_main endp
end

