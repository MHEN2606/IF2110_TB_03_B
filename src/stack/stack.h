#ifndef STACK_H
#define STACK_H

#include "../boolean/boolean.h"

#define MAXCMD 50
#define idx_undef -1

typedef int perintah; // lihat ekivalensi tiap commands di wordmachine
typedef int address;

typedef struct{
    perintah arrCmd[MAXCMD]; // array of char berisi commands
    address TOP;
}STACK;

/* *** SELEKTOR *** */
#define TOP(s) (s).TOP
#define InfoTop(s) (s).arrCmd[(s).TOP]

/* *** KONSTRUKTOR *** */
void createEmptyStack(STACK *S);
/* Membuat stack kosong dengan address TOP idx_undef*/

/* *** VALIDATOR *** */
boolean isEmpty(STACK S);
/* Memeriksa apakah stack S kosong atau tidak */

boolean isFull(STACK S);
/* Memeriksa apakah stack S penuh atau tidak*/

/* *** OPERATOR *** */
void Push(STACK *S, perintah v);
/* Memasukkan perintah v ke dalam stack S */

void Pop(STACK *S, perintah *v);
/* Mengeluarkan TOP dari Stack S. TOP disimpan ke v */

/* *** DESTRUKTOR *** */
void clearStack(STACK *S);
/* Menghapus keseluruhan isi STACK. Membuat TOP(S) menjadi idx_undef */

#endif