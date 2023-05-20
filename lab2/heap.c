#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("heap.c\n\n");
    
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    
    printf("x = %p\n", x);
    printf("y = %p\n\n", y);
    
    *x = 1;
    *y = 2;
    
    printf("*x = %d\n", *x);
    printf("*y = %d\n", *y);
    
    /*
        
             [ ][ ][ ][ ]
             [ ][ ][ ][ ]
             [ ][ ][ ][ ]
    00B81650 [2][0][0][0]   *y
    
             [ ][ ][ ][ ]
             [ ][ ][ ][ ]
             [ ][ ][ ][ ]
    00B81640 [1][0][0][0]   *x
    
    */
    
    return 0;
}
