/* File : prioqueuetime.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioqueuetime_H
#define prioqueuetime_H

#include "../wordmachine/wordmachine.h"
#include "../boolean/boolean.h"
#include "../time/time.h"
#include "../stack/stack.h"
#include "../liststatik/liststatik.h"
#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct
{
    int time;  /*waktu delivery dalam detik*/
    int exp; /* Waktu Expired */
    int id; /* ID Makanan */
    Word info; /* elemen karakter */
} infotype;
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    infotype *T;  /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueueTime;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
#define Time(e) (e).time
#define ExpTime(e) (e).exp
#define IDFood(e) (e).id
#define Info(e) (e).info
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueTime Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueueTime *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
void makeInvTree(ListStatik *resep, PrioQueueTime inv);
/*Melakukan modifikasi pada list of tree resep dengan menambahkan
struktur data baru yaitu exist, exist akan bernilai 1 apabila 
user memiliki item tersebut dalam inventory nya dan bernilai
0 apabila barang tidak dimiliki oleh user*/
/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueTime *Q, infotype X, boolean select);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue(PrioQueueTime *Q, infotype *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintInventory(PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
void PrintDelivery(PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
No urut. Nama makanan - Waktu Delivery
*/
void removeEl(PrioQueueTime *Q, Word makanan,infotype *out);
/*Menghapus suatu elemen dengan info=makanan lalu menggeser Queue*/
/*Elemen yang dihapus dipindahkan ke dalam variabel out*/

void traversalDecreaseTime(PrioQueueTime *Q, PrioQueueTime *R, int rTime);
/* Melakukan traversal pada Queue, mengurangi time sebanyak rTime. 
   Melakukan dequeue elemen jika ada elemen time pada Q sudah 0 
   Elemen yang di didequeue dienqueue ke R */

void reduceExpTime(PrioQueueTime *Q, STACK *commands, int t, ListStatik *notifikasi);
/*Mengurangi semua exp time yang berada di dalam Queue sebanyak t*/
/*Melakukan dequeue pada semua elemen yang mempunyai ExpTime<=0*/
/*t dalam satuan detik*/

void reduceDelTime(PrioQueueTime *Q, PrioQueueTime *NQ, STACK *commands, int t, ListStatik *notifikasi);
/*Mengurangi semua exp time yang berada di dalam Queue sebanyak t*/
/*Melakukan dequeue pada semua elemen yang mempunyai ExpTime<=0*/
/*t dalam satuan detik*/


void deleteEx(PrioQueueTime *Q, STACK *commands, ListStatik *notifikasi);
/*Menghapus semua elemen yang sudah diantar
Expired -> ExpTime <= 0
*/

void deleteDel(PrioQueueTime *Q, PrioQueueTime *NQ, STACK *commands, ListStatik *notifikasi);
/*Menghapus semua elemen yang sudah diantar
Expired -> ExpTime <= 0
*/
boolean updateInv(PrioQueueTime *P, PrioQueueTime *Q, int id);
/*Fungsi mencari suatu food di dalam prioqueue inventory
mengembalikan true apabila terdapat id yang sama dengan "id"
menghapus elemen yang memiliki id == "id" dan melakukan enqueue ke
dalam prioqueue q.
*/
void makeSetOfInv(Set *S,PrioQueueTime P);
/*Membuat suatu set yang terdiri atas id makanan di dalam inventory
karena tipe data set maka id yang berulang hanya akan masuk sekali*/
#endif