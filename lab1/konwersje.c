#include <stdio.h>

/*

- jak¹ maksymaln¹ liczbê binarn¹ mo¿na zapisaæ przy pomocy typu int?

UINT_MAX = 4294967295
INT_MAX  = 2147483647
UBIN_MAX = 1111111111

Odp: *

INT_MIN = -2147483648
INT_MAX = 2147483647

- jaka jest wartoœæ dziesiêtna maksymalnej liczby binarnej, jak¹ mo¿na zapisaæ przy pomocy typu int?

           9876543210
UBIN_MAX = 1111111111 = 2^10 - 1 = 1024 - 1 = 1023

*/

/*

11 / 2 = 5 r0 = 1
5 / 2 = 2  r1 = 1
2 / 2 = 1  r2 = 0
1 / 2 = 0  r3 = 1

11 = 1011 = 1*10^0 + 1*10^1 + 0*10^2 + 1*10^3

*/

int dec2bin(int x) {
    int suma = 0;
    int pow = 1;
    
    while (x > 0) {
        suma = suma + x%2 * pow;
        
        x = x/2;
        
        pow = pow*10;
    }
    
    return suma;
}

int main() {
    printf("konwersje.c\n\n");
    
    int dec1 = 1024; // dec1 = 0..1023
    
    printf("dec2bin(%d) = %d\n", dec1, dec2bin(dec1));
    
    //dec2bin(1023) = 1111111111
    
    return 0;
}
