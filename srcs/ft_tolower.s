global _ft_tolower

section .text

_ft_tolower:
	mov rax, rdi
	cmp rdi, 0x40
	jg bound
	jmp return

bound:
	cmp rdi, 0x5b
	jl upper
	jmp return

upper:
	add rax, 32

return:
	ret
