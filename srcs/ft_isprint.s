global _ft_isprint

section .text

_ft_isprint:
	xor rax, rax
	cmp rdi, 0x20
	jl return
	cmp rdi, 0x7e
	jg return
	jmp print

print:
	mov rax, 1
	jmp return

return:
	ret
