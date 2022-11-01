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
    } ltype;
    int NEFF; // Jumlah efektif list
}ListStatik;

/* *** SELEKTOR *** */
#define ELMT(l,i) (l).ltype.container[(i)]
#define NEFF(l) (l).NEFF
#define RINFO(l,i) (l).ltype.resep[(i)]

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

#endif