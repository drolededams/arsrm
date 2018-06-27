global _ft_isalpha

section .text

_ft_isalpha:
	xor rax, rax
	cmp rdi, 0x41
	jl return
	cmp rdi, 0x7a
	jg return
	cmp rdi, 0x5b
	jl alpha
	cmp rdi, 0x60
	jg alpha
	jmp return

alpha: 
	mov rax, 1
	jmp return

return:
	ret

