global _ft_strcat

section .text

_ft_strcat:
	xor rax, rax
	dec rax

looping:
	inc rax
	cmp byte [rdi + rax], 0x00
	jne looping

strcpy:
	mov bl, byte [rsi]
	mov [rdi + rax], bl
	inc rsi
	inc rax
	cmp byte [rsi], 0x00
	jne strcpy

return:
	xor bl, bl
	mov [rdi + rax], bl
	mov rax, rdi
	ret
