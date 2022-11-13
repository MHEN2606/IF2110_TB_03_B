#ifndef set_H
#define set_H

#include "../prioqueuetime/prioqueuetime.h"
#include "../boolean/boolean.h"
#include "../liststatik/liststatik.h"
typedef struct 
{
    int id_set;
    int exist;
} ElSet;

typedef struct 
{
    ElSet elSet[100];
    int SEFF;
}set;

#define IDSET(s) (s).id_set
#define EXIST(s) (s).exist
#define SEFF(s) (s).SEFF
#define ElSetInfo(s,i) (s).elSet[(i)]

set createSet(ListStatik L);
/*Fungsi membuat set kosong set merupakan sebuah list untuk mengecek 
keberadaan item pada suatu inventory atau resep */
void makeSetFromInv(ListStatik L,PrioQueueTime P);
/*Membuat suatu set dari inventory pengguna*/
boolean isUnion(ListStatik l1, ListStatik L2);
/*Fungsi mengembalikan true apabila set L1 merupakan union dari L2*/
#endif