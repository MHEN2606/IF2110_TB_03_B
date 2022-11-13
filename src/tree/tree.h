/* File: tree.h */
/* ADT Pohon Biner dengan Representasi Berkait*/

#ifndef _N_ARYTREE_
#define _N_ARYTREE_

#include "../boolean/boolean.h"
// #include "../listdinamis/listdin.h"
#include "../wordmachine/wordmachine.h"

// #define Nil -1
/* Nil adalah pohon kosong */

/* type point */
typedef int treeinfo;

struct Node
{
    // treeinfo depth;
    treeinfo exist;
    treeinfo info;
    struct Node *firstChild;
    struct Node *nextSibling;
};

typedef struct Node Node;
#define tInfo(P) (P).info
#define exist(P) (P).exist
#define firstChild(P) (P)-> firstChild
#define nextSibling(P) (P)-> nextSibling
// #define Depth(P) (P).depth

Node * createNode (treeinfo data);
/*Membuat dan mengembalikan suatu node baru dengan berisi firstChild dan nextSibling yang kosong*/
Node * newSibling (Node *x, treeinfo data);
/*Membuat suatu node yang merupakan sibling untuk node x*/
Node * newChild (Node *x, treeinfo data);
/*Membuat suatu node yang merupakan anak dari node x*/
Node * find(Node *x, treeinfo data);
/*Mencari suatu node yang berisi data*/
// void * findChild(Node *x, treeinfo data);
/*Mengeluarkan output semua info dari node yang menjadi anak dari node "data"
Node "data" => Node dengan INFO() = data
FORMAT OUTPUT:
bahan - bahan - ... (dst)
contoh : Ayam Potong - Minyak Goreng
*/
// void readResep(Node *x);
// /*Membaca file konfigurasi dari resep lalu menyimpannya ke tree
// x berperan sebagai node utama dari tree (parent)
// x memiliki beberapa child (tidak ada sibling karena pertama)*/

#endif