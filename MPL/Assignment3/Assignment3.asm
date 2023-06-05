; Works for single digit numbers
; For other define arr in .data section 
; Follow the same Algorithm

%macro inout 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data

msg1 db "Enter 5 Numbers : ",10
len1 equ $-msg1

msg2 db 10,"The 5 Numbers are : ",10
len2 equ $-msg2

msgMax db 10,"Largest Number = "
msgMaxLen equ $-msgMax

; num db 4, 7, 1, 9, 10

count1 db 05
count2 db 05
cnt db 05

section .bss
num resb 10
maxnum resb 1

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
    mov rdx, 2
    syscall

    add rsi, 2
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
    mov rdx, 2
    syscall

    add rsi, 2
    dec byte[count2]
    jnz loop2

inout 1, 1, msgMax, msgMaxLen

LargestNum:
    mov byte[cnt], 5

    mov al, 0h
    mov rdi, num

    loop3:
        cmp [rdi], al
        jbe NoUpdate
    Update:
        mov al, [rdi]
    NoUpdate:
        inc rdi
        inc rdi         ; As we take array from user one enter is also stored
        dec byte[cnt]
        jnz loop3

hextoascii:
    mov byte[cnt], 2
    mov rdi, maxnum

    loop4:
        rol al, 4
        mov bl, al
        and bl, 0Fh

        cmp bl, 09h
        jbe next
        add bl, 07h
    
    next:
        add bl, 30h
        mov [rdi], bl

        inc rdi
        dec byte[cnt]
        jnz loop3

inout 1, 1, maxnum, 3

mov rax, 60
mov rdx, 0
syscall
