[org 0x0100]
jmp start
message1: db 'Press Any Key To Start' ; 22
message2: db 'Game Over' ; 9
message3: db 'Score: ' ; 7
oldkbisr: dd 0
oldTimer: dd 0
boxPosition: dw 3918
miss: dw -5
hit: dw 0
rand: dw 0
randnum: dw 0
up: dw 0,0,0,0,0
down: dw 24,24,24,24,24
char: db 0,0,0,0,0
speed: dw 0,0,0,0,0
speedCounter: dw 0,0,0,0,0
size1: dw 5

clrscr:          push es                  ; subroutine to clear the screen
                 push ax 
                 push di 
                 mov ax, 0xb800 
                 mov es, ax               ; point es to video base 
                 mov di, 0                ; point di to top left column 
nextloc:         mov word [es:di], 0x0720 ; clear next char on screen 
                 add di, 2                ; move to next screen location 
                 cmp di, 4000             ; has the whole screen cleared 
                 jne nextloc              ; if no clear next position 
                 pop di 
                 pop ax 
                 pop es 
                 ret  
printstr:        push bp                  ; subroutine to print a string at desired location, takes x position, y position, string attribute, address of string and its length as parameters 
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

nextchar:        mov al, [si]             ; load next char of string 
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
				 
printnum: push bp
mov bp, sp
push es
push ax
push bx
push cx
push dx
push di
mov ax, 0xb800
mov es, ax ; point es to video base
mov ax, [bp+4] ; load number in ax
mov bx, 10 ; use base 10 for division
mov cx, 0 ; initialize count of digits
nextdigit: mov dx, 0 ; zero upper half of dividend
div bx ; divide by 10
add dl, 0x30 ; convert digit into ascii value
push dx ; save ascii value on stack
inc cx ; increment count of values
cmp ax, 0 ; is the quotient zero
jnz nextdigit ; if no divide it again
mov ax, [bp+6] ; point di to 70th column
mov bx,80
mul bl
add ax,[bp+8]
shl ax,1
mov di,ax
nextpos: pop dx ; remove a digit from the stack
mov dh, 0x07 ; use normal attribute
mov [es:di], dx ; print char on screen
add di, 2 ; move to next screen location
loop nextpos ; repeat for all digits on stack
pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 6

; taking n as parameter, generate random number from 0 to n nad return in the stack
randG:					push bp
						mov bp, sp
						pusha
						cmp word [rand], 0
						jne next

						MOV     AH, 00h   ; interrupt to get system timer in CX:DX 
						INT     1AH
						inc word [rand]
						mov     [randnum], dx
						jmp next1
next:					mov     ax, 25173          ; LCG Multiplier
						mul     word  [randnum]     ; DX:AX = LCG multiplier * seed
						add     ax, 13849          ; Add LCG increment value
						; Modulo 65536, AX = (multiplier*seed+increment) mod 65536
						mov     [randnum], ax          ; Update seed = return value

next1:					xor dx, dx
						mov ax, [randnum]
						mov cx, [bp+4]
						inc cx
						div cx
 
						mov [bp+6], dx
						popa
						pop bp
						ret 2

randomAlphabet:			push bp
						mov bp,sp
						push ax
						mov ax,90
						sub sp,2
						push ax
						call randG
						pop ax
range1:					cmp ax,25
						ja range2
						add ax,65
						jmp endOfrandomAlphabet
range2:					cmp ax,51
						ja range3
						add ax,39
						jmp endOfrandomAlphabet
range3: 				cmp ax,64
						ja endOfrandomAlphabet
						add ax,13
endOfrandomAlphabet:	mov [bp+4],ax
						pop ax
						mov sp,bp
						pop bp
						ret

randomSpeed: 			push bp
						mov bp,sp
						push ax
						mov ax,30
						sub sp,2
						push ax
						call randG
						pop ax
						cmp ax,9
						ja returnSpeed
						add ax,10
returnSpeed:            mov [bp+4],ax
						pop ax
						mov sp,bp
						pop bp
						ret 

randomPosition:         push bp
						mov bp,sp
						push ax
						mov ax,79
						sub sp,2
						push ax
						call randG
						pop ax
						shl ax,1
						mov [bp+4],ax
						pop ax
						mov sp,bp
						pop bp
						ret
						

spawn:             		push bp
						mov bp,sp
			            pusha
						mov si,[bp+4]
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						push si
						shr si,1
						mov [cs:char+si],al
						pop si
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed+si],ax
						mov word[cs:speedCounter+si],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up+si]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up+si],ax
						mov di,[cs:up+si]
						mov word[cs:down+si],0
						mov ah,0x07
						push si
						shr si,1
						mov al,[cs:char+si]
						pop si
						mov [es:di],ax
						popa
						pop bp
						ret 2
						

						
