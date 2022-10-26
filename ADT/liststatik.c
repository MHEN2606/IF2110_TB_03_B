#include <stdio.h>
#include "liststatik.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "food.h"

/* *** CREATOR *** */
void createList(ListStatik *l){
/* Membuat list kosong dengan NEFF = 0*/
    NEFF(*l) = 0;
}

/* *** INPUT *** */
void inputListFood(ListStatik *l){
/* Membaca banyak makanan yang dimasukkan lalu membuat list makanan 
input dilakukan dari sebuah file (implementasi input dari file pada food.h)*/
    int N; //jumlah data yang akan dimasukkan
    int i = 0;
    FOOD fd; // fd adalah food

    /* Buat List Food l */
    createList(l);

    STARTCONFIGWORD("../konfigurasi/makanan.txt");// buka file konfigurasi

    // baca line pertama simpan sebagai N
    N = charToInt(currentWord);
    NEFF(*l) = N;
    ADVLINE();

    // ulang proses memasukkan data sebanyak N kali
    while (i < N)
    {
        /* Terima ID Makanan */
        int id = charToInt(currentWord);
        ADVLINE();

        /* Terima Nama Makanan*/
        /* Untuk nama makanan perlu dipikirkan kondisi kalo nama makanannya lebih
        dari 1 word. Misal Daging Anjing. Itu musti jadi 1 */
        Word namaMakanan = konkatKata();
        ADVLINE();

        /* Terima Waktu Expired */
        TIME exp;
        int e1,e2,e3;
        e1 = charToInt(currentWord);
        ADVWORD();
        e2 = charToInt(currentWord);
        ADVWORD();
        e3 = charToInt(currentWord);
        createTime(&exp, e1,e2,e3);
        ADVLINE();

        /* Terima Waktu Send*/
        TIME send;
        int s1,s2,s3;
        s1 = charToInt(currentWord);
        ADVWORD();
        s2 = charToInt(currentWord);
        ADVWORD();
        s3 = charToInt(currentWord);
        createTime(&send, s1,s2,s3);
        ADVLINE();

        /* Terima Aksi */
        Word aksi = currentWord;
        ADVLINE();

        /* Buat Food */
        createFood(&fd, id, namaMakanan, exp, send, aksi);

        /* Masukkan ke List */
        ELMT(*l,i) = fd;

        /* INCREMENT */
        i++;
    }
    closeFile();
}

/* *** TULIS / SALIN *** */
void displayList(ListStatik l){
/* Menuliskan isi list food*/
    for (int i = 0; i < NEFF(l); i++){
        printf("%d. ", i+1);
        tulisKata(FOODNAME(ELMT(l,i)));
        printf(" - ");
        tulisKata(AKSI(ELMT(l,i)));
        printf(" - %d menit\n", timeToMinute(SEND(ELMT(l,i))));
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