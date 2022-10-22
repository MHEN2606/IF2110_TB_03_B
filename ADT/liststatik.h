#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "food.h"
#include "charmachine.h"
#include "wordmachine.h"

#define NMAX 100 // jumlah elemen maksimum list statik

typedef FOOD ElType;

typedef struct{
    ElType container[100];// array of Food
    int NEFF; // Jumlah efektif list
}ListStatik;

/* *** SELEKTOR *** */
#define ELMT(l,i) (l).container[(i)]
#define NEFF(l) (l).NEFF

/* *** CREATOR *** */
void createList(ListStatik *l);
/* Membuat list kosong dengan NEFF = 0*/

/* *** INPUT *** */
void inputListFood(ListStatik *l);
/* Membaca banyak makanan yang dimasukkan lalu membuat list makanan 
input dilakukan dari sebuah file*/

/* *** TULIS / SALIN *** */
void displayList(ListStatik l);
/* Menuliskan isi list food*/

ListStatik copyList(ListStatik *l);
/* Menyalin seluruh l ke l1*/

int panjangList(ListStatik l);
/* Mengembalikan panjang efektif dari l */

#endif