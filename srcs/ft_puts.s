section .data
new_line:
	db "(null)", 10

global _ft_puts

section .text

_ft_puts:
	xor rax, rax
	dec rax
	mov r8, rdi
	push rdi

looping:
	inc rax
	cmp byte [r8 + rax], 0x00
	jne looping

nl:
	inc rax
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



