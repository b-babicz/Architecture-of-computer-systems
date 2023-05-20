#include <stdio.h>

/*
r0  r1  r2
|---|---|       .
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartoœci
    |---|---|
    r0  r1  r2

Przesuniêcie ramki w prawo:

r0 = r1
r1 = r2
r2 = r1 + r0
*/

int fibo1(int n) {
   int r0 = 1;
   int r1 = 1;
   int r2 = 2;
   
   if (n == 0) return r0;
   if (n == 1) return r1;
   if (n == 2) return r2;
   
   int i;
   for (i = 1; i <= n-2; i++) {
        r0 = r1;
        r1 = r2;
        r2 = r1 + r0;   
   }
   
    return r2;
}

int main() {
    printf("fibo.c\n\n");
    
    int n = 4;
    
    printf("fibo1(%d) = %d\n", n, fibo1(n));
    
    return 0;
}
