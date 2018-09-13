section .data
min:
	db "-2147483648"

global _ft_atoi
extern _ft_strcmp
extern _ft_isdigit

section .text

_ft_atoi:
	push rdi
	lea rsi, [rel min]
	xor rax, rax
	xor r12, r12
	mov r12, 1
	xor r13, r13
	call _ft_strcmp
	pop rdi
	cmp rax, 0
	je ret_min
	jmp pass_char

ret_min:
	mov rax, -2147483648
	ret

pass_char:
	cmp byte [rdi], 0x20
	je str_inc
	cmp byte [rdi], 0x09
	je str_inc
	cmp byte [rdi], 0x0b
	je str_inc
	cmp byte [rdi], 0x0c
	je str_inc
	cmp byte [rdi], 0x0d
	je str_inc
	cmp byte [rdi], 0x0a
	je str_inc
	jmp sign_char

str_inc:
	inc rdi
	jmp pass_char

sign_char:
	cmp byte [rdi], 0x2d
	je is_negative
	cmp byte [rdi], 0x2b
	je is_positive
	jmp calcul

is_negative:
	mov r12, -1
	inc rdi
	jmp calcul

is_positive:
	mov r12, 1
	inc rdi
	jmp calcul

calcul:
	push rdi
	mov sil, [rdi]
	xor rdi, rdi
	mov dil, sil
	xor rax, rax
	call _ft_isdigit
	pop rdi
	cmp rax, 1
	je add_cal
	cmp rax, 0
	je return

add_cal:
	xor rsi, rsi
	mov sil, byte [rdi]
	sub sil, 0x30
	imul r13d, 10
	add r13d, esi
	inc rdi
	jmp calcul

return:
	imul r13d, r12d
	xor rax, rax
	mov eax, r13d
	ret
