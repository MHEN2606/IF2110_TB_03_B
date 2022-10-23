#include "prioqueuetime.h"
#include "boolean.h"
#include "time.h"
#include "wordmachine.h"
#include <stdio.h>
/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (PrioQueueTime Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return MaxEl(Q) == NBElmt(Q);
}
int NBElmt (PrioQueueTime Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)){
        return 0;
    } else{
        if(Head(Q)<=Tail(Q)){
            return (Tail(Q)-Head(Q) + 1);
        } else {
            return (MaxEl(Q)-Tail(Q) - Head(Q) + 1);
        }
    }
}
/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
    if ((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}
/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    int idx,comp;
    infotype temp;
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } 
    else
    {
        /*Masukkan elemen x di tail dari Queue*/
        if(Tail(*Q)==MaxEl(*Q)-1)
        {
            Tail(*Q) = 0;
        }
        else 
        {
            Tail(*Q)++;
        }
        InfoTail(*Q) = X;

        /*Urutkan berdasarkan waktu*/
        idx = Tail(*Q);
        if (idx == 0){
            comp = MaxEl(*Q)-1;
        } else {
            comp = Tail(*Q)-1;
        }

        while(Time(Elmt(*Q,idx))<Time(Elmt(*Q,comp)))
        {
            temp = Elmt(*Q,idx);
            Elmt(*Q,idx) = Elmt(*Q,idx-1);
            Elmt(*Q,idx-1) = temp;
            if (idx == 0){
                idx = MaxEl(*Q)-1;
            } else{
                idx--;
            }
            if(comp==0){
                comp = MaxEl(*Q)-1;
            } else{
                comp--;
            }
        }
    }
}
void Dequeue (PrioQueueTime * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q) == 1){
        Info(*X) = Info(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else {
        Info(*X) = Info(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));
        Head(*Q) = (Head(*Q)%MaxEl(*Q)) + 1;
    }
}
/* Operasi Tambahan */
void PrintInventory (PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
No urut. Nama makanan - Waktu
*/
{
    PrioQueueTime t;
    infotype element;
    TIME temp;
    int num;
    num =  1;
    t = Q;
    if(!IsEmpty(Q)){
        while (!IsEmpty(t)){
            Dequeue(&t,&element);
            printf("%d. ",num);
            tulisKata(Info(element));
            printf(" - ");
            displayTime(secondToTime(Time(element)));
            printf("\n");
            num++;
        }
    }
}

void removeEl(PrioQueueTime *Q, Word makanan,infotype *out)
/*Menghapus suatu elemen dengan info=makanan lalu menggeser Queue*/
/*Elemen yang dihapus dipindahkan ke dalam variabel out*/
{
    int i,idxfound;
    boolean found = false;
    /*Bagi menjadi dua bagian, yaitu ketika head<tail atau sebaliknya*/
    if (Head(*Q)<Tail(*Q)){
        i = Head(*Q);
        /*Mencari index yang sesuai*/
        while(i<Tail(*Q)&&!found){
            if (isSameWord(Info(Elmt(*Q,i)),makanan)){
                idxfound = i;
                found = true;
            }
            i++;
        }
        /*Melakukan pergeseran untuk menghapus elemen pada idxfound*/
        for(i=idxfound;i<Tail(*Q);i++){
            Elmt(*Q,idxfound) = Elmt(*Q,idxfound+1);
        }
        Tail(*Q)--;
        Time(*out) = Time(Elmt(*Q,idxfound)); 
        Info(*out) = Info(Elmt(*Q,idxfound)); 
    } 
    else if (Head(*Q)==Tail(*Q))
    {
        if (isSameWord(Info(InfoHead(*Q)),makanan))
        {
            Head(*Q) = 0;
            Tail(*Q) = 0;
            Time(*out) = Time(Elmt(*Q,idxfound)); 
            Info(*out) = Info(Elmt(*Q,idxfound)); 
        }
    }
    else {
        i = 0;
        /*Terdapat dua kemungkinan
            - di antara 0-Tail
            - di antara head - maxEl
        */
       /*Apabila ditemukan di 0-tail*/
        while(i<Tail(*Q) && !found){
            if (isSameWord(Info(Elmt(*Q,i)),makanan)){
                idxfound = i;
                found = true;
                for(i=idxfound;i<Tail(*Q);i++){
                    Elmt(*Q,idxfound) = Elmt(*Q,idxfound+1);
                }
            }
            i++;
        }
        i = Head(*Q);
        /*Apabila ditemukan diantara head-maxEl*/
        while(i<MaxEl(*Q) && !found){
            if (isSameWord(Info(Elmt(*Q,i)),makanan)){
                idxfound = i;
                found = true;
                for(i=idxfound;i<MaxEl(*Q);i++){
                    Elmt(*Q,idxfound-1) = Elmt(*Q,idxfound);
                }
                Elmt(*Q,MaxEl(*Q)-1) = Elmt(*Q,0);
                for(i=0;i<Tail(*Q);i++){
                    Elmt(*Q,idxfound) = Elmt(*Q,idxfound+1);
                }
        }
        if (Tail(*Q)==0){
            Tail(*Q) = MaxEl(*Q)-1;
        } else{
            Tail(*Q)--;
        }
        Time(*out) = Time(Elmt(*Q,idxfound)); 
        Info(*out) = Info(Elmt(*Q,idxfound)); 
    }
}