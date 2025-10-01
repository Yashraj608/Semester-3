Comment !
INCLUDE Irvine32.inc
.data 
msg byte "Hello World",0
.code
main PROC
mov edx, OFFSET msg
call WriteString
call Crlf
exit
main ENDP
END main
!

COMMENT !
#Print the elements of an array one by one by indirect addressing
INCLUDE Irvine32.inc
.data
array1 byte 10, 20,30,40,50
.code
main PROC
mov esi,offset array1
mov al,[esi]
movzx eax,al
call WriteInt
call Crlf

mov al,[esi+1]
call WriteInt
call crlf

mov al,[esi+2]
call WriteInt
call crlf

mov al,[esi+3]
movzx eax ,al
call WriteInt
call crlf

mov al,[esi+4]
movzx eax,al
call WriteInt
call crlf
exit
main ENDP
END main
!


comment !
#Print the elements of an array one by one by direct addressing
INCLUDE Irvine32.inc
.data
array1 byte 10,20,30,40,50
.code 
main PROC
mov al,array1[0]
;movzx eax ,al
call WriteInt
call Crlf

mov al, array1[1]
movzx eax, al
call WriteInt
call crlf
exit
main ENDP
END main
!


comment !
#Print the elements of an array one by one using a loop
INCLUDE Irvine32.inc
.data 
array byte 10,20,30,40,50
.code
main PROC
mov esi , offset array
mov ecx, LENGTHOF array
Printloop:
mov al, [esi]
movzx eax , al
call WriteInt
call crlf
inc esi
loop Printloop
exit 
main ENDP
END main
!


comment !
#Print the elements of an array in reverse order using a loop
INCLUDE Irvine32.inc
.data
array1 byte 10,20,30,40,50
.code 
main PROC
mov ecx , LENGTHOF array1
mov esi , offset array1
add esi , LENGTHOF array1 - 1
printArray:
mov al, [esi]
movzx eax, al
call WriteInt
call crlf
dec esi
loop printArray
exit
main ENDP
END main
!


comment !
#Calculate the sum of the elements of an array using a loop
INCLUDE Irvine32.inc
.data
array1 byte 5,10,15,20,25,30
sum DWORD ?
.code 
main PROC
mov ecx, LENGTHOF array1
mov esi, offset array1
mov eax, 0
sumloop:
movzx ebx ,byte PTR [esi]
add eax, ebx
inc esi
loop sumloop

mov sum, eax
call WriteInt
call Crlf
exit
main ENDP
END main
!


COMMENT !
#Find the maximum value in an array using a loop
INCLUDE Irvine32.inc
.data
array1 byte 12,7,25,18,9
arrayAize = LENGTHOF array1
maxVal BYTE ?
.code
main PROC
mov ecx , arrayAize
mov esi , offset array1
mov al , byte PTR [esi]

mov maxVal,al
inc esi
dec ecx

findMax:
mov al ,[esi]
cmp al, maxVal
jbe skip
mov maxVal, al

skip:
inc esi
loop findMax

mov al , maxVal
movzx eax, al
call WriteInt
call crlf

exit 
main ENDP
END main
!

COMMENT !
#Add two numbers and display the result
INCLUDE Irvine32.inc
.data
num1 byte 10
num2 byte 20
result byte ?
.code
main PROC
mov al, num1
add al,num2
mov result, al
movzx eax , result
call WriteInt
call Crlf
exit
main ENDP
END main
!


COMMENT !
#Perform multiple arithmetic operations and display the CPU registers
INCLUDE Irvine32.inc
.data
Result DWORD ?
.code
main PROC
mov eax , 1000h
add eax , 2000h
sub eax , 500h
call DumpRegs
call Crlf
exit 
main ENDP
END main
!

COMMENT !
#Add a signed number and an unsigned number and display the result
INCLUDE Irvine32.inc
.data
snum sbyte -100
unum byte 200
result byte ?
.code
main PROC
mov al, snum
add al,unum
mov result, al
movzx eax,result 
call WriteInt
exit
main ENDP
END main
!

COMMENT !
#Display a string message
INCLUDE Irvine32.inc
.data
msg byte "Hello, Assembly Language!",0
.code
main PROC
mov edx , offset msg
call WriteString
call crlf
exit
main ENDP
END main
!


