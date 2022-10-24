/* File: tree.h */
/* ADT Pohon Biner dengan Representasi Berkait*/

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"
#include "tree.h"
#include <stdio.h>

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
infotype GetAkar(BinTree P)
/* Mengirimkan nilai Akar pohon biner P */
{
    return ROOT(P);
}
BinTree GetLeft (BinTree P)
/* Mengirimkan Anak Kiri pohon biner P */
{
    return Left(P);
}
BinTree GetRight (BinTree P)
/* Mengirimkan Anak Kanan pohon biner P */ 
{
    return Right(P);
}

/* Konstruktor */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    BinTree P;
    P = newTreeNode(Akar);
    if (P != Nil){
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

address newTreeNode(infotype X)
/* Mengalokasi sebuah address P, bernilai tidak Nil jika berhasil */
/* Mengirimkan address hasil alokasi elemen bernilai X. Jika alokasi berhasil,
maka address tidak Nil, dan misalnya menghasilkan P, maka (P) -> info = X,
(P) -> Left = Nil, (P) -> Right = Nil. Jika alokasi gagal mengirimkan Nil */
{
    address P;
    P = (address) malloc(sizeof(TreeNode));
    if (node != Nil){
        ROOT(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}
void MakeTree (infotype Akar, BinTree L, BinTree R)
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
{
    *P = Tree(Akar, L, R);
}
void BuildTree();
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi “konstanta” pohon dalam bentuk prefix. Memori pasti cukup,
alokasi pasti berhasil */
/* F.S. P dibentuk dari ekspresi dalam pita */

/* Predikat Penting */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika pohon biner P adalah kosong P */
{
    return P == Nil;
}
boolean IsOneElmt (BinTree P)
/* Mengirimkan true jika pohon biner P tidak kosong dan hanya terdiri dari atas 1
elemen */
{
    if (!IsTreeEmpty(P)){
        return Left(P) == Nil && Right(P) == Nil;
    }
    return false;
}
boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */
{
    if(!IsTreeEmpty(P)){
        return Left(P) != Nil && Right(P) == Nil;
    }
    return false;
}
boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan*/ 
{
    if (!isTreeEmpty(P))
    {
        return Left(P) == Nil && Right(P) != Nil;
    }
    return false;
}
boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan*/
{
    if (!isTreeEmpty(P))
    {
        return Left(P) != Nil && Right(P) != Nil;
    }
    return false;
}

/* Traversal */
void Preorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Preorder: akar, kiri, kanan dengan
Proses (P) */
{
    if (isTreeEmpty(P)){
        printf("()");
    }
    else{
        printf("(");
        printf("%d", ROOT(P));
        Preorder(Left(P));
        Preorder(Right(P));
        printf(")");
    }
}
void Inorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Inorder: kiri, akar, kanan dengan
Proses (P) */
{
    if (isTreeEmpty(P));
    {
        printf("()");
    }
    else{
        printf("(");
        Inorder(Left(P));
        printf("%d", ROOT(P));
        Inorder(Right(P));
        printf(")");
    }
}
void Postorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah diproses secara Postorder: kiri, kanan, akar dengan
Proses (P) */
{
    if (isTreeEmpty(P))
    {
        printf("()");
    }
    else{
        printf("(");
        Postorder(Left(P));
        Postorder(Right(P));
        printf("%d", ROOT(P));
        printf(")");
    }
}
void PrintTree (BinTree P, BinTree h)
/* I.S. P terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul P sudah ditulis dengan indentasi */
{
    spacePrintTree(P, h, 0);
}

void spacePrintTree (BinTree P, int h, int s)
{
    if(!isTreeEmpty(P)){
        for (int i = 0; i < h * s; i++)
        {
            printf(" ")
        }
        printf("%d\n", ROOT(P));
        spacePrintTree(Left(P), s, h + 1);
        spacePrintTree(Right(P), s, h + 1);
    }
}
/* Search */
boolean Search (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    boolean flag;
    flag = false;
    while (!isTreeEmpty(P))
    {
        if(X == ROOT(P)){
            flag = true;
        }
    }
    return flag;
}

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