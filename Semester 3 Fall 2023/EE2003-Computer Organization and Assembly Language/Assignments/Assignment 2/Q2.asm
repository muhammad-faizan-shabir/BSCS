[org 0x0100]
              jmp start             ; execution starts from start label
array1:       dw 10,17,6,5,11,8     ; the array of words to be sorted
size:         dw 6                  ; size of the array
swap:         db 0                  ; a flag that tells whether a pass through the array caused any swaps or not
evenFirst:    db 1                  ; this is a flag. If it is true then first number should be even and second should be odd and if it is flase then first number should be odd and second should be even

start:        mov cx,[size]         ; move size of array in cx
              sub cx,1              ; decrement cx so that it points to last index of array
              shl cx,1              ; multiply cx by two since array is of words
bubbleSort:   mov bx,0              ; initial offset is zero
              mov byte[swap],0      ; unset the swap flag
              
loop1:        mov ax,[array1+bx]    ; fetch an element from array
              cmp ax,[array1 +bx+2] ; compare fetched element with succeeding element
              jle noswap            ; jump to noswap if first element is less than or equal to the second element
              mov dx,[array1+bx+2]  ; get succeeding element in dx
              mov [array1+bx+2],ax  ; swap elements
              mov [array1+bx],dx 
              mov byte[swap],1      ; set the swap flag

noswap:       add bx,2              ; increment bx by 2 since array of words
              cmp bx,cx             ; compare bx with last index position offset
              jne loop1             ; if bx is not equal to last index position offset then jump to loop1

              cmp byte[swap],1      ; compare the swap flag with 1
              je bubbleSort         ; if flag is 1 then jump to bubbleSort for another pass

              mov bx,0              ; reset bx
loop2:        cmp bx,cx             ; compare bx with last index position offset
              je end                ; if bx is equal to last index position offset then jump to end
              cmp byte[evenFirst],1 ; compare evenFirst flag with 1
              jne OddFirstCase      ; if flag is zero then then jump to OddFirstCase
              
              mov byte[evenFirst],0 ; unset evenFirst flag so that next time jump is taken to OddFirstCase
              mov ax,[array1+bx]    ; move first element to ax
              shr ax,1              ; shift ax right by 1 bit
              jnc skip              ; jump to skip if the first element is even
              mov ax,[array1+bx+2]  ; move second element to ax
              shr ax,1              ; shift ax right by 1 bit
              jc skip               ; jump to skip if the second element is odd
              mov ax,[array1+bx+2]  ; get second element in ax
              mov dx,[array1+bx]    ; get first element in dx
              mov [array1+bx+2],dx  ; swap elements to get even number followed by odd
              mov [array1+bx],ax 
              jmp skip              ; jump to skip

OddFirstCase: mov byte[evenFirst],1 ; set evenFirst flag so that next time jump is NOT taken to OddFirstCase
              mov ax,[array1+bx]    ; move first element to ax
              shr ax,1              ; shift ax right by 1 bit
              jc skip               ; jump to skip if the first element is odd
              mov ax,[array1+bx+2]  ; move second element to ax
              shr ax,1              ; shift ax right by 1 bit
              jnc skip              ; jump to skip if the second element is even
              mov ax,[array1+bx+2]  ; get second element in ax
              mov dx,[array1+bx]    ; get first element in dx
              mov [array1+bx+2],dx  ; swap elements to get odd number followed by even
              mov [array1+bx],ax 
 
skip:         add bx,2              ; point to the next element in the array
              jmp loop2             ; jump to loop2

end:          mov ax,0x4c00
              int 0x21
