#include <stdio.h>

int main() {
    printf("add4.c\n\n");
    
    unsigned long long int a = 4294967295u;
    unsigned int b = 1;
    
    unsigned long long suma = a + b;
    
    printf("a = %u\n", a);
    printf("b = %u\n", b);
    
    printf("\nsuma = %llu\n", suma);
    
    return 0;
}
