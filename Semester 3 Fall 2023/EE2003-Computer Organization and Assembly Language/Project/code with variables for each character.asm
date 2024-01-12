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
up1: dw 0
up2: dw 0
up3: dw 0
up4: dw 0
up5: dw 0
down1: dw 24
down2: dw 24
down3: dw 24
down4: dw 24
down5: dw 24
char1: db 0
char2: db 0
char3: db 0
char4: db 0
char5: db 0
speed1: dw 0
speed2: dw 0
speed3: dw 0
speed4: dw 0
speed5: dw 0
speedCounter1: dw 0
speedCounter2: dw 0
speedCounter3: dw 0
speedCounter4: dw 0
speedCounter5: dw 0

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
						mov ax,20
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
						

spawn1: 				pusha
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						mov [cs:char1],al
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed1],ax
						mov word[cs:speedCounter1],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up1]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up1],ax
						mov di,[cs:up1]
						mov word[cs:down1],0
						mov ah,0x07
						mov al,[cs:char1]
						mov [es:di],ax
						popa
						ret
						
spawn2: 				pusha
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						mov [cs:char2],al
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed2],ax
						mov word[cs:speedCounter2],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up2]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up2],ax
						mov di,[cs:up2]
						mov word[cs:down2],0
						mov ah,0x07
						mov al,[cs:char2]
						mov [es:di],ax
						popa
						ret
						
spawn3: 				pusha
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						mov [cs:char3],al
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed3],ax
						mov word[cs:speedCounter3],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up3]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up3],ax
						mov di,[cs:up3]
						mov word[cs:down3],0
						mov ah,0x07
						mov al,[cs:char3]
						mov [es:di],ax
						popa
						ret
						
spawn4: 				pusha
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						mov [cs:char4],al
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed4],ax
						mov word[cs:speedCounter4],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up4]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up4],ax
						mov di,[cs:up4]
						mov word[cs:down4],0
						mov ah,0x07
						mov al,[cs:char4]
						mov [es:di],ax
						popa
						ret
						
spawn5: 				pusha
						mov ax,0xB800
						mov es,ax
						sub sp,2
						call randomAlphabet
						pop ax
						mov [cs:char5],al
						sub sp,2
						call randomSpeed
						pop ax
						mov [cs:speed5],ax
						mov word[cs:speedCounter5],0
						sub sp,2
						call randomPosition
						pop ax
						mov di,[cs:up5]
						mov word[es:di],0x0720
						mov di,[cs:boxPosition]
						mov word[es:di],0x07DC
						mov [cs:up5],ax
						mov di,[cs:up5]
						mov word[cs:down5],0
						mov ah,0x07
						mov al,[cs:char5]
						mov [es:di],ax
						popa
						ret
						
						





check1:					pusha
						cmp word[cs:down1],24
						jne moveDown1
						mov ax,[cs:boxPosition]
						cmp [cs:up1],ax
						jne miss1
						add word[cs:hit],1
						call spawn1
						jmp endOfCheck1
miss1:                  add word[cs:miss],1
						call spawn1
						jmp endOfCheck1
moveDown1:				mov ax,[cs:speedCounter1]
						cmp ax,[cs:speed1]
						jne counter1
						mov word[cs:speedCounter1],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up1]
						mov word[es:di],0x0720
						add word[cs:up1],160
						mov di,[cs:up1]
						mov ah,0x07
						mov al,[cs:char1]
						mov [es:di],ax
						add word[cs:down1],1
						jmp endOfCheck1
counter1:				add word[cs:speedCounter1],1
endOfCheck1: 			popa
						ret
						
check2:					pusha
						cmp word[cs:down2],24
						jne moveDown2
						mov ax,[cs:boxPosition]
						cmp [cs:up2],ax
						jne miss2
						add word[cs:hit],1
						call spawn2
						jmp endOfCheck2
miss2:                  add word[cs:miss],1
						call spawn2
						jmp endOfCheck2
moveDown2:				mov ax,[cs:speedCounter2]
						cmp ax,[cs:speed2]
						jne counter2
						mov word[cs:speedCounter2],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up2]
						mov word[es:di],0x0720
						add word[cs:up2],160
						mov di,[cs:up2]
						mov ah,0x07
						mov al,[cs:char2]
						mov [es:di],ax
						add word[cs:down2],1
						jmp endOfCheck2
counter2:				add word[cs:speedCounter2],1
endOfCheck2: 			popa
						ret
						
check3:					pusha
						cmp word[cs:down3],24
						jne moveDown3
						mov ax,[cs:boxPosition]
						cmp [cs:up3],ax
						jne miss3
						add word[cs:hit],1
						call spawn3
						jmp endOfCheck3
miss3:                  add word[cs:miss],1
						call spawn3
						jmp endOfCheck3
moveDown3:				mov ax,[cs:speedCounter3]
						cmp ax,[cs:speed3]
						jne counter3
						mov word[cs:speedCounter3],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up3]
						mov word[es:di],0x0720
						add word[cs:up3],160
						mov di,[cs:up3]
						mov ah,0x07
						mov al,[cs:char3]
						mov [es:di],ax
						add word[cs:down3],1
						jmp endOfCheck3
counter3:				add word[cs:speedCounter3],1
endOfCheck3: 			popa
						ret
						
check4:					pusha
						cmp word[cs:down4],24
						jne moveDown4
						mov ax,[cs:boxPosition]
						cmp [cs:up4],ax
						jne miss4
						add word[cs:hit],1
						call spawn4
						jmp endOfCheck4
miss4:                  add word[cs:miss],1
						call spawn4
						jmp endOfCheck4
moveDown4:				mov ax,[cs:speedCounter4]
						cmp ax,[cs:speed4]
						jne counter4
						mov word[cs:speedCounter4],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up4]
						mov word[es:di],0x0720
						add word[cs:up4],160
						mov di,[cs:up4]
						mov ah,0x07
						mov al,[cs:char4]
						mov [es:di],ax
						add word[cs:down4],1
						jmp endOfCheck4
counter4:				add word[cs:speedCounter4],1
endOfCheck4: 			popa
						ret
						
check5:					pusha
						cmp word[cs:down5],24
						jne moveDown5
						mov ax,[cs:boxPosition]
						cmp [cs:up5],ax
						jne miss5
						add word[cs:hit],1
						call spawn5
						jmp endOfCheck5
miss5:                  add word[cs:miss],1
						call spawn5
						jmp endOfCheck5
moveDown5:				mov ax,[cs:speedCounter5]
						cmp ax,[cs:speed5]
						jne counter5
						mov word[cs:speedCounter5],0
						mov ax,0xB800
						mov es,ax
						mov di,[cs:up5]
						mov word[es:di],0x0720
						add word[cs:up5],160
						mov di,[cs:up5]
						mov ah,0x07
						mov al,[cs:char5]
						mov [es:di],ax
						add word[cs:down5],1
						jmp endOfCheck5
counter5:				add word[cs:speedCounter5],1
endOfCheck5: 			popa
						ret

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
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
					
					    
						
						call check1
						
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
						
						
						call check2
						
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
						
						
						call check3
						
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
						
						
						call check4
						
						cmp word[cs:miss],10
						je escape2
						call printScore
						call printMisses
						call check5
						jmp endOfTimer
						
						
						
						
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
