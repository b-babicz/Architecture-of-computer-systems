         [bits 32]

%ifdef COMMENT
r0  r1
|---|
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartoœci
|   |---|
pom r0  r1

Przesuniêcie ramki w prawo:

pom = r0
r0 = r1
r1 = pom + r0
%endif

n        equ 6

         mov ebp, ebx  ; ebp = ebx
         
         mov ecx, n
         
         mov eax, 1  ; eax = 1
         mov ebx, 1  ; ebx = 1
         mov edx, 2  ; edx = 2
         
         cmp ecx, 0  ; ecx - 0  ; ZF affected
         jnz next1

         mov edx, eax  ; edx = eax

         jmp done

next1    cmp ecx, 1  ; ecx - 1  ; ZF affected
         jnz next2

         mov edx, ebx  ; edx = ebx

         jmp done

next2    cmp ecx, 2  ; ecx - 2  ; ZF affected
         jnz next3

         jmp done

next3    sub ecx, 2    ; ecx = ecx - 2

shift    mov eax, ebx  ; eax = ebx
         mov ebx, edx  ; ebx = edx
         add eax, ebx  ; eax = eax + ebx
         mov edx, eax  ; edx = eax
         
         loop shift

done     push edx
         
;        esp -> [edx][ret]

         call getaddr
format:
         db "fibo = %u", 0xA, 0
getaddr:

;        esp -> [format][eax][ebx][edx][ret]

         call [ebp+3*4]  ; printf(format, edx)
         add esp, 4*4    ; esp = esp + 16
         
;        esp -> [ret]

         push 0          ; esp -> [0][ret]
         call [ebp+0*4]  ; exit(0);

; asmloader API
;
; ESP wskazuje na prawidlowy stos
; argumenty funkcji wrzucamy na stos
; EBX zawiera pointer na tablice API
;
; call [ebx + NR_FUNKCJI*4] ; wywolanie funkcji API
;
; NR_FUNKCJI:
;
; 0 - exit
; 1 - putchar
; 2 - getchar
; 3 - printf
; 4 - scanf
;
; To co funkcja zwróci jest w EAX.
; Po wywolaniu funkcji sciagamy argumenty ze stosu.
;
; https://gynvael.coldwind.pl/?id=387

%ifdef COMMENT

ebx    -> [ ][ ][ ][ ] -> exit
ebx+4  -> [ ][ ][ ][ ] -> putchar
ebx+8  -> [ ][ ][ ][ ] -> getchar
ebx+12 -> [ ][ ][ ][ ] -> printf
ebx+16 -> [ ][ ][ ][ ] -> scanf

%endif
