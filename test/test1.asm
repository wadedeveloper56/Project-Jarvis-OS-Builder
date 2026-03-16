.386
.model flat, c;
option casemap : none



.data
_var2 SWORD 6
.data?
_var1 SBYTE  ?
_var3 SDWORD  ?

.code
_test1 PROTO C;
_test2 PROTO C;

_test1 PROC C
	mov eax,5
	ret
_test1 endp

_test2 PROC C
	mov eax,5
	ret
_test2 endp
end

