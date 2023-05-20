#include <stdio.h>

int main() {
    printf("div2.c\n\n");
    
    unsigned long long int a = 4294967295u;
    unsigned int b = 2;
    
    unsigned long long iloraz = a / b;
    
    printf("a = %u\n", a);
    printf("b = %u\n", b);
    
    printf("\niloraz = %llu\n", iloraz);
    
    return 0;
}
