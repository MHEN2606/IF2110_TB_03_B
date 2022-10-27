#include <stdio.h>
#include "matrix.h"

/* *** KONSTRUKTOR *** */
void createMatriks(int brs, int kol, Matrix *m){
/* Membuat Matriks m kosong dengan ukuran ROW = brs dan COL = kol*/
    ROW(*m) = brs;
    COL(*m) = kol;
}

/* *** BACA/TULIS *** */
void readMatrix(Matrix *m, POINT *P){
/* Menuliskan isi Matriks dari input txt. Melakukan proses baca input.txt, menentukan ukuran input txt lalu membuat
matriks m*/
    /* DISINI ADA BACA DARI FILENYA. PARAMETER MUNGKIN DITAMBAHKAN */
    char val;
    int brs, kol;

    STARTCONFIGWORD("../konfigurasi/map.txt");
    brs = charToInt(currentWord);
    ADVWORD();
    kol = charToInt(currentWord);

    createMatriks(brs,kol,m);// Membuat matriks kosong dulu

    ADVLINE();

    for(int i = 0; i < ROW(*m); i++){
        for (int j = 0; j < COL(*m); j++){
            if(currentWord.TabWord[j] == '#'){
                MAT(*m,i,j) = ' ';
            }else{
                if(currentWord.TabWord[j] == 'S') {
                    createPoint(P,i,j);
                }
                MAT(*m,i,j) = currentWord.TabWord[j];
            }
        }
        ADVLINE();
    }

    closeFile();
}

void displayMatrix(Matrix m){
/* Mencetak isi matriks m. */
    for (int i = 0; i < COL(m)+2; i++){
        if (i != COL(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }

    for (int i = 0; i < ROW(m); i++){
        printf("* ");
        for (int j = 0; j < COL(m); j++){
            if(j != COL(m)-1){
                printf("%c ", MAT(m,i,j));
            }else{
                printf("%c", MAT(m,i,j));
            }
        }
        printf(" *\n");
    }

    for (int i = 0; i < COL(m)+2; i++){
        if (i != COL(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
}

/* *** VALIDATOR *** */
boolean isIdxValid(Matrix m, int idb, int idc){
/* Memeriksa apakah indeks baris idb dan indeks kolom idc berada dalam matriks m atau tidak*/
    return(ROW(m)>idb && COL(m)>idc && idc >= 0 && idb >= 0);
}