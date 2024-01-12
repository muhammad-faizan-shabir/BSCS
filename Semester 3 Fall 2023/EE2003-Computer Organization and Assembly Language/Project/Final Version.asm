[org 0x0100]
                     jmp start
message1:            db 'Press Any Key To Start'    ; message1 of lenghth 22
message2:            db 'Game Over'                 ; message2 of length 9
message3:            db 'Score: '                   ; message3 of lenght 7
oldkbisr:            dd 0                           
oldTimer:            dd 0
flag:                dw 0                           ; the program terminates when the flag becomes true 
rand:                dw 0                           ; variable to be used by randG
randnum:             dw 0                           ; variable to be used by randG
boxPosition:         dw 3918                        ; offset of the box
hit:                 dw 0                           ; number of hits
miss:                dw -5                          ; number of misses
size1:               dw 5                           ; size of the arrays
up:                  dw 0,0,0,0,0                   ; the current offsets of all characters
down:                dw 24,24,24,24,24              ; the counters that tell whether a character has reached the last row or not
char:                db 0,0,0,0,0                   ; the ascii values of characters currently on screen
speed:               dw 0,0,0,0,0                   ; the speeds/ticks for each character
speedCounter:        dw 0,0,0,0,0                   ; the speedCounter/tickCounter/delayCounter for each character

clrscr:              push es                        ; subroutine to clear the screen
                     push ax 
                     push di 
                     mov ax, 0xb800 
                     mov es, ax                     ; point es to video base 
                     mov di, 0                      ; point di to top left column 
nextloc:             mov word [es:di], 0x0720       ; clear next char on screen 
                     add di, 2                      ; move to next screen location 
                     cmp di, 4000                   ; has the whole screen cleared 
                     jne nextloc                    ; if no clear next position 
                     pop di 
                     pop ax 
                     pop es 
                     ret  

printstr:            push bp                        ; subroutine to print a string at desired location, takes x position, y position, string attribute, address of string and its length as parameters 
                     mov bp, sp 
                     push es 
                     push ax 
                     push cx 
                     push si 
                     push di 
                     mov ax, 0xb800 
                     mov es, ax                     ; point es to video base 
                     mov al, 80                     ; load al with columns per row 
                     mul byte [bp+10]               ; multiply with y position 
                     add ax, [bp+12]                ; add x position 
                     shl ax, 1                      ; turn into byte offset 
                     mov di,ax                      ; point di to required location 
                     mov si, [bp+6]                 ; point si to string 
                     mov cx, [bp+4]                 ; load length of string in cx 
                     mov ah, [bp+8]                 ; load attribute in ah 
nextchar:            mov al, [si]                   ; load next char of string 
                     mov [es:di], ax                ; show this char on screen 
                     add di, 2                      ; move to next screen location 
                     add si, 1                      ; move to next char in string 
                     loop nextchar                  ; repeat the operation cx times 
                     pop di 
                     pop si 
                     pop cx 
                     pop ax 
                     pop es 
                     pop bp 
                     ret 10 
				 
printnum: 	     push bp
		     mov bp, sp
		     push es
		     push ax
	 	     push bx
                     push cx
                     push dx
                     push di
                     mov ax, 0xb800
                     mov es, ax 		    ; point es to video base
                     mov ax, [bp+4] 	            ; load number in ax
                     mov bx, 10 		    ; use base 10 for division
                     mov cx, 0 			    ; initialize count of digits
nextdigit:           mov dx, 0 			    ; zero upper half of dividend
                     div bx 			    ; divide by 10
                     add dl, 0x30 		    ; convert digit into ascii value
                     push dx 			    ; save ascii value on stack
                     inc cx 			    ; increment count of values
                     cmp ax, 0 			    ; is the quotient zero
                     jnz nextdigit 		    ; if no divide it again
                     mov ax, [bp+6] 		    ; point di to 70th column
                     mov bx,80
                     mul bl
                     add ax,[bp+8]
                     shl ax,1
                     mov di,ax
