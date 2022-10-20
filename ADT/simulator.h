#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "point.h"
#include "liststatik.h"

typedef struct{
    char *name;
    POINT position;
    ListStatik inventory; //list inventory
} SIMULATOR;

/* *** SELEKTOR *** */
#define USERNAME(S) (S).name
#define POSISI(S) (S).position // akses absis dan ordinat => ABSIS(POSISI(S)) and ORDINAT(POSISI(S))
#define INV(S) (S).inventory
#define EINV(S,i) (S).inventory.container[(i)]
#define LINV(S) (S).inventory.NEFF


/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, char name, ListStatik inv);
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/
#endif