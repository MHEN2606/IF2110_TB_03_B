#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>
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

void makeInvTree(ListStatik *resep, PrioQueueTime inv)
/*Melakukan modifikasi pada list of tree resep dengan menambahkan
struktur data baru yaitu exist, exist akan bernilai 1 apabila 
user memiliki item tersebut dalam inventory nya dan bernilai
0 apabila barang tidak dimiliki oleh user*/
{
    PrioQueueTime tempInv;
    tempInv = inv;
    infotype out;
    Node tempNode;
    while (!IsEmpty(tempInv))
    {
        Dequeue(&tempInv,&out);
        /*Cari bagian dari tree resep yang memiliki id = id dari out*/
        for (int i = 0; i<NEFF(*resep);i++)
        {
            tempNode = *RINFO(*resep,i);
            if (tInfo(tempNode) == IDFood(out))
            {
                exist(tempNode) = 1;
                printf("masuk:%d",tInfo(tempNode));
            }
            else
            {
                exist(tempNode) = 0;
                tempNode = *firstChild(&tempNode);
                printf("Smpe sini");
                //ERROR DISNI
                while (&tempNode)
                {
                    printf("%d-",tInfo(tempNode));
                    printf("%d",IDFood(out));
                    if (tInfo(tempNode)==IDFood(out))
                    {
                        exist(tempNode) = 1;
                        printf("masuk:%d",tInfo(tempNode));
                    }
                    else 
                    {
                        exist(tempNode) = 0;
                    }
                    tempNode = *nextSibling(&tempNode);
                }
            }
        }
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
void Enqueue (PrioQueueTime * Q, infotype X, boolean select)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan EXP TIME */
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
        // Select = True => Urut berdasarkan send time; Select = False => Urut berdasarkan exp time
        if (select)
        {
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
        else
        {
            while(ExpTime(Elmt(*Q,idx))<ExpTime(Elmt(*Q,comp)))
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
}
void Dequeue (PrioQueueTime * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q) == 1){
        Info(*X) = Info(InfoHead(*Q));
        ExpTime(*X) = ExpTime(InfoHead(*Q));
        IDFood(*X) = IDFood(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Info(*X) = Info(InfoHead(*Q));
        ExpTime(*X) = ExpTime(InfoHead(*Q));
        IDFood(*X) = IDFood(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));
        if (Head(*Q)==MaxEl(*Q)-1){
            Head(*Q) = 0;
        } else {
            Head(*Q) = Head(*Q) + 1;
        }
    }
}
/* Operasi Tambahan */
void PrintInventory(PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
No urut. Nama makanan - Waktu Expired
Waktu time pasti 0
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
            displayTime(secondToTime(ExpTime(element)));
            num++;
        }
    }
}

void PrintDelivery(PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
No urut. Nama makanan - Waktu Delivery
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
            Dequeue(&t, &element);
            printf("%d. ",num);
            tulisKata(Info(element));
            printf(" - ");
            displayTime(secondToTime(Time(element)));
            num++;
        }
    }
}

