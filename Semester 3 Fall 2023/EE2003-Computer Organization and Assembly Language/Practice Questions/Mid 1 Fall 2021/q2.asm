[org 0x0100]
jmp start
arr: dw 3,5,10,9,12,16,23,-1

start: mov bx,0
mov ax,0
mov cx,0
mov dx,0

loop1: mov ax,[arr+bx]
mov dx,[arr+bx+2]
cmp ax,-1
je end
cmp dx,-1
je end
shr dx,1
jc oddCase
mov dx,[arr+bx+2]
mov word[arr+bx],0
mov cx,8
checkbit: shr dx,1
jnc skip
add [arr+bx],ax
skip: shl ax,1
dec cx
jnz checkbit
jmp next
oddCase: mov dx,[arr+bx+2]
 add ax,dx
mov [arr+bx],ax
next: add bx,4
jmp loop1

end : mov ax,0x4c00
int 0x21
