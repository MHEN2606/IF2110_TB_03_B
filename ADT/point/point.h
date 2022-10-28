#ifndef POINT_H
#define POINT_H

#include "../boolean/boolean.h"

typedef struct{
    int X;
    int Y;
} POINT;

/* *** SELEKTOR *** */
#define ABSIS(P) (P).X
#define ORDINAT(P) (P).Y

/* *** CREATOR *** */
void createPoint(POINT *P, int X, int Y);
/* Membuat point sembarang*/

/* *** KELOMPOK TULIS *** */
void tulisPoint(POINT P);
/* Menulis point sekarang dalam format
    (X,Y)
*/
#endif