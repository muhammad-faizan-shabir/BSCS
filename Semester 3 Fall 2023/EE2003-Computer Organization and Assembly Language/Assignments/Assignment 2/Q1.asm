[org 0x0100]
                 jmp step1                ; start execution from step1
checkPalindrome: dw 0xA425                ; the number that is to be checked whether it is palindrome or not

step1:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,1000000000000001b ; retain 0th and 15th bit and make other bits 0
                 cmp ax,1000000000000001b ; compare 0th and 15th bit with 1
                 je step2                 ; jump to step2 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 0th and 15th bit with 0
                 je step2                 ; jump to step2 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step2:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0100000000000010b ; retain 1st and 14th bit and make other bits 0
                 cmp ax,0100000000000010b ; compare 1st and 14th bit with 1
                 je step3                 ; jump to step3 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 1st and 14th bit with 0
                 je step3                 ; jump to step3 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step3:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0010000000000100b ; retain 2nd and 13th bit and make other bits 0
                 cmp ax,0010000000000100b ; compare 2nd and 13th bit with 1
                 je step4                 ; jump to step4 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 2nd and 13th bit with 0
                 je step4                 ; jump to step4 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step4:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0001000000001000b ; retain 3rd and 12th bit and make other bits 0
                 cmp ax,0001000000001000b ; compare 3rd and 12th bit with 1
                 je step5                 ; jump to step5 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 3rd and 12th bit with 0
                 je step5                 ; jump to step5 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx
 
step5:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0000100000010000b ; retain 4th and 11th bit and make other bits 0
                 cmp ax,0000100000010000b ; compare 4th and 11th bit with 1
                 je step6                 ; jump to step6 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 4th and 11th bit with 0
                 je step6                 ; jump to step6 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step6:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0000010000100000b ; retain 5th and 10th bit and make other bits 0
                 cmp ax,0000010000100000b ; compare 5th and 10th bit with 1
                 je step7                 ; jump to step7 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 5th and 10th bit with 0
                 je step7                 ; jump to step7 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step7:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0000001001000000b ; retain 6th and 9th bit and make other bits 0
                 cmp ax,0000001001000000b ; compare 6th and 9th bit with 1
                 je step8                 ; jump to step8 if both bits are 1
                 cmp ax,0000000000000000b ; else compare 6th and 9th bit with 0
                 je step8                 ; jump to step8 if both bits are 0
                 jmp UnsetDx              ; else number is not a palindrome so unset dx

step8:           mov ax,[checkPalindrome] ; move the number in ax
                 and ax,0000000110000000b ; retain 7th and 8th bit and make other bits 0
                 cmp ax,0000000110000000b ; compare 7th and 8th bit with 1
                 je SetDx                 ; set dx if both bits are 1
                 cmp ax,0000000000000000b ; else compare 7th and 8th bit with 0
                 je SetDx                 ; set dx if both bits are 0

UnsetDx:         mov dx,0 
                 jmp end                  ; jump to end

SetDx:           mov dx,1

end:             mov ax,0x4c00
                 int 0x21
