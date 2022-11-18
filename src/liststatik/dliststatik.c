#include <stdio.h>
#include "liststatik.h"

/*
CARA RUN
gcc -c "../charmachine/charmachine.c" -o charmachine.o
gcc -c "../wordmachine/wordmachine.c" -o wordmachine.o
gcc -c "../time/time.c" -o time.o
gcc -c "../set/set.c" -o set.o
gcc -c liststatik.c -o liststatik.o
gcc -c "../tree/tree.c" -o tree.o
gcc -c "../food/food.c" -o food.o
gcc dliststatik.c charmachine.o wordmachine.o time.o set.o liststatik.o tree.o food.o
./a
*/

int main()
{
    ListStatik fd,resep,copymakanan,child,notif,map,mapresep;
    Word temp;
    Set S;
    /*
    Untuk menampilkan food harus mengubah path di liststatik menjadi
    ../../config/makanan.txt
    ../../config/resep.txt
    */
    inputListFood(&fd);
    displayList(fd);
    readResep(&resep);
    displayResep(resep);
    printf("Panjang List Statik Resep\n");
    printf("%d",panjangList(resep));
    printf("Copy makanan ke list copymakanan\n");
    copymakanan = copyList(&fd);
    displayList(copymakanan);
    printf("Makanan dengan id 11\n");
    temp = findFdName(11,fd);
    tulisKata(temp);
    printf("Aksi dari makana dengan id 11\n");
    temp = findFdAksi(11,fd);
    printf("Waktu exp untuk makanan dengan id 11\n");
    printf("%d",findFdExp(11,fd));
    printf("Waktu delivery untuk makanan dengan id 11\n");
    printf("%d",findFdDel(11,fd));
    printf("BUKU RESEP\n");
    bukuResep(resep,fd);
    child = findChild(37,resep);
    for (int i = 0;i <NEFF(child);i++)
    {
        printf("|%d|",IINFO(child,i));
    }
    createNotificationList(&notif);
    Word ElNotif = {"FRY",3};
    Word ElNotif2 = {"AYAM",4};
    Notifikasi tempNotif;
    AKSINOTIF(tempNotif) = ElNotif;
    NAMANOTIF(tempNotif) = ElNotif2;
    insertNotif(&notif,tempNotif);
    displayNotif(&notif);
    createMap(&map);
    createSet(&S);
    insert(&S,11);
    insert(&S,12);
    insertElMap(&map,S,11);
    makeMapOfResep(resep,&mapresep);
}