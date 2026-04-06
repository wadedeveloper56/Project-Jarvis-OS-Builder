.x64p
.model flat, c;
option casemap : none



.data
.data?
_var1 SBYTE  ?
_var2 SWORD  ?

.code
_main PROTO C _argc:SDWORD , _argv:QWORD ;

_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax,5
	ret
_main endp
end

