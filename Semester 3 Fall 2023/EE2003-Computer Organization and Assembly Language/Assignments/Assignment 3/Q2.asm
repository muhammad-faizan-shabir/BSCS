[org 0x0100]

                    jmp start

offsetCalc: 	    push bp              ; subroutine to calculate required offset in the video memory
            	    mov bp,sp
            	    push ax              ; save registers
            
            	    mov ah,0             ; clear ah
            	    mov al,80            ; put 80 in al
            	    mul byte[bp+4]       ; multiply y coordinate with 80 
            	    add ax,[bp+6]        ; add x coordinate in ax
            	    shl ax,1             ; multiply ax by 2
             	    mov [bp+8],ax        ; put the calculated offset in the return value 
            
            	    pop ax               ; restore registers
            	    mov sp,bp
             	    pop bp
            	    ret 4

printAtCenter:      push bp
		    mov bp,sp
		    sub sp,8
		    push ax
		    push bx
		    push cx
		    push dx
		    push si
		    push di
		    push es

		    mov ax,0xB800
		    mov es,ax

		    mov ax,[bp+6]
		    sub ax,[bp+10]
		    add ax,1
		    shr ax,1
		    mov bx,12
		    sub bx,ax
		    mov [bp-2],bx        ; y cord

		    mov ax,[bp+4]
		    sub ax,[bp+8]
		    add ax,1
		    shr ax,1
		    sub ax,1
		    mov bx,39
		    sub bx,ax
		    mov [bp-6],bx        ; x cord

		    mov ax,[bp-2]
		    mov [bp-4],ax
		    mov cx,[bp+10]

loop1:		    cmp cx,[bp+6] 
		    ja endOfprintAtCenter
		    mov ax,[bp-6]
		    mov [bp-8],ax
		    mov si,[bp+8]

loop2:		    cmp si,[bp+4]
		    ja endOfloop1
		    sub sp,2
		    push si
		    push cx
                    call offsetCalc
		    pop di
		    mov ax,[es:di]
		    sub sp,2
		    push word[bp-8]
		    push word[bp-4]
		    call offsetCalc
		    pop di
		    mov [es:di],ax	
		    add si,1
		    add word[bp-8],1
		    jmp loop2

endOfloop1:         add cx,1
		    add word[bp-4],1
		    jmp loop1

endOfprintAtCenter: pop es
		    pop di
		    pop si
		    pop dx
		    pop cx
		    pop bx
		    pop ax
		    mov sp,bp
	            pop bp
		    ret 8

start: 		    push 0               ; top
		    push 0               ; left
                    push 6               ; bottom
		    push 13              ; right
		    call printAtCenter

		    mov ah,0
		    int 0x16
		    mov ax,0x4c00
		    int 0x21