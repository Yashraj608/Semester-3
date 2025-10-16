COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#1:
INCLUDE Irvine32.inc

.data
bon byte "Bit 0 is ON",0
boff byte "Bit 0 is OFF",0

.code
main PROC

mov al, 10
mov bl, 20
mov cl, 40

and al, 10101010b
or al, 01010101b
xor al, 11111111b

and bl, 10101010b
or bl, 01010101b
xor bl, 11111111b

and cl, 10101010b
or cl, 01010101b
xor cl, 11111111b

test al, 00000001b
jz biton

test bl, 00000001b
jz biton

test cl, 00000001b
jz biton

bitoff:
	mov edx, offset boff

biton:
	mov edx, offset bon

call writestring

exit
main ENDP
END main
!

INCLUDE Irvine32.inc

.data
lu byte "Largest (unsigned) = ",0
ls byte "Largest (signed) = ",0
promptBad BYTE "Invalid input, please enter again",0

num1 dword ?
num2 dword ?
num3 dword ?

largestUnsigned SDWORD ?
largestSigned   SDWORD ?

.code
main PROC

call readdec
mov num1, eax

call readdec
mov num2, eax

call readdec
mov num3, eax

mov eax, num1
mov ebx, num2
mov ecx, num3

cmp eax, ebx
jae not_bigger_unsigned_ebx
mov eax, ebx

not_bigger_unsigned_ebx:
    cmp eax, ecx
    jae not_bigger_unsigned_ecx
    mov eax, ecx

not_bigger_unsigned_ecx:
    mov largestUnsigned, eax

    mov eax, num1
    mov ebx, num2
    mov ecx, num3

    cmp eax, ebx
    jge not_bigger_signed_ebx
    mov eax, ebx

not_bigger_signed_ebx:
    cmp eax, ecx
    jge not_bigger_signed_ecx
    mov eax, ecx

not_bigger_signed_ecx:
    mov largestSigned, eax

    call CrLf
    mov edx, OFFSET lu
    call WriteString
    mov eax, largestUnsigned
    call WriteInt

    call CrLf
    mov edx, OFFSET ls
    call WriteString
    mov eax, largestSigned
    call WriteInt

    call CrLf


call writestring

exit
main ENDP
END main



COMMENT !
INCLUDE Irvine32.inc
Task#3:
.data
arr   DWORD 5 DUP(0)
count DWORD 0
msg   BYTE "Valid numbers entered: ", 0
msg1  BYTE "Numbers: ", 0

.code
main PROC

    mov ecx, 5
    mov esi, OFFSET arr

input:
    call ReadInt
    cmp eax, 0
    je stop
    mov [esi], eax
    add esi, 4
    inc count
    loop input

stop:
    mov edx, OFFSET msg
    call WriteString
    mov eax, count
    call WriteInt
    call Crlf

    mov edx, OFFSET msg1
    call WriteString

    mov ecx, count
    mov esi, OFFSET arr

display:
    cmp ecx, 0
    je done
    mov eax, [esi]
    call WriteInt
    mov al, ' '
    call WriteChar
    add esi, 4
    loop display

done:
    exit
main ENDP
END main
!



COMMENT !
Name: Yash Raj
Roll Number: 24k-0737
Task#4:
INCLUDE Irvine32.inc

.data
msgIn BYTE "Enter two numbers: ", 0
msgTrue BYTE "Condition True.", 0
msgFalse BYTE "Condition False.", 0

a DWORD ?
b DWORD ?

.code
main PROC

    mov edx, OFFSET msgIn
    call WriteString

    call ReadInt
    mov a, eax

    call ReadInt
    mov b, eax

    mov eax, a
    mov ebx, b
    cmp eax, ebx
    jle False1

    cmp eax, 100
    jge False1

True1:
    mov edx, OFFSET msgTrue
    call WriteString
    jmp done

False1:
    mov edx, OFFSET msgFalse
    call WriteString

done:
    exit
main ENDP
END main
!





