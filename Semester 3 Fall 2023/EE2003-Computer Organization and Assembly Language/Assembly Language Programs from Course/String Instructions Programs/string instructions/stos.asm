; Clear screen 

[org 0x100]
mov ax, 0xB800
mov es, ax
mov di,0
mov ax, 0x0720
mov cx,2000
cld
rep stosw

mov ax, 0x4C00
int 21h