COMMENT !
Name: Yash Raj
Roll Number : 24k-0737
Task#1: Add 1 to 7Fh and display the registers
INCLUDE Irvine32.inc
.data 
.code
main PROC
mov al, 7Fh
add al,1
call DumpRegs
exit
main ENDP
END main
!

COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#2:
INCLUDE Irvine32.inc
.data
myByte BYTE 12h
myWord WORD 1234h
myDword DWORD 12345678h
.code
main PROC
mov esi, OFFSET myByte
mov esi, OFFSET myWord
mov esi, OFFSET myDword
call DumpRegs

mov ax,WORD PTR myDword
mov ax, WORD PTR [myDword +2]
call DumpRegs

mov bx, TYPE myByte
mov bx, Type myWord
mov bx, TYPE myDword
call DumpRegs

exit
main ENDP
END main
!


COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#3:
INCLUDE Irvine32.inc
.data 
arr1 BYTE 10,20,30,40
arr2 WORD 100h,200h,300h
arr3 DWORD 5 DUP(0)
.code
main PROC
mov ax, LENGTHOF arr1  ;tells lengyth of array
mov bx, LENGTHOF arr2 
mov cx, LENGTHOF arr3
call DumpRegs
exit
main ENDP
END main
!

COMMENT !
Name : Yash Raj
Roll Number: 24k-0737
Task#4:
INCLUDE Irvine32.inc
.data
arrayB BYTE 11h,22h,33h
arrayW WORD 4444h, 5555h,6666h
.code
main PROC
mov esi , OFFSET arrayB
mov al, [esi]
mov bl,[esi +1]
mov cl,[esi +2]  
call DumpRegs

mov esi, OFFSET arrayW
mov ax, [esi]
mov bx,[esi +2]
mov cx, [esi+4]
call DumpRegs
exit
main ENDP
END main
!

COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#4(loop approach)
INCLUDE Irvine32.inc
.data
arrayB BYTE 11h,22h,33h
arrayW WORD 4444h, 5555h,6666h
.code
main PROC
mov esi , OFFSET arrayB
mov ecx, LENGTHOF arrayB
loopForByte:
mov al,BYTE PTR[esi]
movzx eax ,al
call WriteHex
call Crlf
inc esi      ;This will move to next byte
loop loopForByte

mov esi, OFFSET arrayW
mov ecx, LENGTHOF arrayW
loopForWord:
mov ax, WORD PTR[esi]
movzx eax, ax
call WriteHex
call Crlf
add esi,2    ;This will move to next word
loop loopForWord
exit
main ENDP
END main
!

COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#5:
!
INCLUDE Irvine32.inc
.data
arrayD DWORD 1000h,2000h,3000h,4000h
.code
main PROC
mov eax,[OFFSET arrayD+TYPE arrayD*1]
mov ebx,[OFFSET arrayD+TYPE arrayD*3]
call DumpRegs
exit 
main ENDP
END main
!