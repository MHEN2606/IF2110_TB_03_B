#include <stdio.h>
#include "wordmachine.h"

int main()
{
    int baris,kolom;
    printf("===================================\n");
    STARTCONFIGWORD("../../konfigurasi/map.txt");
    baris = charToInt(currentWord);
    ADVWORD();
    kolom = charToInt(currentWord);
    printf("Print isi file map.txt dengan %d baris dan %d kolom\n",baris,kolom);
    ADVLINE();
    for(int i = 0; i < baris; i++){
        tulisKata(currentWord);
        printf("\n");
        ADVLINE();
    }
    closeFile();
    // Word k1,k2;
    Word k1 = {"Halo",4};
    Word k2 = {"Dunia",5};
    printf("kata 1 : ");
    tulisKata(k1);
    printf("\n");
    printf("kata 2 : ");
    tulisKata(k2);
    printf("\n");
    if (isSameWord(k1,k2))
    {
        printf("Kata sama\n");
    }
    else
    {
        printf("Kata beda\n");
    }
    printf("===================================\n");
    //Kurang fungsi LowerCase,konkat kata
    return 0;
}