[org 0x0100]
           jmp start
tickcount: dw 0

timer:     pusha                        ; timer interrupt service routine

           mov ax,0xb800
           mov es,ax
           mov ax,0
           mov di,[cs:tickcount]
           mov word[es:di],0x0720

           cmp word[cs:tickcount],3840
           jae zero1
           add word[cs:tickcount],160
           mov di,[cs:tickcount]
           mov word[es:di],0x072A
           jmp exit1
zero1:     mov word[cs:tickcount],0
           mov di,[cs:tickcount]
           mov word[es:di],0x072A
exit1:     mov al,0x20
           out 0x20, al                  ; end of interrupt
           popa
           iret                          ; return from interrupt

start:     xor ax, ax
           mov es, ax                    ; point es to IVT base
           cli                           ; disable interrupts
           mov word [es:8*4], timer      ; store offset at n*4
           mov [es:8*4+2], cs            ; store segment at n*4+2
           sti                           ; enable interrupts
           mov dx, start                 ; end of resident portion
           add dx, 15                    ; round up to next para
           mov cl, 4
           shr dx, cl                    ; number of paras
           mov ax, 0x3100                ; terminate and stay resident
           int 0x21