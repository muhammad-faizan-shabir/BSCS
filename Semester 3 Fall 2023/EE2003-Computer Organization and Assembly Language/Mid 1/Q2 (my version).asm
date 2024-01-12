[org 0x0100]
jmp start
array: db 0xA7,0xA3,0x94,0xFF,0x00
size: db 5
start : mov si,0
mov bx,0
loop1: cmp bl,[size]
je end
mov al,[array+bx]
add al,0
jp evenCase
mov byte[array+bx],0x00
jmp next
evenCase:mov byte[array+bx],0x00
mov byte[array+si],al
add si,1
next:add bx,1
jmp loop1

end :mov ax,0x4c00
int 0x21 