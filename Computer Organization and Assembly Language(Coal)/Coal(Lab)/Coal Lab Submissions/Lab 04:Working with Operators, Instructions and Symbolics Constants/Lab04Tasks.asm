COMMENT !
Name: Yash Raj
Roll-N0: 24k-0737
Lab04 Task#1: 
INCLUDE Irvine32.inc
.data
    num1 BYTE 25
    num2 WORD 1200h
    num3 DWORD ?
.code
main PROC
    mov al, num1                 ;loads the value of num1 into al
    mov ax, num2                 ;loads the value of num2 into ax
    movzx eax, num1              ;EAX = 25
    mov num3, eax               ;Store the value of EAX into num3
    call WriteHex
    call Crlf
    movzx eax, num2            ;EAX = 1200h
    mov num3, eax              ; store the value of EAX = 1200h into num3
    call WriteHex
    call Crlf
    exit
main ENDP
END main
!



Comment !
INCLUDE Irvine32.inc
Name: Yash Raj
Roll-N0: 24k-0737
Lab04 Task#2:
.data
signedNum SBYTE -50
UnsignedNum BYTE 200
.code
main PROC
movzx eax, unsignedNum
call DumpRegs
call Crlf
movsx eax,signedNum
call DumpRegs
call Crlf
exit
main ENDP
END main
!



COMMENT !
INCLUDE Irvine32.inc
Name: Yash Raj
Roll-N0: 24k-0737
Lab04 Task#3:

.data
num1 WORD 1234h        ;Declared a vaiable num1 of type WORD and initialized it with 123h
num2 WORD 5678h        ;Declared a vaiable num2 of type WORD and initialized it with 5678h
.code
main PROC
mov ax , num1         ;loads the value of num1 into ax register
xchg ax,num2          ; exchange(swap) the values of ax(num1) and num2
mov num1,ax            ;stores the value of ax into num1

movzx eax,num1      ;
call WriteInt
call Crlf

exit
main ENDP
END main
!



COMMENT !
INCLUDE Irvine32.inc
Name: Yash Raj
Roll-N0: 24k-0737
Lab04 Task#4:

.data 
Xval DWORD 25
Yval DWORD 15
Zval DWORD 40
Rval DWORD ?
.code
main PROC
mov eax , Xval
add eax , Yval
sub eax, Zval
neg Rval
mov eax, Rval
call WriteInt
call Crlf

exit
main ENDP
END main
!


Comment !
INCLUDE Irvine32.inc
Name: Yash Raj
Roll-N0: 24k-0737
Lab04 Task#5:

Max = 100
min EQU 10
.data
var1 DWORD Max
var2 DWORD min
sum DWORD ?
.code
main PROC
mov eax,var1
add eax ,var2
mov sum, eax

call WriteInt
call Crlf
exit 
main ENDP
END main
!