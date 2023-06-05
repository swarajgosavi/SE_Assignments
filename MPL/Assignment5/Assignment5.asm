%macro inout 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
num dw 0xFFF6 ; Define tyhw number to check

msg1 db 10,"The Number is : "
len1 equ $-msg1
msg2 db "Positive",10
len2 equ $-msg2
msg3 db "Negative",10
len3 equ $-msg3


section .text
global _start
_start:

program:
    inout 1, 1, msg1, len1

    ; 1st Method
    mov ax, [num]
    mov bx, 0000h
    add ax, bx
    js message2
    jmp message1

    ; 2nd Method
    ; rcl al, 01
    ; jc message2
    ; jmp message1

    ; 3rd Method
    ; bt ax, 15
    ; jc message2
    ; jmp message1

message1:
    inout 1, 1, msg2, len2
    jmp exit

message2:
    inout 1, 1, msg3, len3
    jmp exit

exit:
    mov rax, 60
    mov rdx, 0
    syscall