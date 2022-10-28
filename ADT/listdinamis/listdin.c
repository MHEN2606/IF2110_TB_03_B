/* NIM : 13521013
Nama : Eunice Sarah Siregar */
/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
   BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
   CAPACITY(*l) = capacity;
   NEFF(*l) = 0;
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
   free(BUFFER(*l));
   CAPACITY(*l) = 0;
   NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
   return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
   return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   return NEFF(l)-1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
   return (i >= 0 && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
   return (NEFF(l) == 0);
}
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
   return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{ int n;
  scanf("%d", &n);
  while(n < 0 || n > CAPACITY(*l)){
    scanf("%d", &n);
  }
  int i;
  int a;
  for(i = 0; i < n; i++){
    scanf("%d", &a);
    ELMT(*l, i) = a;
  }
  NEFF(*l) = n;
}
void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{ printf("[");
  int i;
  for(i = 0; i < NEFF(l); i++){
    printf("%d", ELMT(l, i));
    if( i != NEFF(l) - 1){
      printf(",");
    }
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
   ListDin l;
   int i, len;
   CreateListDin(&l, CAPACITY(l1));
   NEFF(l) = NEFF(l1);
   len = listLength(l1);
   if (plus){
       for (i=0; i<len; i++){
           ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
       }
   }
   else{
       for (i=0; i<len; i++){
           ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
       }
   }
   return l;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
{
  boolean eq;
  int i;

  eq = false;
  if (NEFF(l1) == NEFF(l2)) 
  {
    i=0;
    eq = true;
    while (i<NEFF(l1) && eq) 
    {
      if (ELMT(l1,i) != ELMT(l2,i))
        eq = false;
      else
        i++;
    }
  }
  return eq;
}
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
   if (isEmpty(l)){
      return IDX_UNDEF;
   }
   int i = 0;
   while ((ELMT(l,i) != val) && i != listLength(l)){
      i++;
   }
   if (i == listLength(l)){
      return IDX_UNDEF;
   }
   else{
      return i;
   }
}
/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
   {
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    int i, len;
    len = listLength(l);
    for (i=1; i<len; i++){
        if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min){
            *min = ELMT(l,i);
        }
    }
}
}
/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
   
   dealocateList(lOut);
   CreateListDin(lOut, CAPACITY(lIn));
   int i;
   for (i = 0 ; i<NEFF(lIn); i++){
      ELMT(*lOut, i) = ELMT(lIn, i);
   }
   NEFF(*lOut) = NEFF(lIn);

}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
   int i;
   int sum = 0;
   for (i = 0; i < NEFF(l); i++){
      sum += ELMT(l,i);
   }
   return sum;
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
   int count = 0;
   int i;
   for (i = 0; i<listLength(l); i++){
      if(ELMT(l,i) == val){
         count++;
      }
   }
   return count;
}
/* ********** SORTING ********** */
// Fungsi untuk menukar elemen list
void swap(ListDin *l, int idx1, int idx2){
    int temp;
    temp = ELMT(*l, idx1);
    ELMT(*l, idx1) = ELMT(*l, idx2);
    ELMT(*l, idx2) = temp;
}

void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

{
   int i, j;
   int len = listLength(*l);
   if (len > 1){
      if (asc) {
         for(i = 0; i < len; i++){
            for(j = 0; j < len-i-1; j++){
               if (ELMT(*l, j) > ELMT(*l, j+1)){
                  swap(l, j, j+1);
               }
            }
         }
      }
      else{
         for(i = 0; i < len; i++){
            for(j = 0; j < len-i-1; j++){
               if (ELMT(*l, j) < ELMT(*l, j+1)){
                  swap(l, j, j+1);
               }
            }
         }
      }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   ELMT(*l, NEFF(*l)) = val;
   NEFF(*l)+= 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, NEFF(*l)-1);
   NEFF(*l)--;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
   ListDin temp;
   CreateListDin(&temp, CAPACITY(*l));
   copyList(*l, &temp);
   int tempNeff = NEFF(*l);
   dealocateList(l);
   CreateListDin(l, CAPACITY(temp) + num);
   NEFF(*l) = tempNeff;
   
   int i;
   for (i = 0; i < listLength(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
   }
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
  int i;
  ListDin temp;

  CreateListDin(&temp, CAPACITY(*l)-num);
  NEFF(temp) = NEFF(*l);
  
  for(i=0;i<NEFF(temp);i++) {
    ELMT(temp,i) = ELMT(*l,i);
  }
  dealocateList(l);
  CAPACITY(*l) = CAPACITY(temp);
  BUFFER(*l) = BUFFER(temp);
  NEFF(*l) = NEFF(temp);
}
void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
   shrinkList(l, CAPACITY(*l)-NEFF(*l));
}