nextpos:             pop dx 			    ; remove a digit from the stack
                     mov dh, 0x07 		    ; use normal attribute
                     mov [es:di], dx 		    ; print char on screen
		     add di, 2 			    ; move to next screen location
		     loop nextpos 		    ; repeat for all digits on stack
		     pop di
		     pop dx
		     pop cx
		     pop bx
		     pop ax
		     pop es
		     pop bp
		     ret 6

randG:		     push bp                        ; taking n as parameter, generate random number from 0 to n and return in the stack
		     mov bp, sp
		     pusha
		     cmp word [rand], 0
		     jne next
		     MOV     AH, 00h   		    ; interrupt to get system timer in CX:DX 
		     INT     1AH
		     inc word [rand]
		     mov     [randnum], dx
		     jmp next1
next:		     mov     ax, 25173              ; LCG Multiplier
		     mul     word  [randnum]        ; DX:AX = LCG multiplier * seed
		     add     ax, 13849              ; Add LCG increment value
		     				    ; Modulo 65536, AX = (multiplier*seed+increment) mod 65536
		     mov     [randnum], ax          ; Update seed = return value
next1:		     xor dx, dx
		     mov ax, [randnum]
		     mov cx, [bp+4]
		     inc cx
		     div cx
 		     mov [bp+6], dx
		     popa
		     pop bp
		     ret 2

randomAlphabet:	     push bp                        ; subroutine that returns a random alphabet(capital) ascii value
		     mov bp,sp
		     push ax

		     mov ax,90                      ; n=90 since ascii value for capital Z
		     sub sp,2                       ; leave space for return value
		     push ax                        ; push parameter on stack
		     call randG                     ; call randG
		     pop ax                         ; get the return value in ax

range1:		     cmp ax,25                      ; check if ascii is less than or equal to 25
		     ja range2
		     add ax,65                      ; add 65 in ascii value so that it becomes valid
		     jmp endOfrandomAlphabet

range2:		     cmp ax,51                      ; check if ascii is less than or equal to 51
		     ja range3                      
		     add ax,39                      ; add 39 in ascii value so that it becomes valid
		     jmp endOfrandomAlphabet

range3: 	     cmp ax,64                      ; check if ascii is less than or equal to 64
		     ja endOfrandomAlphabet
		     add ax,13                      ; add 13 in ascii value so that it becomes valid

endOfrandomAlphabet: mov [bp+4],ax                  ; put the ascii value on the stack
		     pop ax
		     mov sp,bp
		     pop bp
		     ret

randomSpeed: 	     push bp                        ; subroutine that return a random speed/tick between 10 and 30
		     mov bp,sp
		     push ax

		     mov ax,30                      ; n=30
		     sub sp,2                       ; leave space for return value
		     push ax                        ; push parameter on stack
		     call randG                     ; call randG
		     pop ax                         ; get the return value in ax

		     cmp ax,9                       ; check if the speed/tick is less than or equal to 9
		     ja returnSpeed
		     add ax,10                      ; add 10 in the speed/tick so that it becomes valid 

returnSpeed:         mov [bp+4],ax                  ; put the speed/tick on the stack
		     pop ax
		     mov sp,bp
		     pop bp
		     ret 

randomPosition:      push bp                        ; subroutine that returns an random offset between 0 and 158
		     mov bp,sp
		     push ax

		     mov ax,79                      ; n=79
		     sub sp,2                       ; leave space for return value        
		     push ax                        ; push parameter on stack
		     call randG                     ; call randG
		     pop ax                         ; get the return value in ax

	             shl ax,1                       ; multiply the returned value by two

		     mov [bp+4],ax                  ; put the offset on the stack
		     pop ax
		     mov sp,bp
		     pop bp
		     ret
						
