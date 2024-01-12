; string printing

[org 0x100]
mov ax, 0xB800
mov es, ax
mov si,str1
mov di,0
mov cx,11
mov ah, 0x07
nextchar: lodsb
stosw
loop nextchar
mov ax, 0x4C00
int 21h

str1: db 'Hello World'