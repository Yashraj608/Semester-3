COMMENT!
Computation with large numbers
INCLUDE Irvine32.inc
.code
main PROC
mov eax, 30000h
add eax, 60000h
sub eax, 10000h
call Writehex
call crlf

exit 
main ENDP
END main
!


COMMENT !
INCLUDE Irvine32.inc
.data
array byte 8 dup(5)
ReverseWords byte 2 dup(?)
.code 
main PROC
mov esi , offset array
mov ecx, LENGTHOF array
L1:
movzx eax, byte PTR [esi]
call WriteDec
call crlf
inc esi
loop L1
exit
main ENDP
END main
!

COMMENT !
INCLUDE Irvine32.inc
.data
nums byte 1, 2, 3, 4, 5
.code
main PROC
mov esi ,offset nums
mov ecx , LENGTHOF nums
add esi,LENGTHOF nums -1
PrintReverse:
movzx eax,byte PTR [esi]
call WriteDec
call crlf
dec esi
loop PrintReverse
exit
main ENDP
END main
!


COMMENT !
Count the Number of elements in an array
INCLUDE Irvine32.inc
.data
array byte 4,7,8,9,10,22
result DWORD ?
.code
main PROC
mov eax , 0
mov esi , offset array
mov ecx , LENGTHOF array
count :
inc esi
inc eax
loop count
mov result ,eax
call crlf
mov eax,result 
call WriteDec

exit
main ENDP
END main
!

COMMENT !
Print string character wise
INCLUDE Irvine32.inc
.data
msg byte "Hello ",0
.code
main PROC
mov esi , offset msg
mov ecx , LENGTHOF msg
PrintChar:
mov al, [esi]
cmp al,0
je done

call WriteChar
call crlf
inc esi
jmp PrintChar
done:
exit
main ENDP
END main
!


COMMENT !
Print string as character in reverse
INCLUDE Irvine32.inc
.data
msg byte "YashRaj",0
.code
main PROC
mov esi , offset msg
mov ecx,0
PrintYash:
mov al , [esi]
cmp al,0
je gotlen
inc esi
inc ecx
jmp PrintYash

gotlen:
dec esi


PrintReverse:
mov al,[esi]
call WriteChar
call crlf 
dec esi

loop PrintReverse
exit
main ENDP
END main
!


COMMENT !
Print the string in reverse order
INCLUDE Irvine32.inc
.data
array byte "World",0
result byte ?
.code
main PROC
mov esi , offset array
mov ecx, LENGTHOF array-1
add esi , ecx
dec esi

PrintReverse:
mov al , [esi]
mov result , al
call WriteChar
call crlf 
dec esi
loop PrintReverse
exit
main ENDP
END main
!


COMMENT!
Using movzx to handle different data sizes
INCLUDE Irvine32.inc
.data
num1 byte 25
num2 WORD 1200h
num3 DWORD ?
.code
main PROC
mov al, num1
movzx eax , al
call WriteDec
call crlf

mov ax , num2
movzx ebx , ax
call WriteHex
call crlf

add eax , ebx
mov num3,eax
call WriteHex
call crlf
exit 
main ENDP
END main
!

COMMENT !
movzx and movsx with signed and unsigned numbers
INCLUDE Irvine32.inc
.data
num1 sbyte -50
num2 byte 200
.code
main PROC
movzx eax , num1 
call DumpRegs

movsx  ebx , num2
call DumpRegs
exit
main ENDP
END main
!


COMMENT !
Swapping two numbers using xchg instruction
INCLUDE Irvine32.inc
.data
num1 WORD 1234h
num2 WORD 5678h
.code
main PROC
mov ax , num1
mov bx , num2
xchg ax , bx
mov num1 , ax
mov num2 , bx

movzx eax , num1
call WriteHex
call crlf
exit
main ENDP
END main
!

COMMENT !

INCLUDE Irvine32.inc
.data 
Xval DWORD 25
Yval DWORD 15
Zval DWORD 40
Rval DWORD ?
.code
main PROC
mov eax , Xval
add eax , Yval
sub eax , Zval
mov Rval , eax
neg eax
call WriteDec
main ENDP
END main
!

COMMENT !
Using EQU directive
INCLUDE Irvine32.inc
max = 100
min EQU 10
.data
num1 DWORD max
num2 DWORD min
.code
main PROC
mov eax,num1
add eax,num2
call WriteInt

exit
main ENDP
END main
!

COMMENT !
Addition and simple output 
INCLUDE Irvine32.inc
.data
.code
main PROC
mov al , 7Fh
add al ,1
call DumpRegs

mov al , 7Fh
sub al ,80h
call DumpRegs
exit
main ENDP
END main
!
COMMENT !
INCLUDE Irvine32.inc
.data
mybyte byte 12h
myword WORD 1234h
myDword DWORD 12345678h
.code
main PROC
mov esi,offset mybyte
mov esi , offset myword
mov esi , offset myDword
call DumpRegs

mov ax ,WORD PTR myDword+2
call DumpRegs

mov bx , type mybyte
call DumpRegs
mov bx ,type myWord
call DumpRegs
mov bx , type myDword
call DumpRegs
exit
main ENDP
END main

!


