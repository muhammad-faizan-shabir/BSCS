[org 0x100]
jmp start

ballPosition: dw 3760
paddleAPos: dw 60
paddleBPos: dw 3900
ballDirection: dw 0
turn: dw 0
scoreB: dw 0
oldTimer: dd 0
oldKb: dd 0

clrscr: push es
push ax
push cx
push di
mov ax, 0xb800
mov es, ax ; point es to video base
xor di, di ; point di to top left column
mov ax, 0x0720 ; space char in normal attribute
mov cx, 2000 ; number of screen locations
cld ; auto increment mode
rep stosw ; clear the whole screen
pop di
pop cx
pop ax
pop es
ret

slideLeft:
push bp
mov bp, sp
push ax
push es
push di
mov ax, 0xB800
mov es, ax
mov ax, [bp+4]

cmp ax, 0
je next3
mov di, [cs:paddleBPos]
sub di, 2
mov [cs:paddleBPos], di
jmp next4
next3: mov di, [cs:paddleAPos]
sub di,2
mov [cs:paddleAPos], di

next4:
mov cx, 20

loopD:
mov word [es:di], 0x07DB
add di,2
loop loopD

mov word[es:di] ,0x0720

pop di
pop es
pop ax
pop bp
ret 2

slideRight:
push bp
mov bp,sp
push ax
push es
push di
mov ax, 0xB800
mov es, ax
mov ax, [bp+4]

cmp ax, 0
je next1
mov di, [cs:paddleBPos]
add di, 2
mov [cs:paddleBPos], di
jmp next2
next1: mov di, [cs:paddleAPos]
add di,2
mov [cs:paddleAPos], di

next2:
mov word [es:di-2], 0x0720
mov cx, 20

loopC:
mov word [es:di], 0x07DB
add di,2
loop loopC


pop di
pop es
pop ax
pop bp
ret 2


key:
push ax
push bx
cmp word [cs:turn], 0
jne  next50
mov bx, 0
jmp next60
next50: mov bx, 24
next60:in al, 0x60
cmp al, 0x4B
jne next
push  bx
call slideLeft
jmp end
next:cmp al, 0x4D
jne end
push bx
call slideRight

end:pop bx
pop ax
mov al, 0x20
out 0x20, al
iret


timer:
push ax
push bx
push es
push di
mov ax, 0xB800
mov es, ax
mov di, [cs:ballPosition]
mov word[es:di], 0x0720

cmp word [cs:ballDirection], 0
jne next9
sub di, 158 
jmp next10

next9: add di, 162


next10:cmp di, 0
jb next30
cmp di, 158
ja next30

mov al, [es:di]
cmp al, 0xDB
je next80
add word [cs:scoreB],1

next80:add di, 162
mov word [cs:ballDirection],1
mov word[cs:turn], 1

next30:cmp di, 3840
jb next20
cmp di, 3998
ja next20

sub di, 158
mov word [cs:ballDirection],0
mov word[cs:turn], 0


next20:mov bx, 158
add bx, 160

loopF: cmp di, bx
je next11
add bx, 160
cmp bx, 3998
jb loopF
jmp next5

next11: 
mov word[es:di], 0x0720
mov word [cs:ballPosition] , 3760
mov word [cs:ballDirection], 0
mov word [cs:turn], 0
mov di, [cs:ballPosition]

next5:mov word[es:di], 0x072A
mov [cs:ballPosition], di

pop di
pop es
pop bx
pop ax

mov al, 0x20
out 0x20, al
iret

start:

cli
call clrscr

mov ax, 0
mov es, ax

mov ax, [es:8h*4]
mov bx, [es:8h*4+2]

mov [oldTimer], ax
mov [oldTimer+2], bx

mov ax, [es:9h*4]
mov bx, [es:9h*4+2]

mov [oldKb], ax
mov [oldKb+2], bx


mov word[es:8h*4], timer
mov word [es:8h*4+2], cs

mov word[es:9h*4], key
mov word [es:9h*4+2], cs


mov ax, 0xB800
mov es, ax
mov di, 60
mov cx, 20

loopA:
mov word [es:di], 0x07DB
add di,2
loop loopA

mov di, 3900
mov cx, 20

loopB:
mov word [es:di], 0x07DB
add di,2
loop loopB

mov di, 3760
mov word [es:di] , 0x072A

sti
start1:cmp word [scoreB], 5
je end1
jmp start1
end1:
call clrscr
mov ax, 0
mov es, ax
mov ax, [oldTimer]
mov bx, [oldTimer+2]

cli
mov [es:8h*4], ax
mov [es:8h*4+2], bx

mov ax, [oldKb]
mov bx, [oldKb+2]

mov [es:9h*4], ax
mov [es:9h*4+2], bx
sti
mov ax, 0x4C00
int 21h 
