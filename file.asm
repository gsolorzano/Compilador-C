section .bss 
 a  resb 2048 
section .data 
  	 menos db 45 
 	 dosPuntos db 58 
 section .text 
 	 global _start 
_start: 
	mov eax, 6
	mov [a] , eax 
 	mov  ebx, 0 
	mov  eax, 1 
	int  80h
	ret 
