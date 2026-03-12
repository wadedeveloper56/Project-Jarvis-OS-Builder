.386
.model flat, c;
option casemap : none

EXTERN _printf :PROTO format: DWORD ;


.data
_var2 SWORD 6
.data?
_var1 SBYTE  ?
_var3 SDWORD  ?

.code
_main PROTO C _argc:SDWORD , _argv:DWORD ;

_main PROC C, _argc:SDWORD , _argv:DWORD 
