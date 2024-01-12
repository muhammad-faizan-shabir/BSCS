[org 0x0100]

jmp start

offsetCalc: push bp        ; subroutine to calculate required offset in the video memory
            mov bp,sp
            push ax        ; save registers
            
            mov ah,0       ; clear ah
            mov al,80      ; put 80 in al
            mul byte[bp+4] ; multiply y coordinate with 80 
            add ax,[bp+6]  ; add x coordinate in ax
            shl ax,1       ; multiply ax by 2
            mov [bp+8],ax  ; put the calculated offset in the return value 
            
            pop ax         ; restore registers
            mov sp,bp
            pop bp
            ret 4

flip:       push bp
            mov bp,sp
            sub sp,4
            push ax
            push bx
            push cx
            push dx
            push si
            push di
            push es

            mov ax,0xB800
            mov es,ax
            mov word[bp-2],12
            mov word[bp-4],80
            mov cx,0

Loop1:      cmp cx,[bp-2]
            je endOfFlip
            mov si,0

Loop2:      cmp si,[bp-4]
            je endOfloop2
            sub sp,2
            push si
            push cx
            call offsetCalc
            pop di
            mov ax,[es:di]
            sub sp,2
            mov dx,79
            sub dx,si
            push dx
            mov dx,24
            sub dx,cx
            push dx
            call offsetCalc
            pop di
            mov [es:di],ax
            add si,1
            jmp Loop2

endOfloop2: add cx,1
            jmp Loop1

endOfFlip:  pop es
            pop di
            pop si
            pop dx
            pop cx
            pop bx
            pop ax
            mov sp,bp
            pop bp
            ret 

start:      mov ax,0
            call flip

            mov ah,0
            int 0x16
            mov ax,0x4c00
            int 0x21
