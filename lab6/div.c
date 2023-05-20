#include <stdio.h>

int main() {
    printf("div.c\n\n");
    
    unsigned int a = 4294967295u;
    unsigned int b = 2;
    
    unsigned iloraz = a/b;
    
    printf("a = %u\n", a);
    printf("b = %u\n", b);
    
    printf("\niloraz = %u\n", iloraz);
    
    return 0;
}
