#ifndef FOOD_H
#define FOOD_H

#include "time.h"
#include "wordmachine.h"

#define NMAX 100

#define idx_undef -1

typedef struct{
    int ID;
    Word namaMakanan; // string nama makanan
    TIME expired; // waktu expired
    TIME send; // waktu pengiriman
    Word aksi; // Aksi yang dapat dilakukan
} FOOD;

/* *** SELEKTOR ADT FOOD *** */
#define ID(F) (F).ID
#define FOODNAME(F) (F).namaMakanan
#define EXP(F) (F).expired //Akses Minute => Minute(EXP(F))
#define SEND(F) (F).send
#define AKSI(F) (F).aksi

/* *** CREATOR FOOD *** */
void createFood(FOOD *food, int id, Word namaMakanan, TIME exp, TIME send, Word aksi);
/* Membuat sembarang Food */

#endif