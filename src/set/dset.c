#include <stdio.h>
#include "set.h"
/*
gcc -c set.c -o set.o
gcc dset set.o
./a
*/
int main()
{
    Set S1,S2;
    createSet(&S1);
    createSet(&S2);
    printf("=============================\n");
    printf("||   *****DRIVER SET*****   ||\n");
    printf("=============================\n");
    printf("Set S1 : ");
    displaySet(S1);
    printf("\n");
    printf("Input 1 & 2 ke dalam set\n");
    insert(&S1,1);
    insert(&S1,2);
    displaySet(S1);
    printf("\n");
    printf("Hapus elemen 1 di dalam set\n");
    printf("Apakah 1 merupakan elemen dari set?\n");
    if (isMember(S1,1))
    {
        printf("1 merupakan elemen dari set\n");
    }
    else 
    {
        printf("1 bukan elemen dari set\n");
    }
    deleteElSet(&S1,1);
    displaySet(S1);
    printf("\n");
    printf("Buat set S2: ");
    displaySet(S2);
    printf("\n");
    printf("Input 2 & 3 ke dalam set S2\n");
    insert(&S2,2);
    insert(&S2,3);
    printf("S2: ");
    displaySet(S2);
    printf("\n");
    printf("Apakah S1 merupakan subset dari S2?");
    if (isSubset(S1,S2))
    {
        printf(" Benar\n");
    }
    printf("Kosongkan set S1\n");
    LENST(S1) = 0;
    displaySet(S1);
    printf("\n");
    printf("Apakah set kosong?\n");
    if (isEmptySet(S1))
    {
        printf("Set S1 kosong\n");
    }
}