COMMENT !
Sizeof And Lengthof operators
INCLUDE Irvine32.inc
.data
arr1 byte 10,20,30,40
arr2 WORD 100h,200h,300h
arr3 DWORD 5 DUP(?)
.code
main PROC
mov ax , LENGTHOF arr1
mov bx , LENGTHOF arr2
mov cx , LENGTHOF arr3


movzx eax , ax
call WriteDec
call crlf

movzx eax , bx
call WriteDec
call crlf

movzx eax , cx
call WriteDec
call crlf


mov ax, SIZEOF arr1
mov bx , SIZEOF arr2
mov cx , SIZEOF arr3

movzx eax, ax
call WriteDec
call crlf
exit
main ENDP
END main
!


COMMENT !
Indexing
INCLUDE Irvine32.inc
.data
array1 byte 11h , 22h , 33h
array2 WORD 4444h , 5555h, 6666h
.code
main PROC
mov esi , offset array1
mov ecx, LENGTHOF array1
Print1:
mov al , [esi]
movzx eax , al
call WriteHex
call crlf
inc esi
loop Print1

mov esi , offset array2
mov ecx , LENGTHOF array2
PrintLoop2:
mov ax , [esi]
movzx eax , ax
call WriteHex
call crlf
add esi , TYPE array2
loop PrintLoop2
exit
main ENDP
END main
!



COMMENT !
Indirect Addressing
INCLUDE Irvine32.inc
.data
arrayB BYTE 11h,22h,33h
arrayW WORD 4444h,5555h,6666h
.code
main PROC
mov esi , offset arrayB
mov al , [esi]
movzx eax, al
call WriteHex
call crlf
mov al, [esi+1]
call WriteHex
call crlf
mov al , [esi+2]
call WriteHex
call crlf


mov esi , offset arrayW
mov ax , [esi]
call WriteHex
call crlf

mov ax , [esi+2]
call WriteHex

call crlf
mov ax , [esi+4]
call WriteHex
exit
main ENDP
END main
!

COMMENT !
Using TYPE operator
INCLUDE Irvine32.inc
.data
arrayD DWORD 1000h , 2000h , 3000h, 4000h
.code
main PROC
mov esi ,offset arrayD
mov eax , [esi + TYPE arrayD]
call WriteHex
call crlf
mov eax , [esi +TYPE arrayD*2]
call WriteHex
call crlf
mov eax , [esi + TYPE arrayD*3]
call WriteHex
exit
main ENDP
END main
!



COMMENT !
Comparison using CMP instruction
INCLUDE Irvine32.inc
.data
.code
main PROC

mov eax , 10           ;EAX = 10
mov ebx , 10            ;EBX = 10
cmp eax , ebx           EAX - EBX =0
call DumpRegs           ;Zero flag = 1


mov eax, 20              ;eax = 20
mov ebx , 10             ;ebx = 10
cmp eax , ebx            ;EAX - EBX = 10
call DumpRegs            ;Zero flag = 0
						;Sign flag = 0
						;Carry flag = 0


mov eax , 5              ;EAX = 5
mov ebx , 10             ;EBX = 10
cmp eax , ebx            ;EAX - EBX = -5
call DumpRegs            ;Sign flag = 1
                         ;Carry flag = 1
exit
main ENDP
END main
!


COMMENT !
Unconditional Jump using JMP instruction
INCLUDE Irvine32.inc
.data
msg1 byte "This is the first message",0
msg2 byte "This is the second message",0
.code
main PROC
mov edx , offset msg1
call WriteString
call crlf

jmp SkipSecond
mov edx , offset msg2
call WriteString
call crlf
SkipSecond:
exit
main ENDP
END main
!

COMMENT !
Looping using LOOP instruction
INCLUDE Irvine32.inc
.data
count DWORD 5
.code
main PROC
mov ecx , count
mov eax , 1
L1:
call WriteInt
call crlf
inc eax
loop L1
exit
main ENDP
END main
!


COMMENT !
Nested Loops
INCLUDE Irvine32.inc
.code 
main PROC
mov eax , 0
mov ecx , 5
mov ebx , 0
L1:
inc eax 
call DumpRegs
mov edx , ecx
mov ecx , 10
L2:
inc ebx 
call DumpRegs
loop L2
mov ecx , edx
loop L1
call DumpRegs
exit
main ENDP
END main
!


COMMENT !
Unconditional Jump using JMP instruction
INCLUDE Irvine32.inc
.data
msg1 byte "Welcome",0
msg2 byte "You should not see this line"
msg3 byte "Good bye",0
.code
main PROC
mov edx , offset msg1
call WriteString
call crlf

jmp skip
mov edx , offset msg2
call WriteString
call crlf
skip: 
mov edx , offset msg3
call WriteString
call crlf
exit
main ENDP
END main
!

COMMENT !
Counting from 5 to 15 using LOOP instruction
INCLUDE Irvine32.inc
.code
main PROC
mov eax , 5
mov ecx ,11
L1:
call WriteInt
call crlf
inc eax
loop L1
exit
main ENDP
END main
!


COMMENT !
Printing a pattern using nested loops
INCLUDE Irvine32.inc
.data
star byte "*",0
.code
main PROC
mov ecx , 5
mov ebx , 1
L1:
push ecx
mov ecx,ebx
l2:
mov edx , offset star
call WriteString
loop L2

call crlf
inc ebx
pop ecx 
Loop L1
exit
main ENDP
END main
!