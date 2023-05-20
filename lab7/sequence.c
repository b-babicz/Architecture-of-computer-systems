#include <stdio.h>

/*
r0  r1  r2
|---|---|        .
0   1   2   3    4   5   6    indeksy
3   4   8   12   22  35  62   wartości
    |---|---|
    r0  r1  r2

Przesunięcie ramki w prawo:

r0 = r1
r1 = r2
r2 = 0.5*r2 + 2*r1
*/

/*

- ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu w funkcji seq dla n >= 3 ?

Należy dokonać przesunięcia o n-2 razy


- dokonaj analizy wywołania seq1(4)

* seq1(4) = 22
  r0 = 3
  r1 = 4
  r2 = 8
  
  4 == 0  false
  4 == 1  false
  4 == 2  false
  
  i
  i = 1
  1 <= 2   r0 = 4
           r1 = 8
           r2 = 0.5*8 + 2*4 = 12    i = 2
  2 <= 2   r0 = 8
           r1 = 12
           r2 = 0.5*12 + 2*8 = 22   i = 3
  3 <= 2   false
  
  return r2 = 22

- narysuj graf obliczen dla seq1(4)

seq(0)  seq(1)    seq(2)
           \     / |
           seq(3)  |
             \     |
              seq(4)

*/


int seq1(int n) {
   int r0 = 3;
   int r1 = 4;
   int r2 = 8;
   
   if (n == 0) return r0;
   if (n == 1) return r1;
   if (n == 2) return r2;
   
   int i;
   for (i = 1; i <= n-2; i++) {
        r0 = r1;
        r1 = r2;
        r2 = (r1/2) + 2*r0;   
   }
   
    return r2;
}

/*

r0  r1
|---|            n
0   1   2   3    4    5   6   indeksy
3   4   8   12   22  35  62   wartości
|   |---|
pom r0  r1

Przesunięcie ramki w prawo:

pom = r0
r0 = r1
r1 = 2*pom + 0.5*r0
*/

int seq2(int n) {
    int r0 = 3;
    int r1 = 4;
    
    if (n == 0) return r0;
    if (n == 1) return r1;
    
    int i;
    for (i =1; i <= n-1; i++) {
        int pom = r0;
        r0 = r1;
        r1 = 2*pom + (r0/2);
    }
    
    return r1;
}

/*
- ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu w funkcji seq dla n >= 3 ?

Należy dokonać przesunięcia o n-1 razy


- dokonaj analizy wywołania seq1(4)

* seq2(4) = 22

  r0 = 3
  r1 = 4
  
  4 == 0  false
  4 == 1  false
  
  i
  i = 1
  1 <= 3   pom = 3
           r0 = 4
           r1 = 2*3 + 0.5*4 = 8    i = 2
  2 <= 3   pom = 4
           r0 = 8
           r1 = 2*4 + 0.5*8 = 12   i = 3
  3 <= 3   pom = 8
           r0 = 12
           r1 = 2*8 + 0.5*12 = 22  i = 4
  4 <= 4   false
  
  return r1 = 22   
*/

/*

- narysuj graf obliczen dla seq2(4)

seq2(0)     seq2(1)
        \    /  |
        seq2(2) |
          |  \  |
          |   seq2(3)
          |  /
          seq2(4)
*/




int main() {
    printf("sequence.c\n\n");
    
    int n = 4;
    
    printf("seq1(%d) = %d\n", n, seq1(n));
    printf("seq2(%d) = %d\n", n, seq2(n));
    
    return 0;
}

