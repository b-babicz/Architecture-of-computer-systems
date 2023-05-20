#include <stdio.h>

int main() {
    printf("imul2.c\n\n");
    
    long long int a = -2147483647;
    int b = 2;
    
    long long iloczyn = a * b;
    
    printf("a = %lld\n", a);
    printf("b = %d\n", b);
    
    printf("\niloczyn = %lld\n", iloczyn);
    
    return 0;
}
