global _ft_isascii

section .text

_ft_isascii:
	xor rax, rax
	cmp rdi, 0x00
	jl return
	cmp rdi, 0x7f
	jg return
	jmp ascii

ascii:
	mov rax, 1
	jmp return

return:
	ret
