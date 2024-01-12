[org 0x0100]
          jmp start           ; execution begins from start
array1:   db 2,3,5,9,5,1,4,9,8; the 3 by 3 matrix

multiply: push bp             ; subroutine to multiply two 8 bit numbers
          mov bp,sp           ; save bp
          push ax             ; save ax
          push bx             ; save bx
          
          mov ah,0            ; make upperhalf of ax 0
          mov al,[bp+4]       ; move the multiplicand parameter in al
          mov bl,[bp+6]       ; move the multiplier parameter in bl
          mul bl              ; multiply al and bl
          mov [bp+8],ax       ; store the result of multiplication in return value

          pop bx              ; restore bx
          pop ax              ; restore ax
          mov sp,bp           ; restore sp
          pop bp              ; restore bp
          ret 4               ; return to caller

start:    mov cx,0            ; cx will store the determinant
          mov bh,0            ; initialize bh with zero

          sub sp,2            ; make space for return value
          mov bl,[array1+4]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+8]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop ax              ; pop the product into ax
          sub sp,2            ; make space for return value
          mov bl,[array1+5]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+7]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop dx              ; pop the product into dx
          sub ax,dx           ; calculate the first minor
          sub sp,2            ; make space for return value
          push ax             ; push first minor as multiplier
          mov bl,[array1+0]
          push bx             ; push first row's first element as multiplicand
          call multiply       ; call multiply
          pop ax              ; pop the first cofactor in ax

          add cx,ax           ; add the first cofactor into cx

          sub sp,2            ; make space for return value
          mov bl,[array1+3]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+8]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop ax              ; pop the product into ax
          sub sp,2            ; make space for return value
          mov bl,[array1+5]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+6]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop dx              ; pop the product into dx
          sub ax,dx           ; calculate the second minor
          sub sp, 2           ; make space for return value         
          push ax             ; push second minor as multiplier
          mov bl,[array1+1]
          push bx             ; push first row's second element as multiplicand
          call multiply       ; call multiply
          pop ax              ; pop the second cofactor in ax
          
          sub cx,ax           ; second cofactor has a negative sign so subtract second cofactor from cx

          sub sp,2            ; make space for return value
          mov bl,[array1+3]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+7]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop ax              ; pop the product into ax
          sub sp,2            ; make space for return value
          mov bl,[array1+4]
          push bx             ; pass the multiplier as parameter
          mov bl,[array1+6]
          push bx             ; pass the multiplicand as parameter
          call multiply       ; call multiply 
          pop dx              ; pop the product into dx
          sub ax,dx           ; calculate the third minor
          sub sp,2            ; make space for return value
          push ax             ; push third minor as multiplier
          mov bl,[array1+2]
          push bx             ; push first row's third element as multiplicand
          call multiply       ; call multiply 
          pop ax              ; pop the third cofactor in ax

          add cx,ax           ; add the third cofactor into cx, cx now contains the determinant

          mov ax,0x4c00
          int 0x21