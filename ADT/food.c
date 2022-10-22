#include <stdio.h>
#include "food.h"
#include "time.h"

/* *** CREATOR FOOD *** */
void createFood(FOOD *food, int id, char *namaMakanan, TIME exp, TIME send, char *aksi){
/* Membuat sembarang Food */
    ID(*food) = id;
    FOODNAME(*food) = namaMakanan;
    EXP(*food) = exp;
    SEND(*food) = send;
    AKSI(*food) = aksi;
}