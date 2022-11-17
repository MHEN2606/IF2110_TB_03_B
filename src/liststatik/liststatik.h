#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "../food/food.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../tree/tree.h"
#include "../set/set.h"
// #include "../prioqueuetime/prioqueuetime.h"

// #include "../set/set.h"

#define NMAX 100 // jumlah elemen maksimum list statik

typedef FOOD ElType;
typedef struct Node * rType;
typedef struct
{
    Word aksi;
    Word foodname;
}Notifikasi;

typedef struct
{
    int key;
    Set set;
}ElMap;

typedef struct{
    union{
        ElType container[100];
        Node * resep[100];
        int num[100];
        Notifikasi notif[100];
        Set set[100];
        ElMap elemen[100];
    } ltype;
    int NEFF; // Jumlah efektif list
}ListStatik;

/* *** SELEKTOR *** */
#define ELMT(l,i) (l).ltype.container[(i)] //Selektor untuk list makanan
#define NEFF(l) (l).NEFF
#define RINFO(l,i) (l).ltype.resep[(i)] //selektor untuk list resep
#define IINFO(l,i) (l).ltype.num[(i)] // selektor untuk list integer
#define SETINFO(l,i) (l).ltype.set[(i)] // selektor untuk list set

/*Definisikan selektor map disini*/
#define KEY(M) (M).key
#define SET(M) (M).set
#define MINFO(M,i) (M).ltype.elemen[(i)]

/*Definisikan selektor notifikasi disini*/
#define NTF(l,i) (l).ltype.notif[(i)]
#define AKSINOTIF(n) (n).aksi
#define NAMANOTIF(n) (n).foodname

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
Word findFdAksi(int N, ListStatik l);
/*Mengembalikan aksi dari makanan dengan id = N*/
Word findFdName(int N, ListStatik l);
/*Mengembalikan nama makanan dengan id = N*/
int findFdExp(int N, ListStatik l);
/*Mengembalikan waktu exp dari makanan dengan id = N*/
int findFdDel(int N, ListStatik l);
/*Mengembalikan waktu delivery/masak dari makanan dengan id = N*/
void bukuResep(ListStatik l, ListStatik f);
/*  ListStatik *l = list yang berisi tree yang mengandung resep
    ListStatik f = list yang berisi makanan (untuk ubah id menjadi word makanan)
*/
ListStatik findChild(int id, ListStatik resep);
/*Membuat suatu list statik yang berisi child dari
makanan dengan id = "id"*/
void createNotificationList(ListStatik *n);
/* Membuat list yang berisi notifikasi */

void destruktor(ListStatik *n);
/* Menghapus semua elemen yang berada di list */

void displayNotif(ListStatik *notif);
/* Menampilkan isi notifikasi */

void insertNotif(ListStatik *n, Notifikasi val);
/* Menambahkan elemen kedalam list notif*/

/**PRIMITIF UNTUK STRUKTUR DATA MAP**/
/*Map merupakan liststatik dengan yang terdiri dari elemen ElMap
ElMap mempunyai key yang nantinya dapat dikombinasikan dengan 
struktur data Set untuk operasi rekomendasi*/

void createMap(ListStatik *M);
/*Membuat map kosong, map kosong dengan length = 0*/

void insertElMap(ListStatik *M,Set S,int key);
/*Memasukkan elemen set dengan key "key" ke dalam map*/

void makeMapOfResep(ListStatik resep, ListStatik *Map);
/*Membuat liststatik dengan tipe data sesuai dengan map
key merepresentasikan parent pada resep
set merepresentasikan bahan pada resep
Makanan akan dapat dibuat apabila merupakan subset dari set inventory*/
#endif