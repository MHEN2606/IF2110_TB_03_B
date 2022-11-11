#include <stdio.h>
#include "prioqueuetime.h"

// COMMAND RUN
// gcc -c "../charmachine/charmachine.c" -o charmachine.o
// gcc -c "../wordmachine/wordmachine.c" -o wordmachine.o
// gcc -c "../time/time.c" -o time.o
// gcc -c prioqueuetime.c -o prioqueuetime.o
// gcc dprioqueuetime.c time.o charmachine.o wordmachine.o prioqueuetime.o
// ./a

int main()
{
    STACK S;
    infotype a,b,c;
    Word a1 = {"ikan",4};
    PrioQueueTime P,D,tp,O;
    MakeEmpty(&tp,10);
    MakeEmpty(&P,10);
    MakeEmpty(&D,10);
    MakeEmpty(&O,10);
    ExpTime(a) = 500;
    Time(a) = 500;
    IDFood(a) = 1;
    Info(a) = a1;
    printf("Tambah makanan ke inv: ikan (TIME : 500 s)\n");
    Enqueue(&P,a,false);

    Word b1 = {"mangga",6};
    ExpTime(b) = 300;
    Time(b) = 300;
    IDFood(b) = 2;
    Info(b) = b1;
    Enqueue(&P,b,false);
    printf("Tambah makanan ke inv: mangga (TIME : 300 s)\n");

    Word c1 = {"ayam",4};
    ExpTime(c) = 1000;
    Time(c) = 1000;
    IDFood(c) = 3;
    Info(c) = c1;
    Enqueue(&P,c,false);
    printf("Tambah makanan ke inv: ayam (TIME : 1000 s)\n");

    printf("--------------\n");
    printf("INVENTORY\n");
    printf("--------------\n");
    PrintInventory(P);

    infotype out;
    removeEl(&P,a1,&out);
    printf("Hapus elemen dengan nama ikan\n");

    printf("--------------\n");
    printf("INVENTORY\n");
    printf("--------------\n");
    PrintInventory(P);

    reduceExpTime(&P,&S,120);
    printf("Kurangi exp time dengan 2 menit\n");
    printf("--------------\n");
    printf("INVENTORY\n");
    printf("--------------\n");
    PrintInventory(P);

    printf("Tambah makanan ke Delivery: ikan (TIME : 500 s)\n");
    printf("Tambah makanan ke Delivery: mangga (TIME : 300 s)\n");
    printf("Tambah makanan ke Delivery: ayam (TIME : 1000 s)\n");
    Enqueue(&D,a,true);
    Enqueue(&D,b,true);
    Enqueue(&D,c,true);
    printf("\n--------------\n");
    printf("DELIVERY\n");
    printf("--------------\n");
    PrintDelivery(D);

    Dequeue(&D,&out);
    printf("Lakukan dequeue \n");
    printf("\n--------------\n");
    printf("DELIVERY\n");
    printf("--------------\n");
    PrintDelivery(D);

    printf("Lakukan pengurangan waktu dengan 2 menit \n");
    reduceDelTime(&D,&tp,&S,120);
    printf("\n--------------\n");
    printf("DELIVERY\n");
    printf("--------------\n");
    PrintDelivery(D);

    printf("--------------\n");
    printf("Inventory awal\n");
    printf("--------------\n");
    PrintInventory(P);
    boolean cek = updateInv(&P,&O,2);
    printf("--------------\n");
    printf("Cek inventory setelah kode makanan 2 diupdate\n");
    printf("--------------\n");
    PrintInventory(P);
    printf("--------------\n");
    printf("Temporary queue\n");
    printf("--------------\n");
    PrintInventory(O);
    return 0;
}