[org 0x100]
jmp start

scrollDown:
push bp
mov bp,sp
mov ax, 80
mul byte [bp+4]
push ax
shl ax,1
mov si,3998
sub si,ax
mov cx, 2000
pop ax
sub cx, ax
push ax
mov ax, 0xB800
mov es, ax
mov ds,ax
mov di,3998
std
rep movsw
mov ax, 0x720
pop cx
rep stosw
pop bp
ret 2




start:
mov ax, 5
push ax
call scrollDown
mov ax, 0x4C00
int 21h