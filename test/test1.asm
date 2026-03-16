.386
.model flat, c;
option casemap : none


data1 STRUCT
	var1 REAL4 ?
	var2 REAL8 ?
	var3 REAL10 ?
data1 ENDS
data2 UNION
	var1 REAL4 ?
	var2 REAL8 ?
	var3 REAL10 ?
data2 ENDS

.data
.data?
_var4 data1 <>
_var5 data2 <>

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	mov eax,5
	ret
_main endp
end

