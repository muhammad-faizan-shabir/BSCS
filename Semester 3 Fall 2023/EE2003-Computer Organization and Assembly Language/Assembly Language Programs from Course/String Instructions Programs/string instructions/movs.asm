; copy str1 string to str2

[org 0x100]
push ds
pop es

mov si, str1
mov di, str2
mov cx, [size]
rep movsb

mov ax, 0x4C00
int 21h

str1: db 'abcde'
str2: db 0,0,0,0,0
size: dw 5