#include <stdio.h>
section .data
    msg db "Hello, Holberton", 0Ah, 0

section .text
    global main

    extern printf

main:
    push msg
    push qword 0
    mov  rax, 0
    call printf
    add  rsp, 16
    xor  eax, eax
    ret

