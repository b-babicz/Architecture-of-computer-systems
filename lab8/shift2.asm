[bits 32]

;        esp -> [ret]  ; ret - adres powrotu do asmloader

b        equ 1
d        equ 2

         mov ebp, ebx  ; ebp = ebx

         mov ebx, b  ; ebx = b
         mov edx, d  ; edx = d

         mov eax, ebx  ; eax = ebx
         mov ebx, edx  ; ebx = edx

         add edx, eax

         push edx
         push ebx
         push eax
;        esp -> [eax][ebx][edx][ret]

         call getaddr  ; push on the stack the run-time address of format and jump to get address
format:
         db "a = %u", 0xA
         db "b = %u", 0xA
         db "d = %u", 0xA, 0
getaddr:

;        esp -> [format][eax][ebx][edx][ret]

         call [ebp+3*4]  ; printf(format, eax, ebx, edx);
         add  esp, 4*4   ; esp = esp + 8;

;        esp -> [ret]

         push 0          ; esp -> [0][ret]
         call [ebp+0*4]  ; exit(0);

;Pytania:
; - format przechowuje adres napisu
; - etykieta format ma wartoœæ: 00000005 (adres 5, pod f11, drugi adres, pod instrukcj¹ call)
; - format ma wartoœæ na stosie: 0x00020100 (podczas runtime, uruchamiania programu pod f10)

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
