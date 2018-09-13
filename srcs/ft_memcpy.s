global _ft_memcpy

section .text

_ft_memcpy:
	xor rax, rax
	cmp rdi, 0
	ret
	mov rax, rdi
	mov rcx, rdx
	cld
	rep movsb
	ret
