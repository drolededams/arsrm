global _ft_memcpy

section .text

_ft_memcpy:
	xor rax, rax
	cmp rdi, 0
	je return
	cmp rsi, 0
	je return
	mov rax, rdi
	mov rcx, rdx
	cld
	rep movsb
	ret

return:
	mov rax, rdi
	ret
