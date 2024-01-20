[org 0x0100]
                      jmp start

clrscr:               push es
                      push ax
                      push di
                      mov ax, 0xb800
                      mov es, ax                ; point es to video base
                      mov di, 0                 ; point di to top left column
nextloc:              mov word [es:di], 0x0720  ; clear next char on screen
                      add di, 2                 ; move to next screen location
                      cmp di, 4000              ; has the whole screen cleared
                      jne nextloc               ; if no clear next position
                      pop di
                      pop ax
                      pop es
                      ret

showPowerBinary:      push bp
                      mov bp,sp
                      pusha

                      mov ax,0xb800
                      mov es,ax
                      mov cx,[bp+4]
                      mov di,160
                      mov word[es:di],0x0731
                      add di,2

loop1:                cmp cx,0
                      je endOfShowPowerBinary
                      mov word[es:di],0x0730
                      add di,2
                      sub cx,1
                      jmp loop1

endOfShowPowerBinary: popa
                      mov sp,bp
                      pop bp
                      ret 2

start:                call clrscr

                      mov ax,4                  ; print 2's power 4 in binary
                      push ax
                      call showPowerBinary

                      mov ax,0x4c00
                      int 0x21