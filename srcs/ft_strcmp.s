global _ft_strcmp

section .text

_ft_strcmp:
	mov rax, 0
	cmp byte [rdi], 0
	je diff

loop:
	cmp byte [rdi], 0
	je diff
	cmp dil, sil
	jne diff
	inc rdi
	inc rsi
	jmp loop

diff:
	mov al, [rdi]
	mov dl, [rsi]
	sub rax, rdx

return:
	ret
