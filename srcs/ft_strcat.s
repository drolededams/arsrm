global _ft_strcat
extern _ft_strlen

section .text

_ft_strcat:
	push rdi
	push rsi
	push r8
	mov rdi, rsi
	call _ft_strlen
	cmp rax, 0
	je retnochange
	pop r8
	pop rsi
	pop rdi
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

retnochange:
	pop r8
	pop rsi
	pop rdi
	mov rax, rdi
	ret
