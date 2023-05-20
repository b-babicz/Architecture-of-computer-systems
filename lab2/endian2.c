#include <stdio.h>

int main() {

    unsigned int x = 0x01234567;
    unsigned char *p = (unsigned char *)&x;

    if (*p == 0x67 && *(p + 1) == 0x45 && *(p + 2) == 0x23 && *(p + 3) == 0x01) {
        printf("Architektura Little-endian\n");
    } else if (*p == 0x01 && *(p + 1) == 0x23 && *(p + 2) == 0x45 && *(p + 3) == 0x67) {
        printf("Architektura Big-endian\n");
    } else {
        printf("Architektura Nieznana\n");
    }

    return 0;
}
