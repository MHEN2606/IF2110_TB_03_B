#include <stdio.h>
#include "food.h"

/* *** CREATOR FOOD *** */
void createFood(FOOD *food, int id, Word namaMakanan, TIME exp, TIME send, Word aksi){
/* Membuat sembarang Food */
    ID(*food) = id;
    FOODNAME(*food) = namaMakanan;
    EXP(*food) = exp;
    SEND(*food) = send;
    AKSI(*food) = aksi;
}