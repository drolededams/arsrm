global _ft_strrev
extern _ft_strlen
extern _ft_strdup

section .text

_ft_strrev:
	xor rax, rax
	cmp rdi, 0x00
	je return
	push rdi
	call _ft_strlen
	pop rdi
	mov r12, rax
	push rdi
	call _ft_strdup
	pop rdi
	mov rcx, r12
	dec rcx
	xor rdx, rdx
	cmp rcx, rdx
	jg loop
	jmp return

loop:
	mov bl, [rax + rdx]
	mov sil, [rax + rcx]
	mov [rax + rdx], sil
	mov [rax + rcx], bl
	dec rcx
	inc rdx
	cmp rcx, rdx
	jg loop

return:
	ret
