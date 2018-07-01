section .data
new_line:
	db "(null)", 10

global _ft_puts

section .text

_ft_puts:
	xor rax, rax
	dec rax
	mov r8, rdi
	cmp rdi, 0x00
	je prin_nul
	push rdi

looping:
	inc rax
	cmp byte [r8 + rax], 0x00
	jne looping

nl:
	mov rdi, 1
	mov rsi, r8
	mov rdx, rax
	mov rax, 0x02000004
	syscall
	mov rdi, 1
	lea rsi, [rel new_line + 6]
	mov rdx, 1
	mov rax, 0x02000004
	syscall
	pop rdi
	ret

prin_nul:
	push r12
	mov rdi, 1
	lea rsi, [rel new_line]
	mov rdx, 7
	mov rax, 0x02000004
	syscall
	pop r12
	ret