spawn:               push bp                        ; subroutine that randomly spawns a character in an array in first row
		     mov bp,sp
	             pusha

		     mov si,[bp+4]                  ; get index in si for the character in the array 

		     mov ax,0xB800
	             mov es,ax

		     sub sp,2                       ; leave space for return value
		     call randomAlphabet            ; call randomAlphabet
		     pop ax                         ; get the return value in ax

       		     push si                        ; temporarily save si
		     shr si,1                       ; half si
		     mov [cs:char+si],al            ; put the random character in the char array
		     pop si                         ; restore si

		     sub sp,2                       ; leave space for return value
		     call randomSpeed               ; call randomSpeed
		     pop ax                         ; get the return value in ax

		     mov [cs:speed+si],ax           ; put random speed in the speed array

		     mov word[cs:speedCounter+si],0 ; reset the speedCounter in speedCounter array

		     sub sp,2                       ; leave space for return value
		     call randomPosition            ; call randomPosition
		     pop ax                         ; get the return value in ax

		     mov di,[cs:up+si]              ; get current offset for the character from up array
		     mov word[es:di],0x0720         ; put a space at the current offset

		     mov di,[cs:boxPosition]        ; get box offset 
		     mov word[es:di],0x07DC         ; put box at box offset (covers the case when character hits the box)

		     mov [cs:up+si],ax              ; put random offset in the up array

		     mov di,[cs:up+si]              ; get current offset from up array

		     mov word[cs:down+si],0         ; reset down in the down array

		     mov ah,0x07                    ; attribute byte

		     push si                        ; temporarily save si
		     shr si,1                       ; half si
		     mov al,[cs:char+si]            ; get character ascii from char array
		     pop si                         ; restore si    

		     mov [es:di],ax                 ; put the character on screen at the random offset

                     popa
		     pop bp
		     ret 2
						
check:		     push bp                        ; subroutine that checks the current condition of character on screen 
                     mov bp,sp
                     pusha

		     mov si,[bp+4]                  ; get index in si for the character in the array

		     cmp word[cs:down+si],24        ; check if the character has reached the last row
		     jne moveDown                   ; move character down further if not reached last row

		     mov ax,[cs:boxPosition]        ; get offset of the box
		     cmp [cs:up+si],ax              ; check if offset of the character and box are equal
		     jne missed                     ; if the above two offsets are unequal then its a miss

		     add word[cs:hit],1             ; else its a hit
		     push word[bp+4]                ; pass parameter
		     call spawn                     ; call spawn
		     jmp endOfCheck

missed:              add word[cs:miss],1            ; increment miss counter
                     push word[bp+4]                ; pass parameter
		     call spawn                     ; call spawn
		     jmp endOfCheck

moveDown:	     mov ax,[cs:speedCounter+si]    ; get speedCounter/tickCounter value of the character from speedCounter array
		     cmp ax,[cs:speed+si]           ; compare the speedCounter/tickCounter with speed/tick
		     jne counter                    ; if not equal then keep counting ticks

		     mov word[cs:speedCounter+si],0 ; else reset the speedCounter/tickCounter for the character
		     mov ax,0xB800 
	             mov es,ax
		     mov di,[cs:up+si]              ; get current offset of the character from the up array
		     mov word[es:di],0x0720         ; put a space at that offset
		     add word[cs:up+si],160         ; update the offset for the character by one row
		     mov di,[cs:up+si]              ; get the updated offset of the character 
		     mov ah,0x07                    ; attribute byte
		     push si                        ; temporarily save si
		     shr si,1                       ; half si
		     mov al,[cs:char+si]            ; get character ascii from char array
		     pop si                         ; restore si
		     mov [es:di],ax                 ; put the character on screen at the updated offset
		     add word[cs:down+si],1         ; update down for the character in the down array to indicate the number of rows the character has moved yet
		     jmp endOfCheck

counter:	     add word[cs:speedCounter+si],1 ; keep incrementing the speedCounter/tickCounter for the character

endOfCheck: 	     popa
                     pop bp
		     ret 2
						
