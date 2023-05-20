#include <stdio.h>

int main() {

    printf("endian2.c\n\n");

    unsigned int iv = 1;
    char *cv = (char*)&iv;

    if (*cv)
        printf("Little endian\n");
    else
        printf("Big endian\n");

    return 0;
}
