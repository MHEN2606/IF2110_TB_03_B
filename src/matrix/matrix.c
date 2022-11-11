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

    STARTCONFIGWORD("../config/map.txt");
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
                    createPoint(P,j,i);
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

/* *** OPERASI *** */
/* Operasi disini dikhususkan untuk move ke lor, kidul, wetan, kulon.*/
void moveNorth(POINT *P, Matrix *m){
/* Menggerakkan point ke atas sebanyak 1 titik*/
    if (ORDINAT(*P) > 0) {
        if (MAT(*m,ORDINAT(*P)-1,ABSIS(*P)) == ' ') {
            printf("Point S berhasil bergerak ke utara!\n");
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P)-1,ABSIS(*P)) = 'S';
            ORDINAT(*P)--;
        } else {
            printf("Point S tidak dapat bergerak ke utara. Silakan coba lagi!\n");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!\n");
    }
}

void moveSouth(POINT *P, Matrix *m){
/* Menggerakkan point ke bawah sebanyak 1 titik*/
    if (ORDINAT(*P) < ROW(*m)-1) {
        if (MAT(*m,ORDINAT(*P)+1,ABSIS(*P)) == ' ') {
            printf("Point S berhasil bergerak ke selatan!\n");
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P)+1,ABSIS(*P)) = 'S';
            ORDINAT(*P)++;
        } else {
            printf("Point S tidak dapat bergerak ke selatan. Silakan coba lagi!\n");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!\n");
    }
}

void moveEast(POINT *P, Matrix *m){
/* Menggerakkan point ke kiri sebanyak 1 titik*/
    if (ABSIS(*P) < COL(*m)-1) {
        if (MAT(*m,ORDINAT(*P),ABSIS(*P)+1) == ' ') {
            printf("Point S berhasil bergerak ke timur!\n");
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P),ABSIS(*P)+1) = 'S';
            ABSIS(*P)++;
        } else {
            printf("Point S tidak dapat bergerak ke timur. Silakan coba lagi!\n");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!\n");
    }
}

void moveWest(POINT *P, Matrix *m){
/* Menggerakkan point ke kanan sebanyak 1 titik*/
    if (ABSIS(*P) > 0) {
        if (MAT(*m,ORDINAT(*P),ABSIS(*P)-1) == ' ') {
            printf("Point S berhasil bergerak ke barat!\n");
            MAT(*m,ORDINAT(*P),ABSIS(*P)) = ' ';
            MAT(*m,ORDINAT(*P),ABSIS(*P)-1) = 'S';
            ABSIS(*P)--;
        } else {
            printf("Point S tidak dapat bergerak ke barat. Silakan coba lagi!\n");
        }
    } else {
        printf("Point S telah sampai di tepi. Silakan coba lagi!\n");
    }
}

boolean isAdjacent(POINT P, Matrix m, char sym){
/* Mengecek apakah sym ada di sekitar POINT P  */
    if (MAT(m, ORDINAT(P) + 1, ABSIS(P)) == sym){
        return true;
    }
    else if (MAT(m, ORDINAT(P), ABSIS(P) - 1) == sym){
        return true;
    }
    else if (MAT(m, ORDINAT(P), ABSIS(P) + 1) == sym){
        return true;
    }
    else if (MAT(m, ORDINAT(P) - 1, ABSIS(P)) == sym){
        return true;
    }
    else{
        return false;
    }
}