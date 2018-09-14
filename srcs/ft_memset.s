global _ft_memset

section .text

_ft_memset:
	cmp rdi, 0
	je return
	mov r8, rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	mov rax, r8
	ret

return:
	mov rax, rdi
	ret
