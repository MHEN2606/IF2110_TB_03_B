#include <stdio.h>
#include "set.h"

set createSet(ListStatik L)
/*Fungsi membuat set kosong set merupakan sebuah list untuk mengecek 
keberadaan item pada suatu inventory atau resep */
{
    int i;
    set L2;
    SEFF(L2) = NEFF(L);
    for (i=0;i<NEFF(L);i++)
    {
        IDSET(ElSetInfo(L2,i)) = ID(ELMT(L,i));
        EXIST(ElSetInfo(L2,i)) = 0;
    }
    return L2;
}

void makeSetFromInv(set L,PrioQueueTime P)
/*Membuat suatu set dari inventory pengguna*/
{
    PrioQueueTime temp;
    int tempID;
    infotype out;
    temp = P;
    while (!IsEmpty(temp))
    {
        Dequeue(&temp,&out);
        tempID = IDFood(out);
        for (int i = 0; i<SEFF(L) ; i++)
        {
            if(IDSET(ElSetInfo(L,i))==tempID)
            {
                EXIST(ElSetInfo(L,i)) = 1;
            }
        }
    }
}
// ListStatik makeListofSet(ListStatik resep)
// {
//     int i,tempParent;
//     set L;
//     createSet(&L);
//     ListStatik ret;
//     NEFF(ret) = 100;
//     for (i = 0; i<NEFF(ret);i++)
//     {
//         // tInfo(*RINFO(resep,i)) = tempParent;
//         SETN(ret,i) = L;
//     }
// }
// void makeSetFromResep(ListStatik L,ListStatik resep)
// {

// }
