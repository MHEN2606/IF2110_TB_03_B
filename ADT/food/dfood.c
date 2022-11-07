#include <stdio.h>
#include "food.h"
// COMMAND RUN
// gcc -c food.c -o food.o
// gcc -c "../wordmachine/wordmachine.c" -o wordmachine.o
// gcc -c "../time/time.c" -o time.o
// gcc -c "../charmachine/charmachine.c" -o charmachine.o
// gcc dfood.c food.o wordmachine.o time.o charmachine.o
// ./a
int main()
{
    //Membuat makanan "F"
    FOOD F;
    //Definisikan id, nama, waktu exp & delivery, aksi
    int id = 10;
    Word ayam = {"ayam",4};
    TIME tExp;
    createTime(&tExp,1,12,12);
    TIME tDev;
    createTime(&tDev,0,0,30);
    Word FRY = {"FRY",3};
    createFood(&F,id,ayam,tExp,tDev,FRY);
    printf("==========================\n");
    printf("MAKANAN YANG DIBUAT\n");
    printf("id = %d\n",id);
    printf("Nama makanan : ");
    tulisKata(ayam);
    printf("\n");
    printf("Waktu EXP : ");
    displayTime(tExp);
    printf("Waktu delivery : ");
    displayTime(tDev);
    printf("Aksi yang dapat dilakukan : ");
    tulisKata(FRY);
    printf("\n==========================");
    return 0;
}