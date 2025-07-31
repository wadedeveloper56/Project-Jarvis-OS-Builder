BITS 32
	SECTION .data
	SECTION .bss
var1:  resb 1
var2:  resw 1
var3:  resd 1
var4:  resd 1
var5:  resq 1
var6:  resd 1
var7:  resq 1
var8:  rest 1
var9:  resb 1
var10:  resb 16
var11:  resq 1
var12:  resb 1
	SECTION .text
	 global main
main:
	ret

	 global function2
function2:
	ret

