%include '/usr/bin/bib.asm'  
section .bss 
a  resb 2048 
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
 Exp_While1: 
	mov eax, 0
	cmp eax, 0 
	jz  Exit_while1
	mov eax, 1
	mov [c] , eax 
 	mov eax, [c]
	call verificarNegativo 
call iprintLF 
 	jmp Exp_While1
Exit_while1: 
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
