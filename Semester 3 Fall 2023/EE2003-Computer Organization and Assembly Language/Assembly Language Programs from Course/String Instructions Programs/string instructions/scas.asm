; length of null-terminated string in ax

[org 0x100]
push ds
pop es
mov al,0
mov di, str1
mov cx, 0xFFFF
repne scasb
mov ax, 0xFFFF
sub ax,cx
dec ax

mov ax, 0x4C00
int 21h

str1: db 'abcdefghij',0
