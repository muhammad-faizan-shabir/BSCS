[org 0x100]
jmp start

array1: dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
n: dw 0

rotateScreenRight:
push bp
mov bp,sp
pusha
push ds

mov ax, 0xB800
mov ds, ax

mov bx,[bp+6]
mov di,array1

back: mov  ax, 80
mul bx
add ax, [bp+4]
shl ax,1
mov si, ax

mov cx, 5
rep movsw

inc bx
inc word [es:n]
cmp word [es:n],5
jne back

mov ax, es
mov ds, ax
mov ax, 0xB800
mov es, ax

mov bx,[bp+4]
add bx,4
mov si,array1

back2:mov  ax, 80
mul word [bp+6]
add ax, bx
shl ax,1
mov di, ax
mov cx,5

back1:
movsw
add di, 158
dec cx
cmp cx,0
jne back1

dec bx
dec word [n]
cmp word [n],0
jne back2

pop ds
popa
pop bp
ret 4

start:
push 2
push 3
call rotateScreenRight

mov ax, 0x4C00
int 21h

