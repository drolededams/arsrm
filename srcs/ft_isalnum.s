global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit


section .text

_ft_isalnum:
	xor rax, rax
	push rsi
	call _ft_isalpha
	cmp rax, 0x01
	je return
	push r12
	call _ft_isdigit
	pop r12

return:
	pop rsi
	ret

