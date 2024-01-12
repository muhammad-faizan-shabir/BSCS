[org 0x0100]
mov si,0
mov bx,0
loop1:cmp word[arr+bx],-1
je end
mov ax,[arr+bx]
shr ax,1
jc oddCase
mov word[arr+bx],-1
jmp next
oddCase: mov ax,[arr+bx]
mov word[arr+bx],-1
mov [arr+si],ax
add si,2
next: add bx,2
jmp loop1

end:mov ax,0x4c00
int 0x21
arr: dw 10,13,96,16,18,51,88,45,2,4,3,-1