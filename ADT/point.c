#include <stdio.h>
#include "point.h"

/* *** CREATOR *** */
void createPoint(POINT *P, int X, int Y){
/* Membuat point sembarang*/
    ABSIS(*P) = X;
    ORDINAT(*P) = Y;
}

/* *** KELOMPOK TULIS *** */
void tulisPoint(POINT P){
/* Menulis point sekarang dalam format
    (X,Y)
*/
    printf("(%d,%d)\n", ABSIS(P), ORDINAT(P));
}

/* *** OPERASI *** */
/* Operasi disini dikhususkan untuk move ke lor, kidul, wetan, kulon.*/
void moveNorth(POINT *P){
/* Menggerakkan point ke atas sebanyak 1 titik*/
    ORDINAT(*P)--;
}

void moveSouth(POINT *P){
/* Menggerakkan point ke bawah sebanyak 1 titik*/
    ORDINAT(*P)++;
}

void moveEast(POINT *P){
/* Menggerakkan point ke kiri sebanyak 1 titik*/
    ABSIS(*P)++;
}

void moveWest(POINT *P){
/* Menggerakkan point ke kanan sebanyak 1 titik*/
    ABSIS(*P)--;
}