void removeEl(PrioQueueTime *Q, Word makanan, infotype *out)
/*Menghapus suatu elemen dengan info=makanan lalu menggeser Queue*/
/*Elemen yang dihapus dipindahkan ke dalam variabel out*/
{
    int i,idxfound;
    boolean found = false;
    /*Bagi menjadi dua bagian, yaitu ketika head<tail atau sebaliknya*/
    if (Head(*Q)<Tail(*Q)){
        i = Head(*Q);
        // printf("%d\n",i);
        // printf("%d",Tail(*Q));
        // tulisKata(Info(Elmt(*Q,i)));
        /*Mencari index yang sesuai*/
        while(i<=Tail(*Q)&&!found){
            // printf("%d",i);
            if (isSameWord(Info(Elmt(*Q,i)),makanan)){
                idxfound = i;
                // printf("Wah idnya ketemu nih %d",idxfound);
                found = true;
            } 
            else
            {
                i++;
            }
        }
        Time(*out) = Time(Elmt(*Q,idxfound)); 
        Info(*out) = Info(Elmt(*Q,idxfound));
        // tulisKata(Info(Elmt(*Q,i))); 
        // tulisKata(Info(Elmt(*Q,idxfound)));
        /*Melakukan pergeseran untuk menghapus elemen pada idxfound*/
        if (idxfound != Tail(*Q))
        {
            for(i=idxfound;i<Tail(*Q);i++)
            {
                Elmt(*Q,i) = Elmt(*Q,i+1);
            }
        }
        Tail(*Q)--;
    } 
    else if (Head(*Q)==Tail(*Q))
    {
        idxfound = 0;
        if (isSameWord(Info(InfoHead(*Q)),makanan))
        {
            Head(*Q) = Nil;
            Tail(*Q) = Nil;
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
                    Elmt(*Q,i) = Elmt(*Q,i+1);
                }
            } else {
            i++;
            }
        }
        i = Head(*Q);
        /*Apabila ditemukan diantara head-maxEl*/
        while(i<MaxEl(*Q) && !found){
            if (isSameWord(Info(Elmt(*Q,i)),makanan)){
                idxfound = i;
                found = true;
                for(i=idxfound;i<MaxEl(*Q);i++){
                    Elmt(*Q,i-1) = Elmt(*Q,i);
                }
                Elmt(*Q,MaxEl(*Q)-1) = Elmt(*Q,0);
                for(i=0;i<Tail(*Q);i++){
                    Elmt(*Q,i) = Elmt(*Q,i+1);
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
}

void reduceDelTime(PrioQueueTime *Q, PrioQueueTime *NQ, STACK *commands, int t, ListStatik *notifikasi)
/*Mengurangi semua waktu yang berada di dalam Queue sebanyak t*/
/*t dalam satuan detik*/
{
    infotype x;
    PrioQueueTime temp;
    MakeEmpty(&temp,MaxEl(*Q));
    while(!IsEmpty(*Q))
    {
        Dequeue(Q,&x);
        Time(x) = Time(x) - t;
        Enqueue(&temp,x,true);
    }
    *Q = temp;
    deleteDel(Q, NQ, commands, notifikasi);
}

void reduceExpTime(PrioQueueTime *Q, STACK *commands, int t, ListStatik *notifikasi)
/*Mengurangi semua waktu yang berada di dalam Queue sebanyak t*/
/*t dalam satuan detik*/
{
    infotype x;
    PrioQueueTime temp;
    MakeEmpty(&temp,MaxEl(*Q));
    while(!IsEmpty(*Q))
    {
        Dequeue(Q,&x);
        ExpTime(x) = ExpTime(x) - t;
        Enqueue(&temp,x,false);
    }
    *Q = temp;
    deleteEx(Q, commands, notifikasi);
}

void deleteDel(PrioQueueTime *Q, PrioQueueTime *NQ, STACK *commands, ListStatik *notifikasi)
/*Menghapus semua elemen yang sudah diantar
sudah diantar -> Time = 0
Memindahkan ke NQ (New Queue)
*/
{
    infotype x;
    Notifikasi not;
    Word delivery = {"delivery", 8};
    int count;
    count = 0;
    PrioQueueTime temp;
    temp = *Q;
    if (!IsEmpty(*Q))
    {
        while (!IsEmpty(temp))
        {
            Dequeue(&temp,&x);
            if (Time(x)<=0)
            {
                Dequeue(Q,&x);
                Enqueue(NQ, x, false);
                count++;
                not.foodname=Info(x);
                not.aksi= delivery;
                insertNotif(notifikasi, not);
                Push(commands, IDFood(x));
            }
        }
        Push(commands, count);
        Push(commands, 20);
    }
}

void deleteEx(PrioQueueTime *Q, STACK *commands, ListStatik *notifikasi)
/*Menghapus semua elemen yang sudah expired*/
{
    infotype x;
    Notifikasi not;
    Word expired = {"expired", 7};
    int count;
    count = 0;
    PrioQueueTime temp;
    temp = *Q;
    if (!IsEmpty(*Q))
    {
        while (!IsEmpty(temp))
        {
            Dequeue(&temp,&x);
            if (ExpTime(x)<=0)
            {
                Dequeue(Q,&x);
                count++;
                not.foodname=Info(x);
                not.aksi= expired;
                insertNotif(notifikasi, not);
                Push(commands, IDFood(x));
            }
        }
        Push(commands, count);
        Push(commands, 21);
    }
}

boolean updateInv(PrioQueueTime *P, PrioQueueTime *Q, int id)
/*Fungsi mencari suatu food di dalam prioqueue inventory
mengembalikan true apabila terdapat id yang sama dengan "id"
menghapus elemen yang memiliki id == "id" dan melakukan enqueue ke
dalam prioqueue q.
*/
{
    PrioQueueTime temp;
    temp = *P;
    infotype X,out;
    boolean found = false;
    while (!IsEmpty(temp))
    {
        Dequeue(&temp,&X);
        if (IDFood(X)==id)
        {
            Enqueue(Q,X,false);
            removeEl(P,Info(X),&out);
            found = true;
        }
    }
    return found;
}