printScore:          pusha                          ; subroutine to print score

                     mov ax,78                      ; x coordinate is 79
		     push ax                        ; pass x coordinate
		     mov ax,0                       ; y coordinate is 0
		     push ax                        ; pass y coordinate
		     mov ax,[cs:hit]                ; put the score in ax
		     push ax                        ; pass score
		     call printnum                  ; call printnum

		     popa
		     ret
						
printMisses:         pusha                          ; subroutine to print misses

                     mov ax,0                       ; x coordinate is 0
	             push ax                        ; pass x coordinate
		     mov ax,0                       ; y coordinate is 0 
		     push ax                        ; pass y coordinate
		     mov ax,[cs:miss]               ; put the misses in ax
		     cmp ax,0                       ; check if misses are nagative
		     jl zero                        ; if yes than jump to zero
		     push ax                        ; else pass misses
		     jmp callPrintNum               ; jump to callPrintNum
zero:                mov ax,0                       ; put 0 in ax
                     push ax	                    ; pass 0					
callPrintNum:        call printnum                  ; call printnum

                     popa
                     ret						
						
timer:               pusha                          ; hooked timer isr

                     mov cx,0                       ; start from first index of the arrays

loop1:		     cmp cx,[cs:size1]              ; loop runs for each index of arrays
		     je endOfTimer                  ; jump to end of routine if all indices are processed

		     cmp word[cs:miss],10           ; check if the misses ave become 10
		     je escape2                     ; if yes then jump to escape2 

		     call printScore                ; else call printScore
		     call printMisses               ; call printMisses

	             mov ax,cx                      ; put current index in ax
                     shl ax,1                       ; double ax to get index for word arrays
		     push ax                        ; pass index
		     call check                     ; call check for the current index

		     add cx,1                       ; move to next index
		     jmp loop1                      ; jump to loop1

escape2:	     mov word[cs:flag],1	    ; set the flag to terminate program								

endOfTimer:	     mov al,0x20                    ; eoi signal
		     out 0x20,al
		     popa
		     iret
						
kbisr: 	             push ax                        ; hooked keyboard isr
	             push es
		     push di

		     mov ax,0xB800
		     mov es,ax

		     in al, 0x60 		    ; read a char from keyboard port

left:	             cmp al, 0x4B 		    ; is the left key pressed 
		     jne right 			    ; no, try next comparison

		     cmp word[cs:boxPosition],3840  ; check if the current box offset at left boundary
	      	     jbe nomatch                    ; if yes then no need to update the box position

		     mov di,[cs:boxPosition]        ; else get current box offset
		     mov word[es:di],0x0720         ; put a space at that offset
		     sub word[cs:boxPosition],2     ; update the box offset
		     mov di,[cs:boxPosition]        
		     mov word[es:di],0x07DC         ; print box at new position
		     jmp nomatch                    ; jump to nomatch

right: 	             cmp al, 0x4D 		    ; is the right key pressed
		     jne escape1 		    ; no, try next comparison

		     cmp word[cs:boxPosition],3998  ; check if the current box offset at right boundary
		     jae nomatch                    ; if yes then no need to update the box position
		     mov di,[cs:boxPosition]        ; else get current box offset
		     mov word[es:di],0x0720         ; put a space at that offset
		     add word[cs:boxPosition],2     ; update the box offset
		     mov di,[cs:boxPosition] 
		     mov word[es:di],0x07DC         ; print box at new position
		     jmp nomatch                    ; jump to nomatch

escape1:             cmp al,0x1                     ; is the escape key pressed
		     jne nomatch                    ; if no then jump to nomatch

		     mov word[cs:flag],1            ; else set the flag to terminate the program

nomatch:	     mov al, 0x20                   ; eoi signal
		     out 0x20, al
		     pop di
		     pop es
		     pop ax
	             iret

