#include <stdio.h>
#include "charmachine.h"

int main()
{
    printf("======================\n");
    printf("Selamat datang di driver mesin kata\n");
    printf("Masukkan kata\n");
    START();
    printf("Kata yang dimasukkan adalah : ");
    while (!EOP)
    {
        char c = currentChar;
        printf("%c",c);
        ADV();
    }
    printf("\n");
    return 0;
}