#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include "matrix.h"

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

/* *** OPERASI *** */
/* Operasi disini dikhususkan untuk move ke lor, kidul, wetan, kulon.*/
void moveNorth(POINT *P, Matrix *m);
/* Menggerakkan point ke atas sebanyak 1 titik*/

void moveSouth(POINT *P, Matrix *m);
/* Menggerakkan point ke bawah sebanyak 1 titik*/

void moveEast(POINT *P);
/* Menggerakkan point ke kiri sebanyak 1 titik*/

void moveWest(POINT *P);
/* Menggerakkan point ke kanan sebanyak 1 titik*/

#endif