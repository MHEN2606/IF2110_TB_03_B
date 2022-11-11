#include <stdio.h>
#include "stack.h"

/* *** KONSTRUKTOR *** */
void createEmptyStack(STACK *S){
/* Membuat stack kosong dengan address TOP idx_undef*/
    TOP(*S) = idx_undef;
}

/* *** VALIDATOR *** */
boolean isEmpty(STACK S){
/* Memeriksa apakah stack S kosong atau tidak */
    return(TOP(S) == idx_undef);
}

boolean isFull(STACK S){
/* Memeriksa apakah stack S penuh atau tidak*/
    return(TOP(S) == MAXCMD-1);
}

/* *** OPERATOR *** */
void Push(STACK *S, perintah v){
/* Memasukkan perintah v ke dalam stack S */
    TOP(*S)++;
    InfoTop(*S) = v;
}

void Pop(STACK *S, perintah *v){
/* Mengeluarkan TOP dari Stack S. TOP disimpan ke v */
    *v = InfoTop(*S);
    TOP(*S)--;
}

/* *** DESTRUKTOR *** */
void clearStack(STACK *S)
/* Menghapus keseluruhan isi STACK. Membuat TOP(S) menjadi idx_undef */
{
    perintah v;
    while(TOP(*S) != idx_undef)
    {
        Pop(S, &v);
    }
}