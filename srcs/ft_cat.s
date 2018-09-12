global _ft_cat

section .bss
   buffer resb 128

section .text

_ft_cat:
	mov r12, rdi
	push r13

looping:
	mov rdi, r12
	lea rsi, [rel buffer]
	mov rdx, 128
	mov rax, 0x02000003
	syscall
	jc return
	cmp rax, 0x00
	jle return
	push r14
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, 0x02000004
	syscall
	pop r14
	jmp looping

return:
	pop r13
	ret


