[org 0x0100]
jmp start
row1: dw 0,0,0,0,0
row2: dw 0,0,0,0,0
row3: dw 0,0,0,0,0
row4: dw 0,0,0,0,0
row5: dw 0,0,0,0,0


rotateScreenRight: push bp
                   mov bp,sp
                   pusha
                   mov ax,0xb800
                   mov ds,ax
                   push cs
                   pop es
                   mov al,[bp+6]
                   mov bl,80
                   mul bl
                   add ax,[bp+4]
                   shl ax,1
                   mov si,ax
                   mov di,row1
                   mov cx,5
                   rep movsw
                   add ax,160
                   mov si,ax
                   mov di,row2
                   mov cx,5
                   rep movsw
                   add ax,160
                   mov si,ax
                   mov di,row3
                   mov cx,5
                   rep movsw
                   add ax,160
                   mov si,ax
                   mov di,row4
                   mov cx,5
                   rep movsw
                   add ax,160
                   mov si,ax
                   mov di,row5
                   mov cx,5
                   rep movsw
                   push cs
                   pop ds
                   mov cx,0xb800
                   mov es,cx
                   
                   sub ax,640

                   mov si,row1
                   mov di,ax
                   add di,8
                   mov cx,5
                   
loop1:             mov dx,[si]
                   mov [es:di],dx
                   add si,2
                   add di,160
                   loop loop1

                   mov si,row2
                   mov di,ax
                   add di,6
                   mov cx,5
                   
loop2:             mov dx,[si]
                   mov [es:di],dx
                   add si,2
                   add di,160
                   loop loop2

                   mov si,row3
                   mov di,ax
                   add di,4
                   mov cx,5
                   
loop3:             mov dx,[si]
                   mov [es:di],dx
                   add si,2
                   add di,160
                   loop loop3

                   mov si,row4
                   mov di,ax
                   add di,2
                   mov cx,5
                   
loop4:             mov dx,[si]
                   mov [es:di],dx
                   add si,2
                   add di,160
                   loop loop4



                   mov si,row5
                   mov di,ax
                   mov cx,5
                   
loop5:             mov dx,[si]
                   mov [es:di],dx
                   add si,2
                   add di,160
                   loop loop5

                   popa 
                   mov sp,bp
                   pop bp
                   ret 4
                    

                   
                   
 
start: mov ax,0x4
       push ax
       mov ax,0x39
       push ax
       call rotateScreenRight
       mov ah,0
       int 0x16     
       mov ax,0x4c00
       int 0x21              