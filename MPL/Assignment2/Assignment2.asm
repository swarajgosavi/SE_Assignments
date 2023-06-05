section .data
msg1 db "Enter string : ",10,13
m1 equ $-msg1

section .bss
string resb 100
result resb 2

section .text
global _start
_start:

mov rax,1
mov rdi,1
mov rsi,msg1
mov rdx,m1
syscall

mov rax,0
mov rdi,0
mov rsi,string
mov rdx,100
syscall

dec al
mov bl,al
mov rsi,result
mov cx,2

hextoascii:
    rol bl,04
    mov dl,bl
    and dl,0Fh
    cmp dl,09h
    jbe next
    add dl,07h

next:
    add dl,30h
    mov [rsi],dl
    inc rsi
    dec cx
    jnz hextoascii

mov rax,1
mov rdi,1
mov rsi,result
mov rdx,02
syscall

mov rax,60
mov rdx,0
syscall