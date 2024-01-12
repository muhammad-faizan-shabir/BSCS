; compare two equal-length strings. Put 1 in ax if same.

[org 0x100]
push ds 
pop es
mov si, str1
mov di,str2
mov cx,[size]
repe cmpsb
jcxz same
mov ax, 0
jmp end
same: mov ax,1
end:mov ax, 0x4C00
int 21h
str1:db 'abcdef'
str2:db 'abcdef'
size:dw 5