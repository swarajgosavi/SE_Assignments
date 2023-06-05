section .data
msg1 db "Enter 5 64bit Numbers : ",10
len1 equ $-msg1
msg2 db 10,"The 5 64bit Numbers are : ",10
len2 equ $-msg2
count1 db 05
count2 db 05

section .bss
num resb 85

section .text
global _start
_start:

mov rax, 01
mov rdi, 01
mov rsi, msg1
mov rdx, len1
syscall

xor rsi, rsi
mov rsi, num

loop1:
    mov rax, 00
    mov rdi, 00
    mov rdx, 17
    syscall

    add rsi, 17
    dec byte[count1]
    jnz loop1

mov rax, 01
mov rdi, 01
mov rsi, msg2
mov rdx, len2
syscall

mov rsi, num

loop2:
    mov rax, 01
    mov rdi, 01
    mov rdx, 17
    syscall

    add rsi, 17
    dec byte[count1]
    jnz loop2

mov rax, 60
mov rdx, 0
syscall
