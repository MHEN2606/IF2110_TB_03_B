#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../point/point.h"
#include "../time/time.h"
#include "../liststatik/liststatik.h"
#include "../prioqueuetime/prioqueuetime.h"
#include "../matrix/matrix.h"
#include "../food/food.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../boolean/boolean.h"

typedef struct{
    char *name;
    POINT position;
    PrioQueueTime inventory; //list inventory
} SIMULATOR;

/* *** SELEKTOR *** */
#define USERNAME(S) (S).name
#define POSISI(S) (S).position // akses absis dan ordinat => ABSIS(POSISI(S)) and ORDINAT(POSISI(S))
#define INV(S) (S).inventory

/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, char *name, PrioQueueTime inv);
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/

/* *** INISIASI *** */
void splashScreen();
/* Mencetak Splash Screen Gambar BMO :) */

void startSimulator(SIMULATOR *S, Matrix *peta, POINT *posisi, ListStatik *foodlist);
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

/* *** COMMAND PARSER *** */
/* Melakukan parsing dari input */
int cmdParser(char cmd[50]);
/* Menyimpan input string menjadi sebuah Word dengan tiap character 
    dibuat uppercase */
#endif