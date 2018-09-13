global _ft_strcmp

section .text

_ft_strcmp:
	mov rax, 0
	cmp byte [rdi], 0
	je diff

loop:
	cmp byte [rdi], 0
	je diff
	xor rax, rax
	xor rdx, rdx
	mov al, [rdi]
	mov dl, [rsi]
	cmp al, dl
	jne diff
	inc rdi
	inc rsi
	jmp loop

diff:
	xor rax, rax
	xor rdx, rdx
	mov al, [rdi]
	mov dl, [rsi]
	sub rax, rdx

return:
	ret
