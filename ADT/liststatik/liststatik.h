#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "../food/food.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../prioqueuetime/prioqueuetime.h"
#include "../tree/tree.h"

#define NMAX 100 // jumlah elemen maksimum list statik

typedef FOOD ElType;
typedef struct Node * rType;

typedef struct{
    union{
        ElType container[100];
        Node * resep[100];
        int num[100];
    } ltype;
    int NEFF; // Jumlah efektif list
}ListStatik;

/* *** SELEKTOR *** */
#define ELMT(l,i) (l).ltype.container[(i)]
#define NEFF(l) (l).NEFF
#define RINFO(l,i) (l).ltype.resep[(i)]
#define IINFO(l,i) (l).ltype.num[(i)]

/* *** CREATOR *** */
void createList(ListStatik *l);
/* Membuat list kosong dengan NEFF = 0*/

/* *** INPUT *** */
void inputListFood(ListStatik *l);
/* Membaca banyak makanan yang dimasukkan lalu membuat list makanan 
input dilakukan dari sebuah file*/
void readResep(ListStatik *l);
/* Membaca resep dari sebuah file konfigurasi dan disimpan dalam bentuk list */

/* *** TULIS / SALIN *** */
void displayList(ListStatik l);
/* Menuliskan isi list food*/
void displayResep(ListStatik l);

ListStatik copyList(ListStatik *l);
/* Menyalin seluruh l ke l1*/

int panjangList(ListStatik l);
/* Mengembalikan panjang efektif dari l */

void buy(PrioQueueTime *q, ListStatik fd);
/* Melakukan proses buy */
Word findFdAksi(int N, ListStatik l);
/*Mengembalikan aksi dari makanan dengan id = N*/
Word findFdName(int N, ListStatik l);
/*Mengembalikan nama makanan dengan id = N*/
TIME findFdExp(int N, ListStatik l);
/*Mengembalikan waktu exp dari makanan dengan id = N*/
void bukuResep(ListStatik l, ListStatik f);
/*  ListStatik *l = list yang berisi tree yang mengandung resep
    ListStatik f = list yang berisi makanan (untuk ubah id menjadi word makanan)
*/
void chop(ListStatik fc, ListStatik f);
void fry(ListStatik fc, ListStatik f);
void mix(ListStatik fc, ListStatik f);
ListStatik findChild(int id, ListStatik resep);
/*Membuat suatu list statik yang berisi child dari
makanan dengan id = "id"*/
#endif