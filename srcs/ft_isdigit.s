global _ft_isdigit

section .text

_ft_isdigit:
	xor rax, rax
	cmp rdi, '0'
	jl return
	cmp rdi, '9'
	jg return
	jmp digit

digit:
	mov rax, 1
	jmp return

return:
	ret
