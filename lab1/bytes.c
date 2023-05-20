#include <stdio.h>

int main() {
    printf("bits.c\n\n");
    
    int x = 260;
    
    unsigned char *p = (char*)&x;
    
    printf("value = %d\n\n",x);
    
    printf("bytes = %03d %03d %03d %03d\n",*p,*(p+1),*(p+2),*(p+3));
    
    return 0;
}
