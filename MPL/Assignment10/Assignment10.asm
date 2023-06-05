%macro inout 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

hextoascii:
    mov bl, [rsi]
    mov rdi, value
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
    inout 1, 1, value, 2
    ret

factorial:
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx

    mov cl, [arg_input]

pushnum:
    push rcx
    dec rcx
    jnz pushnum

    mov cl, [arg_input]
    mov bl, 01h

popnum:
    pop rax
    mul rbx
    mov bl, al
    dec rcx
    jnz popnum
    ret

section .data
num db 05h
linebr db 0Ah

section .bss
arg_count resb 1
arg_input resb 1
value resb 1
argv resb 64
fact_output resb 1

section .text

global _start
_start:
    pop rbx
    pop rbx
    pop rbx

    mov rdx, 00h
    mov dl, [rbx]
    sub dl, 30h

    mov byte[arg_input], dl
    inout 1, 1, arg_input, 1

    call factorial
    mov byte[fact_output], bl
    mov rsi, fact_output
    call hextoascii
    inout 1, 1, fact_output, 2    
    inout 1, 1, linebr, 1

    mov rax, 60
    mov rdx, 0
    syscall