global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit


section .text

_ft_isalnum:
	xor rax, rax
	call _ft_isalpha
	cmp rax, 0x01
	je return
	call _ft_isdigit

return:
	ret

