[org 0x0100]
              jmp start

tempMemory:   dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
source:       dw 0
destination:  dw 0 

swap:         cmp bx,0
              je getKeyStroke

              mov cx,40
              mov si,[source]
              mov di,tempMemory
              mov ax,0xB800
              mov ds,ax
              mov ax,cs
              mov es,ax
              rep movsw
              mov ax,cs
              mov ds,ax

              mov cx,40
              mov si,[destination]
              mov di,[source]
              mov ax,0xB800
              mov es,ax
              mov ds,ax
              rep movsw
              mov ax,cs
              mov ds,ax

              mov cx,40
              mov si,tempMemory
              mov di,[destination]
              mov ax,cs
              mov ds,ax
              mov ax,0xB800
              mov es,ax
              rep movsw
              mov ax,cs
              mov ds,ax

              sub bx,1
              add word[source],160
              add word[destination],160
              jmp swap

start :       mov al,0

loop1:        cmp al,27
              je end
              cmp al,49
              je swap1and4
              cmp al,50
              je swap2and3

getKeyStroke: mov ah,0
              int 0x16
              jmp loop1

swap1and4:    mov bx,12
              mov word[source],0
              mov word[destination],2000
              jmp swap

swap2and3:    mov bx,12
              mov word[source],80
              mov word[destination],1920
              jmp swap

end:          mov ax,0x4c00
              int 0x21
