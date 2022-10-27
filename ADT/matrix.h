#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include "wordmachine.h"
#include "point.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType;
typedef char Elmtype; // Elemen dari matriks adalah char (*, S, dsb.). Elemen dari peta

typedef struct{
    Elmtype mem[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} Matrix;

/* *** SELEKTOR *** */
#define ROW(M) (M).rowEff
#define COL(M) (M).colEff
#define MAT(M,i,j) (M).mem[(i)][(j)]

/* *** KONSTRUKTOR *** */
void createMatriks(int brs, int kol, Matrix *m);
/* Membuat Matriks m kosong dengan ukuran ROW = brs dan COL = kol*/

/* *** BACA/TULIS *** */
void readMatrix(Matrix *m, POINT *P);
/* Menuliskan isi Matriks dari input txt. Melakukan proses baca input.txt, menentukan ukuran input txt lalu membuat
matriks m*/

void displayMatrix(Matrix m);
/* Mencetak isi matriks m. */

/* *** VALIDATOR *** */
boolean isIdxValid(Matrix m, int idb, int idc);
/* Memeriksa apakah indeks baris idb dan indeks kolom idc berada dalam matriks m atau tidak */

#endif