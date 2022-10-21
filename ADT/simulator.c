#include <stdio.h>
#include <stdlib.h>

#include "simulator.h"
#include "point.h"
#include "liststatik.h"

/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, char name, ListStatik inv){
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/

}

/* *** INISIASI *** */
void splashScreen(){
/* Mencetak Splash Screen Gambar BMO :) */
    FILE * fptr;

    fptr = fopen("splash.txt", "r");

    char pic_content[255];

    while(fgets(pic_content,255,fptr) != NULL)
        printf("%s",pic_content);

    fclose(fptr);
}

void startSimulator(){
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
    /* ALGORITMA PROSES 1*/

    /* ALGORITMA PROSES 2*/
}

/* *** STOPPER *** */
void exitSimulator(boolean state){
/* Menerima state boolean true dan dijadikan false untuk menghentikan simulator*/
    return (state = false);
}