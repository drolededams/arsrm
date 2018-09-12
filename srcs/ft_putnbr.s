section .data
min:
	db "-2147483648"

global _ft_putnbr
extern _ft_putchar

section .text

_ft_putnbr:
	cmp edi, -2147483648
	je print_min
	cmp edi, 0
	jl print_neg
	jmp begin

print_min:
	push rdi
	mov rdi, 1
	lea rsi, [rel min]
	mov rdx, 11
	mov rax, 0x02000004
	syscall
	pop rdi
	ret

print_neg:
	push rdi
	mov rdi, '-'
	call _ft_putchar
	pop rdi
	mov rax, -1
	imul rdi, rax

begin:
	cmp edi, 0x00
	jge unit
	jmp recurse

unit:
	cmp edi, 0x09
	jle print

recurse:
	mov eax, edi
	mov ecx, 10
	xor rdx, rdx
	div ecx,
	mov rdi, rax
	push rdx
	call _ft_putnbr
	pop rdx
	mov rdi, rdx
	push r12
	call _ft_putnbr
	pop r12
	ret

print:
	push rdi
	add rdi, 48
	call _ft_putchar
	pop rdi
	ret
