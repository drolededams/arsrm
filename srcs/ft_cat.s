global _ft_cat

section .bss
   buffer resb 128

section .text

_ft_cat:
	mov r12, rdi

looping:
	mov rdi, r12
	;xor rsi, rsi
	lea rsi, [rel buffer]
	mov rdx, 128
	mov rax, 0x02000003
	syscall
	;cmp rax, 0x00
	;jl return
	;jc return
	test eax, eax
	js return
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	push rax
	mov rax, 0x02000004
	syscall
	pop rax
	cmp rax, 0x00
	jne looping

return:
	ret


