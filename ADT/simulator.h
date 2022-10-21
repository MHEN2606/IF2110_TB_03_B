#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "point.h"
#include "liststatik.h"
#include "boolean.h"

typedef struct{
    char *name;
    POINT position;
    ListStatik inventory; //list inventory
} SIMULATOR;

/* *** SELEKTOR *** */
#define USERNAME(S) (S).name
#define POSISI(S) (S).position // akses absis dan ordinat => ABSIS(POSISI(S)) and ORDINAT(POSISI(S))
#define INV(S) (S).inventory
#define EINV(S,i) (S).inventory.container[(i)]
#define LINV(S) (S).inventory.NEFF


/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, char name, ListStatik inv);
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/

/* *** INISIASI *** */
void splashScreen();
/* Mencetak Splash Screen Gambar BMO :) */

void startSimulator();
/* Start Simulator terdiri dari beberapa proses:
    Proses 1:
    Melakukan load dari file konfigurasi.
    Loading menggunakan mesin kata, mesin karakter
    Hasil Load Peta dijadikan matriks
    Hasil Load Makanan dijadikan list makanan
    Hasil Load Resep dijadikan Tree Resep
    
    Proses 2:
    Membuat user dengan create user.
    Point origin berdasarkan peta (simbol S)
    char name dari masukan keyboard
    liststatik inv kosong
*/

/* *** STOPPER *** */
void exitSimulator(boolean state);
/* Menerima state boolean true dan dijadikan false untuk menghentikan simulator*/

#endif