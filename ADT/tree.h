/* File: tree.h */
/* ADT Pohon Biner dengan Representasi Berkait*/

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"

#define Nil -1
/* Nil adalah pohon kosong */

/* type point */
typedef int infotype;
typedef int address; 
typedef int addressList;
typedef address BinTree;
typedef addressList ListOfNode;  /* list linier yang elemennya adalah ElmtNode */
typedef struct 
{
    infotype Info;
    address Left;
    address Right;
 } node;
typedef struct
{
    infotype Info;
    addressList Next;
} ElmtNode;

#define ROOT(P) (P)-> Info
#define Left(P) (P)-> Left
#define Right(P) (P)-> Right

/* PRIMITIF */
/* SELEKTOR */
infotype GetAkar(BinTree P);
/* Mengirimkan nilai Akar pohon biner P */
BinTree GetLeft (BinTree P);
/* Mengirimkan Anak Kiri pohon biner P */
BinTree GetRight (BinTree P);
/* Mengirimkan Anak Kanan pohon biner P */ 

/* Konstruktor */
BinTree Tree (infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
address newTreeNode(infotype X);
/* Mengalokasi sebuah address P, bernilai tidak Nil jika berhasil */
/* Mengirimkan address hasil alokasi elemen bernilai X. Jika alokasi berhasil,
maka address tidak Nil, dan misalnya menghasilkan P, maka (P) -> info = X,
(P) -> Left = Nil, (P) -> Right = Nil. Jika alokasi gagal mengirimkan Nil */

void MakeTree (infotype Akar, BinTree L, BinTree R);
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
void BuildTree();
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi “konstanta” pohon dalam bentuk prefix. Memori pasti cukup,
alokasi pasti berhasil */
/* F.S. P dibentuk dari ekspresi dalam pita */

/* Predikat Penting */
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika pohon biner P adalah kosong P */
boolean IsOneElmt (BinTree P);
/* Mengirimkan true jika pohon biner P tidak kosong dan hanya terdiri dari atas 1
elemen */
boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */
boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan*/ 
boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan*/

/* Traversal */
void Preorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Preorder: akar, kiri, kanan dengan
Proses (P) */
void Inorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Inorder: kiri, akar, kanan dengan
Proses (P) */
void Postorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Postorder: kiri, kanan, akar dengan
Proses (P) */
void PrintTree (BinTree P, BinTree h);
/* I.S. P terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul P sudah ditulis dengan indentasi */
void spacePrintTree (BinTree P, int h, int s);

/* Search */
boolean Search (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* Fungsi lain */
int nbELmt (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int nbDaun (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
boolean IsSkewLeft (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
boolean IsSkewRight (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
int Level (BinTree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon
biner P. Akar(P) level-nya adalah 1. POhon P tidak kosong. */

/* Operasi lain */
void AddDaunTerkiri (BinTree P, infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun (BinTree P, infotype X, infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau
sebagai anak Kanan X (jika not Kiri) */
void DelDaunTerkiri (BinTree P);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus */
void DelDaun (BinTree P, infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. X dihapus dari P */
ListOfNode MakeListDaun (BinTree P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun
pohon P, jika semua alokasi berhasil. Menghasilkan list kosong jika ada alokasi
yang gagal */
ListOfNode MakeListPreorder (BinTree P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua
elemen pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan
list kosong jika ada alokasi yang gagal */
ListOfNode MakeListLevel (BinTree P, int N);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua
elemen pohon P yang levelnya=N, jika semua alokasi berhasil. Menghasilkan list
kosong jika ada alokasi yang gagal. */
/* Membentuk balanced tree */
BinTree BuildBalanceTree (int N) ;
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Terhadap Binary Search Tree */
boolean BSearch (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
void InsSearchTree (infotype X, BinTree P);
/* Menambahkan sebuah node X ke pohon biner pencarian P */
/* infotype terdiri dari key dan count. Key menunjukkan nilai unik, dan Count
berapa kali muncul */
void DelBtree (BinTree P, infotype X);
/* I.S. Pohon P tidak kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dg nilai X dihapus */ 
#endif