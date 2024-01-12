[org 0x0100]
               jmp start

message1:      db 'Enter a four digit number'
message2:      db 'Happy'
message3:      db 'Unhappy'

clrscr:        push es                  ; subroutine to clear the screen
               push ax 
               push di 
               mov ax, 0xb800 
               mov es, ax               ; point es to video base 
               mov di, 0                ; point di to top left column 

nextloc:       mov word [es:di], 0x0720 ; clear next char on screen 
               add di, 2                ; move to next screen location 
               cmp di, 4000             ; has the whole screen cleared 
               jne nextloc              ; if no clear next position 
               pop di 
               pop ax 
               pop es 
               ret  

printstr:      push bp                  ; subroutine to print a string at desired location, takes x position, y position, string attribute, address of string and its length as parameters 
               mov bp, sp 
               push es 
               push ax 
               push cx 
               push si 
               push di 
                 
               mov ax, 0xb800 
               mov es, ax               ; point es to video base 
               mov al, 80               ; load al with columns per row 
               mul byte [bp+10]         ; multiply with y position 
               add ax, [bp+12]          ; add x position 
               shl ax, 1                ; turn into byte offset 
               mov di,ax                ; point di to required location 
               mov si, [bp+6]           ; point si to string 
               mov cx, [bp+4]           ; load length of string in cx 
               mov ah, [bp+8]           ; load attribute in ah 

nextchar:      mov al, [si]             ; load next char of string 
               mov [es:di], ax          ; show this char on screen 
               add di, 2                ; move to next screen location 
               add si, 1                ; move to next char in string 
               loop nextchar            ; repeat the operation cx times 
                
               pop di 
               pop si 
               pop cx 
               pop ax 
               pop es 
               pop bp 
               ret 10 

placeValue:    push bp
               mov bp,sp
               push ax
               push bx
               push cx
               push dx
               push si
               push di

               mov ax,0
               mov cx,[bp+4]

multiply:      cmp cx,0
               je endOfMultiply
               add ax,[bp+6]
               sub cx,1
               jmp multiply

endOfMultiply: mov [bp+8],ax

	       pop di
	       pop si
	       pop dx
	       pop cx
	       pop bx
	       pop ax
	       mov sp,bp
	       pop bp 
	       ret 4

square:        push bp
               mov bp,sp
               push ax
               push bx
               push cx
               push dx
               push si
               push di

               mov ax,[bp+4]
               mov bx,[bp+4]
               mul bx
               mov [bp+6],ax

               pop di
               pop si
               pop dx
               pop cx
               pop bx
               pop ax
               mov sp,bp
               pop bp
               ret 2

happy:         mov ax,0
               push ax
               mov ax,3
	       push ax
	       mov ax,0x07
	       push ax
	       mov ax,message2
	       push ax
	       mov ax,5
	       push ax
	       call printstr
	       jmp end

unhappy:       mov ax,0
               push ax
               mov ax,3
               push ax
               mov ax,0x07
               push ax
               mov ax,message3
               push ax
               mov ax,7
               push ax
               call printstr
               jmp end

start:         call clrscr

               mov ax,0
               push ax
               mov ax,1
               push ax
               mov ax,0x07
               push ax
               mov ax,message1
               push ax
               mov ax,25
               push ax
               call printstr

               mov ax,0xB800
               mov es,ax
               mov dx,0
               mov ax,0

               mov ah,0
               int 0x16
               mov ah,0x07
               mov [es:212],ax
               sub al,0x30
               mov ah,0
               sub sp,2
               push ax
               mov bx,1000
               push bx
               call placeValue
               pop bx
               add dx,bx

               mov ah,0
               int 0x16
               mov ah,0x07
               mov [es:214],ax
               sub al,0x30
               mov ah,0
               sub sp,2
               push ax
               mov bx,100
               push bx
               call placeValue
               pop bx
               add dx,bx

               mov ah,0
               int 0x16
               mov ah,0x07
               mov [es:216],ax
               sub al,0x30
               mov ah,0
               sub sp,2
               push ax
               mov bx,10
               push bx
               call placeValue
               pop bx
               add dx,bx

               mov ah,0
               int 0x16
               mov ah,0x07
               mov [es:218],ax
               sub al,0x30
               mov ah,0
               add dx,ax

               mov ah,0
               int 0x16

               mov ax,dx
               mov dx,0
               mov bx,10
               mov si,0
               mov cx,256

loop1:         cmp cx,0
               je unhappy
               mov di,4

loop2:         cmp di,0
               je endOfLoop2
               mov dx,0
               div bx
               sub sp,2
               push dx
               call square
               pop dx
               add si,dx
               mov dx,0
               sub di,1
               jmp loop2

endOfLoop2:    cmp si,1
               je happy
               mov dx,0
               mov ax,si
               mov si,0
               sub cx,1               
               jmp loop1

end:           mov ah,0
               int 0x16
               mov ax,0x4c00
               int 0x21