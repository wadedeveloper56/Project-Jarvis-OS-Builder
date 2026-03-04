.x64p
.model flat, c;

.data
.data?
_init SDWORD  ?

.code
_main PROC C, _argc:SDWORD , _argv:QWORD 
	mov eax, [_argc]
	xor eax,eax
	ret
_main endp
end

