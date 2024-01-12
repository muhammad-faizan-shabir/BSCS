[org 0x100]
jmp start

; 1 parameter (n) is passed to this subroutine. This subroutine will generate random number from 0 to n and returns it through stack.
RANDNUM:
   push bp
   mov bp,sp
   push ax
   push cx
   push dx
   
   MOV AH, 00h  ; interrupts to get system time        
   INT 1AH      ; CX:DX now hold number of clock ticks since midnight      
   mov  ax, dx
   xor  dx, dx
   mov  cx, [bp+4] 
   inc cx   
   div  cx       ; here dx contains the remainder of the division - from 0 to 9
   mov [bp+6], dx
   pop dx
   pop cx
   pop ax
   pop bp   
   ret 2

start:
push 79
call RANDNUM
pop dx
mov ax, 0x4C00
int 21h