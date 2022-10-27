#include <stdio.h>
#include "point.h"
#include "matrix.h"

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
void moveNorth(POINT *P, Matrix *m){
/* Menggerakkan point ke atas sebanyak 1 titik*/
    if (ORDINAT(*P) > 0) {
        if (MAT(*m,ORDINAT(*P)-1,ABSIS(*P)) == ' ') {
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P)-1,ABSIS(*P)) = 'S';
            ORDINAT(*P)--;
        } else {
            printf("Point S tidak dapat bergerak ke utara. Silakan coba lagi!");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!");
    }
}

void moveSouth(POINT *P, Matrix *m){
/* Menggerakkan point ke bawah sebanyak 1 titik*/
    if (ORDINAT(*P) < ROW(*m)-1) {
        if (MAT(*m,ORDINAT(*P)+1,ABSIS(*P)) == ' ') {
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P)+1,ABSIS(*P)) = 'S';
            ORDINAT(*P)++;
        } else {
            printf("Point S tidak dapat bergerak ke selatan. Silakan coba lagi!");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!");
    }
}

void moveEast(POINT *P){
/* Menggerakkan point ke kiri sebanyak 1 titik*/
    ABSIS(*P)++;
}

void moveWest(POINT *P){
/* Menggerakkan point ke kanan sebanyak 1 titik*/
    ABSIS(*P)--;
}