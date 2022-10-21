#include <stdio.h>
#include "liststatik.h"
#include "food.h"
#include "time.h"

/* *** CREATOR *** */
void createList(ListStatik *l){
/* Membuat list kosong dengan NEFF = 0*/
    NEFF(*l) = 0;
}

/* *** INPUT *** */
void inputList(ListStatik *l){
/* Membaca banyak makanan yang dimasukkan lalu membuat list makanan 
input dilakukan dari sebuah file (implementasi input dari file pada food.h)*/
    int n;
    FOOD fd;

    scanf("%d", &n);

    createList(l);

    for (int i = 0; i < n; i++){
        readFood(&fd);
        ELMT(*l,i) = fd;
    }
}

/* *** TULIS / SALIN *** */
void displayList(ListStatik *l){
/* Menuliskan isi list food*/
    for (int i = 0; i < NEFF(*l); i++){
        printf("%d. %s - %d menit\n", i, FOODNAME(ELMT(*l,i)), Minute(SEND(ELMT(*l,i))));
    }
}

ListStatik copyList(ListStatik *l){
/* Menyalin seluruh l ke l1*/
    ListStatik lcopy;

    createList(&lcopy);
    NEFF(lcopy) = NEFF(*l);

    for (int i = 0; i < NEFF(*l); i++){
        ELMT(lcopy, i) = ELMT(*l, i);
    }

    return lcopy;
}

int panjangList(ListStatik l){
/* Mengembalikan panjang efektif dari l */
    return(NEFF(l));
}