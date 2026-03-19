.386
.model flat, c;
option casemap : none



.data
.data?
_var4 data1 <>
_var5 DWORD  ?

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
	mov eax,5
	ret
_main endp
end

