.x64p
.model flat, c;
option casemap : none


data1 STRUCT
	var1 REAL4 ?
	var2 REAL8 ?
	var3 REAL10 ?
data1 ENDS

.data
.data?
_var4 data1 <>
_var5 QWORD  ?

.code
_main PROTO C _argc:SDWORD , _argv:QWORD ;

_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax,5
	ret
_main endp
end

