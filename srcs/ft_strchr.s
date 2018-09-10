global _ft_strchr
extern _ft_strlen

section .text

_ft_strchr:
	xor rax, rax
	push rdi
	push rsi
	call _ft_strlen
	pop rsi
	pop rdi
	cmp rax, 0
	je return

init:
	mov rdx, rax
	add rdx, 1
	xor rcx, rcx
	xor rax, rax

loop:
	cmp rdx, rcx
	je return
	add rcx, 1
	cmp [rdi], sil
	je found
	inc rdi
	jmp loop

found:
	mov rax, rdi

return:
	ret
