#include <stdio.h>
#include <math.h>

/*
 0  1  2  3
[1][0][5][1] = 1*256^0 + 0*256^1 + 5*256^2 + 1*256^3

*/

int polinomial(unsigned char *p, int n) {
    unsigned int suma = 0;
    
    int i;    
    for (i = 0; i < n; i++) {
        suma = suma + *(p+i)*pow(256, i);
    }   
    
    return suma;  
}


int main() {
    printf("number.c\n\n");
    
    unsigned char x[] = {255,255,255,255}; //{1, 0, 5, 1};
    
    int n = sizeof(x);
    
    /*
    
    number(0061FE94, 4) = 16711680
    number(0061FE94, 4) = 16711680

    
    */
    
    printf("number(%p, %d) = %u\n", x, n, polinomial(x, n));
    
    return 0;
}

