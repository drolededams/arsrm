
global _ft_putchar

section .text

_ft_putchar:
	push rdi
	lea rsi, [rel rsp]
	mov rdi, 1
	mov rdx, 1
	mov rax, 0x02000004
	syscall
	pop rdi
	ret
