[ORG 0x0100]
jmp start
 
array: 	db 0xA7, 0xA3, 0x94, 0xFF, 0x00
size: db 5
 
start:
mov bx,0
mov dl, [size]
loop1:mov cl,0
mov dh,0
mov al,[array+bx]

prev:shl al,1
jnc next
add cl, 1

next:add dh,1
cmp dh,8
jne prev
shr cl,1
jnc next1

mov byte[array+bx],0
mov dh,0
mov cx,0

mov si, dx
sub si,1
mov di,bx
sub dl,1

mov al, [array+di]
mov ah, [array+si]
mov [array+si],al

next3:sub si,1
cmp si,di
jl com
mov cl,[array+si]
mov [array+si],ah
mov ah,cl
jmp next3

next1: add bx,1
com:cmp bl,dl
jne loop1

MOV  AX, 0x4C00     	; Terminate Program
INT  0x21
