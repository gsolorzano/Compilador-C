%include 'bib.asm'  
section .bss 
a  resb 2048 
Temp1  resb 2048 
c  resb 2048 
section .data 
  	 menos db 45 
 	 dosPuntos db 58 
 section .text 
 	 global _start 
_start: 
	mov eax, 0
	mov [a] , eax 
 	mov eax, [a]
	call verificarNegativo 
call iprintLF 
 	mov eax, [a]
	cmp eax, 0 
	 jz  L_Else1
	mov eax, 4
	mov [Temp1] , eax 
 	jmp Exit_if1
L_Else1: 
	mov eax, 69
	mov [Temp1] , eax 
 Exit_if1: 
	mov eax, [Temp1]
	mov [c] , eax 
 	mov eax, [c]
	call verificarNegativo 
call iprintLF 
 	mov  ebx, 0 
	mov  eax, 1 
	int  80h
	ret 



verificarNegativo: 
	cmp eax, 0 
	jge .return 
	push eax 
	mov eax, 4
	mov ebx, 1
	mov ecx, menos
	mov edx, 1
	int 80h
	pop eax 
	neg eax
	.return:
	ret
