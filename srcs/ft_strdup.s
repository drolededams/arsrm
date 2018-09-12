global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_memcpy

section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	cmp rax, 0
	je retnul
	mov rdi, rax
	push rax
	push r8
	call _malloc
	cmp rax, 0
	je retnul2
	mov rdi, rax
	pop r8
	pop rdx
	pop rsi
	push r12
	call _ft_memcpy
	pop r12
	ret

retnul:
	xor rax, rax
	mov rdi, 1
	push rax
	push r8
	call _malloc
	cmp rax, 0
	je retnul2
	mov rdi, rax
	pop r8
	pop rdx
	pop rsi
	call _ft_memcpy
	ret

retnul2:
	xor rax, rax
	pop rsi
	pop r8
	pop rdx
	ret
