global _ft_bzero

section .text

_ft_bzero:
	mov rcx, 0
	mov rdx, rdi
	cmp rcx, rsi
	jl loop
	ret

loop:
	mov byte [rdx], 0
	inc rdx
	inc rcx
	cmp rcx, rsi
	jl loop
	ret
