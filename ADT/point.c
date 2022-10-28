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