start:		     call clrscr                    ; call clrscr

                     mov ax,28                      ; x coordinate is 28
		     push ax                        ; pass x coordinate
		     mov ax,12                      ; y coordinate is 12
	             push ax                        ; pass y coordinate
		     mov ax,0x0007                  ; attribute byte
		     push ax                        ; pass attribute byte
		     mov ax,message1                ; offset is message1
		     push ax                        ; pass offset
		     mov ax,22                      ; length of message is 22
		     push ax                        ; pass length
		     call printstr                  ; call printstr

		     mov ah,0                       ; get keystroke
		     int 0x16                       ; keyboard service

		     call clrscr                    ; call clrscr

		     mov ax,0xB800
		     mov es,ax 
		     mov di,[boxPosition]           ; get box offset
		     mov word[es:di],0x07DC         ; print box on screen in the last row

		     xor ax,ax                      
		     mov es,ax

		     mov ax,[es:9*4]                ; get offset for oldkbisr
		     mov [oldkbisr],ax              ; save offset for oldkbisr
		     mov ax,[es:9*4+2]              ; get segment for oldkbisr
		     mov [oldkbisr+2],ax            ; save segment for oldkbisr
		     cli                            ; clear interrupt flag
		     mov word[es:9*4],kbisr         ; hook offset
		     mov [es:9*4+2],cs              ; hook segment
		     sti                            ; set interrupt flag

		     mov ax,[es:8*4]                ; get offset for oldTimer
		     mov [oldTimer],ax              ; save offset for oldTiimer
		     mov ax,[es:8*4+2]              ; get segment for oldTimer
		     mov [oldTimer+2],ax            ; save segment for oldTimer
		     cli                            ; clear interrupt flag
		     mov word[es:8*4],timer         ; hook offset
		     mov [es:8*4+2],cs              ; hook segment
		     sti                            ; set interrupt flag
						
l1:                  cmp word[flag],0               ; check if the flag is set
                     je l1                          ; jump to l1 if flag not set

end:                 call clrscr                    ; call clrscr

                     mov ax,34                      ; x coordinate is 34
		     push ax                        ; pass x coordinate
		     mov ax,12                      ; y coordinate is 12
		     push ax                        ; pass y coordinate
		     mov ax,0x0007                  ; attribute
		     push ax                        ; pass attribute
		     mov ax,message2                ; offset for message2
		     push ax                        ; pass offset
		     mov ax,9                       ; length of message2
		     push ax                        ; pass length
		     call printstr                  ; call printstr
		 				
		     mov ax,34                      ; x coordinate is 34
		     push ax                        ; pass x coordinate
		     mov ax,14                      ; y coordinate is 14
		     push ax                        ; pass y coordinate
		     mov ax,0x0007                  ; attribute
		     push ax                        ; pass attribute
		     mov ax,message3                ; offset for message3
		     push ax                        ; pass offset
		     mov ax,7                       ; length of message3
		     push ax                        ; pass length
		     call printstr                  ; call printstr
						
		     mov ax,41                      ; x coordinate is 41
		     push ax                        ; pass x coordinate
		     mov ax,14                      ; y coordinate is 14
		     push ax                        ; pass y coordinate
		     mov ax,[cs:hit]                ; the score
		     push ax                        ; pass score
		     call printnum                  ; call printnum

                     mov ax,0                   
		     mov es,ax

		     mov ax,[oldkbisr]              ; get oldkbisr offset in ax
		     mov bx,[oldkbisr+2]            ; get oldkbisr segment in bx
		     cli                            ; clear interrupt flag
		     mov [es:9*4],ax                ; unhook offset
		     mov [es:9*4+2],bx              ; unhook segment
		     sti                            ; set interrupt flag

		     mov ax,0
		     mov es,ax

		     mov ax,[oldTimer]              ; get oldTimer offset in ax
		     mov bx,[oldTimer+2]            ; get oldTimer segment in bx
		     cli                            ; clear interrupt flag
		     mov [es:8*4],ax                ; unhook offset
		     mov [es:8*4+2],bx              ; unhook segment
		     sti                            ; set interrupt flag
						
		     mov ax,0x4c00                  ; terminate program
		     int 0x21
