section .data
    hello: db 'Hello, Holberton', 0Ah
section .text
    global _start
_start:
    ; set up stack and other necessary things
    ; call printf with the address of hello string
    ; clean up and exit
