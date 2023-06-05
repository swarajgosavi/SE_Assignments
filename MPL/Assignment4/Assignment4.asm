%macro inout 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

hextoascii:
    mov rcx, 02h
add:
    rol bl, 04
    mov dl, bl
    and dl, 0Fh
    cmp dl, 09h
    jbe update
    add dl, 07h
update:
    add dl, 30h
    mov [rdi], dl
    inc rdi
    dec rcx
    jnz add
    ret

asciitohex:
    mov bl, 00h
    mov rcx, 02h
next:
    rol bl, 04
    mov dl, [rsi]
    cmp dl, 39h
    jbe update1
    sub dl, 07h
update1:
    sub dl, 30h
    add bl, dl
    inc rsi
    dec rcx
    jnz next
    ret

section .data:
    msg1 db 10,13,"Enter 1st Number : "
    len1 equ $-msg1

    msg2 db 10,13,"Enter 2nd Number : "
    len2 equ $-msg2

    msg3 db 10,13,"Result is : "
    len3 equ $-msg3

    msg4 db 10,13,"Options are"
        db 10,"1. Add"
        db 10,"2. Subtract"
        db 10,"3. Multiply"
        db 10,"4. Divide"
        db 10,"5. Exit",10
    len4 equ $-msg4

section .bss
    num1ascii resb 02
    num2ascii resb 02
    num1hex resb 01
    num2hex resb 01
    optionascii resb 01
    optionhex resb 01
    resascii resb 02
    reshex resb 01

section .text
global _start
_start:
    inout 1, 1, msg1, len1
    inout 0, 0, num1ascii, 03

    inout 1, 1, msg2, len2
    inout 0, 0, num2ascii, 03

    mov bl, 00h
    mov rsi, num1ascii
    call asciitohex
    mov [num1hex], bl

    mov bl, 00h
    mov rsi, num2ascii
    call asciitohex
    mov [num2hex], bl

programLoop:
    inout 1, 1, msg4, len4
    inout 0, 0, optionascii, 02
    mov bl, byte[optionascii]
    sub bl, 30h
    cmp bl, 01h
    jz addition
    cmp bl, 02h
    jz subtract
    cmp bl, 03h
    jz multiply
    cmp bl, 04h
    jz divide
    cmp bl, 05h
    jz exit

addition:
    mov al, byte[num1hex]
    mov bl, byte[num2hex]
    add al, bl
    mov [reshex], al
    jmp printRes

subtract:
    mov al, byte[num1hex]
    mov bl, byte[num2hex]
    sub al, bl
    mov [reshex], al
    jmp printRes

multiply:
    mov al, byte[num1hex]
    mov bl, byte[num2hex]
    mul bl
    mov [reshex], al
    jmp printRes

divide:
    mov al, byte[num1hex]
    mov bl, byte[num2hex]
    div bl
    mov [reshex], al
    jmp printRes

printRes:
    inout 1, 1, msg3, len3
    mov bl, [reshex]
    mov rdi, resascii
    call hextoascii
    inout 1, 1, resascii, 02
    jmp programLoop

exit:
    mov rax, 60
    mov rdx, 0
    syscall