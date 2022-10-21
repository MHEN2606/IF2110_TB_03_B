#include <stdio.h>
#include "food.h"
#include "time.h"

/* *** CREATOR FOOD *** */
void createFood(FOOD *food, int id, char namaMakanan, TIME exp, TIME send, char aksi){
/* Membuat sembarang Food */
    ID(*food) = id;
    FOODNAME(*food) = namaMakanan;
    EXP(*food) = exp;
    SEND(*food) = send;
    AKSI(*food) = aksi;
}

/* *** BACA *** */
void readFood(FOOD *food){
/* Membaca food dari sebuah file.txt lalu menjadikannya tipe food*/
    /* BUAT PROSEDUR BACA FILE NYA. PARAM BISA DITAMBAHKAN/DIKURANGI */
    int id;
    char *namaMakanan;
    char *aksi;
    TIME exp,send;
    
    scanf("%d", &id);
    scanf("%s", &namaMakanan);
    scanf("%s", &aksi);

    // dummy : kita buat langsung time exp dan send. seharusnya ada prosedur di sini

    createTime(&exp, 2,0,0);
    createTime(&send, 0,0,5);

    createFood(&food, id, namaMakanan, exp, send, aksi);
}