check:					push bp
                        mov bp,sp
                        pusha
						mov si,[bp+4]
						cmp word[cs:down+si],24
						jne moveDown
						mov ax,[cs:boxPosition]
						cmp [cs:up+si],ax
						jne missed
						add word[cs:hit],1
						push word[bp+4]
						call spawn
						jmp endOfCheck
missed:                 add word[cs:miss],1
                        push word[bp+4]
						call spawn
						jmp endOfCheck
moveDown:				mov ax,[cs:speedCounter+si]
						cmp ax,[cs:speed+si]
						jne counter
						mov word[cs:speedCounter+si],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up+si]
						mov word[es:di],0x0720
						add word[cs:up+si],160
						mov di,[cs:up+si]
						mov ah,0x07
						push si
						shr si,1
						mov al,[cs:char+si]
						pop si
						mov [es:di],ax
						add word[cs:down+si],1
						jmp endOfCheck
counter:				add word[cs:speedCounter+si],1
endOfCheck: 			popa
                        pop bp
						ret 2
						


printScore:             pusha
                        mov ax,78
						push ax
						mov ax,0
						push ax
						mov ax,[cs:hit]
						push ax
						call printnum
						popa
						ret
						
printMisses:            pusha
                        mov ax,0
						push ax
						mov ax,0
						push ax
						mov ax,[cs:miss]
						cmp ax,0
						jl zero
						push ax
						jmp callPrintNum
zero:                   mov ax,0
                        push ax						
callPrintNum:           call printnum
                        popa
                        ret						
						
						
timer:           		pusha
                        mov cx,0
loop1:					cmp cx,[cs:size1]
						je endOfTimer
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
					    mov ax,cx
						shl ax,1
						push ax
					    call check
						add cx,1
						jmp loop1
					
						
						
						
						
escape2:				mov al, 0x20
						out 0x20, al
						popa
						add sp,6
						jmp end										



endOfTimer:				mov al,0x20
						out 0x20,al
						popa
						iret
						

kbisr: 					push ax
						push es
						push di
						mov ax,0xB800
						mov es,ax
						in al, 0x60 ; read a char from keyboard port
left:					cmp al, 0x4B ; is the key left shift
						jne right ; no, try next comparison
						cmp word[cs:boxPosition],3840
						jbe nomatch
						mov di,[cs:boxPosition]
						mov word[es:di],0x0720
						sub word[cs:boxPosition],2
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						jmp nomatch
right: 					cmp al, 0x4D ; is the key right shift
						jne escape1 ; no, leave interrupt routine
						cmp word[cs:boxPosition],3998
						jae nomatch
						mov di,[cs:boxPosition]
						mov word[es:di],0x0720
						add word[cs:boxPosition],2
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						jmp nomatch
escape1: 				cmp al,0x1
						jne nomatch
						mov al, 0x20
						out 0x20, al
						pop di
						pop es
						pop ax
						add sp,6
						jmp end
nomatch:				mov al, 0x20
						out 0x20, al
						pop di
						pop es
						pop ax
						iret


start:					call clrscr
                        mov ax,28
						push ax
						mov ax,12
						push ax
						mov ax,0x0007
						push ax
						mov ax,message1
						push ax
						mov ax,22
						push ax
						call printstr
						mov ah,0
						int 0x16
						call clrscr
						mov ax,0xB800
						mov es,ax 
						mov di,[boxPosition]
						mov word[es:di],0x07DC
						xor ax,ax
						mov es,ax
						mov ax,[es:9*4]
						mov [oldkbisr],ax
						mov ax,[es:9*4+2]
						mov [oldkbisr+2],ax
						cli
						mov word[es:9*4],kbisr
						mov [es:9*4+2],cs
						sti
						mov ax,[es:8*4]
						mov [oldTimer],ax
						mov ax,[es:8*4+2]
						mov [oldTimer+2],ax
						cli 
						mov word[es:8*4],timer
						mov [es:8*4+2],cs
						sti
						
l1:             		jmp l1
end:                    call clrscr
                        mov ax,34
						push ax
						mov ax,12
						push ax
						mov ax,0x0007
						push ax
						mov ax,message2
						push ax
						mov ax,9
						push ax
						call printstr
						
						mov ax,34
						push ax
						mov ax,14
						push ax
						mov ax,0x0007
						push ax
						mov ax,message3
						push ax
						mov ax,7
						push ax
						call printstr
						
						mov ax,41
						push ax
						mov ax,14
						push ax
						mov ax,[cs:hit]
						push ax
						call printnum
						
          			    cli
                        mov ax,0
						mov es,ax
						mov ax,[oldkbisr]
						mov bx,[oldkbisr+2]
						
						;cli
						mov [es:9*4],ax
						mov [es:9*4+2],bx
						;sti
						mov ax,0
						mov es,ax
						mov ax,[oldTimer]
						mov bx,[oldTimer+2]
						;cli
						mov [es:8*4],ax
						mov [es:8*4+2],bx
						sti
						
						mov ax,0x4c00
						int 0x21
