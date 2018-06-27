global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_memcpy

section .text

_ft_strdup:
	mov r8, rdi
	push r8
	call _ft_strlen
	mov rcx, rax
	push rcx
	mov rdi, rax
	call _malloc
	cmp rax, 0
	jl retnul
	mov rdi, rax
	pop rdx
	pop rsi
	call _ft_memcpy
	ret

retnul:
	mov rax, 0
	ret
