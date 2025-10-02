COMMENT !
INCLUDE Irvine32.inc
minus = 5
.data
caloriesburned WORD 250
stepsWeek1 sbyte  100
stepsWeek2 sbyte  -50

TotalSteps DWORD ?
temp DWORD ?
.code
Lab PROC
movsx eax, stepsWeek1
movsx ebx , stepsWeek2
add eax , ebx
mov TotalSteps , eax
call WriteInt


sub ebx ,minus
mov eax , ebx 
call WriteInt
call crlf

movsx eax , stepsWeek1
movsx ebx , stepsWeek2
xchg eax , ebx
mov temp , eax
mov eax , ebx
call WriteInt
call crlf

mov eax , temp
call WriteInt
call crlf
exit
Lab ENDP
END Lab
!


COMMENT !
INCLUDE Irvine32.inc
.data
username     byte 20 dup(?)
rollnumber   byte 20 dup(?)
accountMsg    byte "Your account number is : ",0
buffer    byte 20 dup(?)
titleMsg    byte  "Account info",0
.code
Lab PROC
;Username input
mov edx, OFFSET username    
mov ecx , 20
call ReadString

;Roll number input
mov edx , offset rollnumber
mov ecx , 20
call ReadString

;random account number
call Randomize 
mov eax , 10000
call RandomRange

mov edx , offset buffer
call WriteDec
call crlf



mov edx , offset accountMsg
mov ebx , offset titleMsg
mov ecx , 0
call MsgBox


exit
Lab ENDP
END Lab
!

COMMENT !
Indirect addressing
INCLUDE Irvine32.inc
.data
week1 DWORD 10,20,30,40,50
Week2 DWORD 15,25,35,45,55
Total DWORD 5 dup(?)
.code
Lab PROC
mov eax , 0
mov esi , offset week1
mov edi , offset Week2
mov ebx , offset total

add eax , [esi]
add eax , [edi]
mov [ebx] ,eax
call WriteDec
call crlf


mov eax , [esi+4]
add eax , [edi+4]
mov [ebx +4], eax 
call WriteDec
call crlf

mov eax , [esi +8]
add eax , [edi +8]
mov [ebx+8], eax 
call WriteDec
call crlf

mov eax , [esi +12]
add eax , [edi +12]
mov [ebx +12], eax
call WriteDec
call crlf

mov eax , [esi +16]
add eax , [edi+16]
mov [ebx+16] , eax
call WriteDec
call crlf
exit
Lab ENDP
END Lab
!


COMMENT !
Multiplication
INCLUDE Irvine32.inc
.data
A DWORD 2, 3, 4
B DWORD 5, 4, 6
Result DWORD 3 dup(?)
.code
Lab PROC
mov eax , [A]
imul eax , [B]
mov [Result] , eax
call WriteDec
call crlf


mov eax , [A+4]
imul eax , [B+4]
mov [Result+4], eax
call WriteDec
call crlf


mov eax , [A+8]
imul eax , [B+8]
mov [Result +8], eax
call WriteDec
call crlf

exit
Lab ENDP
END Lab
!


COMMENT !
Multiplication
INCLUDE Irvine32.inc
.data
array1 byte 3, 4, 5
array2 byte  4 , 5 , 6
array3 byte 3 dup(?)
.code
Lab PROC

mov esi , offset array1
mov edi , offset array2
mov ecx , LENGTHOF array1
Loop1:
movzx eax ,byte PTR [esi]
movzx ebx ,byte PTR [edi]
imul eax ,ebx
call WriteDec
call crlf
inc esi
inc edi
loop Loop1

exit
Lab ENDP
END Lab
!




COMMENT !
INCLUDE Irvine32.inc
.data
sizeMsg   byte "Enter the size of the array: ",0
elementMsg byte "Enter the array elements: ",0
resultMsg byte "Result: ",0

array  DWORD 20 dup(?)
size   DWORD ?
result DWORD ?

.code
Lab PROC
    ; ask for size
    mov edx , offset sizeMsg
    call WriteString
    call ReadInt
    mov size , eax

    ; ask for elements
    mov edx , offset elementMsg
    call WriteString
    call crlf              ; FIX → so prompt is visible properly

    mov ecx , size
    mov esi , offset array
inputLoop:
    call ReadInt
    mov [esi], eax
    add esi , 4
    loop inputLoop

    ; check all numbers
    mov ecx , size
    mov esi , offset array
    mov result , 1

checkLoop:
    mov eax , [esi]
    test eax , 1
    jnz oddNum             ; odd → continue
    mov result , 0         ; even → mark as 0
oddNum:
    add esi , 4
    loop checkLoop

    ; print result
    mov edx , offset resultMsg
    call WriteString
    mov eax, result
    call WriteDec
    call crlf

    exit
Lab ENDP
END Lab
!


COMMNET !
A = (A+B)-(C-D)
INCLUDE Irvine32.inc
.data
Aval  byte 5
Bval byte 6
Cval byte 7
Dval byte 8
.code
Lab PROC
mov al , Aval
add al , Bval


mov bl , Cval
sub bl , Dval

sub al , bl
mov Aval , al
call WriteInt
call crlf

exit
Lab ENDP
END Lab
!