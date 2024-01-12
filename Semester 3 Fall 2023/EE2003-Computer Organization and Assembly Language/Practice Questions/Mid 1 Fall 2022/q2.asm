[org 0x100]
jmp start
sizeSet1: db 7 ; There are 7 elements in Set 1
sizeSet2: db 5 ; Set 2 contains 5 Elements
sizeSetDiff: db 7 ; Maximum 7 elements’ space
Set1: db -3, -1, 2, 5, 6, 8, 9 ; Elements of Set1
Set2: db -2, 2, 6, 7, 9; Elements of Set2
Difference: db 0, 0, 0, 0, 0, 0,0 ; Max 7 elements’ space available
start: mov si,0
mov di,0
mov bx,0
outerLoop: mov dx,si
 cmp dl,[sizeSet1]
je end
mov di,0
mov al,[Set1+si]
innerLoop: mov dx,di
cmp dl,[sizeSet2] 
je endInner
mov dl,[Set2+di]
cmp al,dl
je skip
add di,1
jmp innerLoop
endInner: mov [Difference+bx],al
add bx,1

skip: add si,1
jmp outerLoop

end: mov ax,0x4c00
int 0x21