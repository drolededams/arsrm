global _ft_toupper

section .text

_ft_toupper:
	mov rax, rdi
	cmp rdi, 0x60
	jg bound
	jmp return

bound:
	cmp rdi, 0x7b
	jl upper
	jmp return

upper:
	sub rax, 32

return:
	ret
