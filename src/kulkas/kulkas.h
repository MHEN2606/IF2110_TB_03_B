/* ADT KULKAS */
/* Spesifikasi */
/* Kulkas berbentuk matriks 10 x 20 dengan tipe isi integer */
#include "../boolean/boolean.h"
#include "../prioqueuetime/prioqueuetime.h"
#include "../wordmachine/wordmachine.h"

#ifndef _KULKAS_H_
#define _KULKAS_H_

typedef infotype ElKulkas;

#define ID_KOSONG -999
#define MAKS_BARIS 10
#define MAKS_KOLOM 20

typedef struct{
    ElKulkas mem[MAKS_BARIS][MAKS_KOLOM];
    int Baris;
    int Kolom;
} Kulkas;

/* SELEKTOR */
#define IsiKulkas(M,i,j) (M).mem[(i)][(j)]
#define BarisKulkas(M) (M).Baris
#define KolomKulkas(M) (M).Kolom

/* KONSTRUKTOR */
void createKulkas(Kulkas *k);
/* Membuat kulkas kosong. Definisi Kosong adalah
   setiap infotype memiliki id -999 */

/* BACA / TULIS */
void displayKulkas(Kulkas k);
/* Menampilkan kulkas. Yang ditampilkan adalah ID dari
   tiap food yang dimasukkan */

/* VALIDATOR */
boolean isAvailable(Kulkas k, int i, int j);
/* Melihat apakah pada baris i dan kolom j 
   kulkas sudah terisi atau belum */

boolean isValid(int i, int j);
/* Melihat apakah baris i dan kolom j 
    valid pada kulkas atau tidak */

boolean isKulkasKosong(Kulkas k);
/* Melihat apakah kulkas kosong atau tidak.
   Semua ID pada ElKulkas kosong */

/* OPERATOR */
void insertFood(Kulkas *k, PrioQueueTime *inv);
/* Memasukkan makanan dari inventory ke kulkas 
   makanan yang dimasukkan ke kulkas adalah makanan 
   yang berada di ujung depan queue. Melakukan traversal
   sampai ditemukan tempat kosong pertama */

void removeFood(Kulkas *k, int i, int j,PrioQueueTime *inv);
/* Memasukkan makanan dari kulkas pada baris i
   dan kolom j ke inventory. Makanan dimasukkan 
   ke inventory diurutkan berdasarkan waktu */

#endif