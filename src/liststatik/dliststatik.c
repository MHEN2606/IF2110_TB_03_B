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
    Word temp, temp1;
    Set S;
    /*
    Untuk menampilkan food harus mengubah path di liststatik menjadi
    ../../config/makanan.txt
    ../../config/resep.txt
    */
    printf("================================\n");
    printf("||******DRIVER LISTSTATIK*****||\n");
    printf("================================\n");
    inputListFood(&fd);
    displayList(fd);
    readResep(&resep);
    printf("\nPanjang List Statik Resep : ");
    printf("%d\n",panjangList(resep));
    printf("\nCopy makanan ke list copymakanan\n");
    copymakanan = copyList(&fd);
    displayList(copymakanan);
    printf("\nMakanan dengan id 11\n");
    temp = findFdName(11,fd);
    tulisKata(temp);
    printf("\nAksi dari makanan dengan id 11\n");
    temp1 = findFdAksi(11,fd);
    tulisKata(temp1);
    printf("\nWaktu exp untuk makanan dengan id 11\n");
    printf("%d detik\n",findFdExp(11,fd));
    printf("Waktu delivery untuk makanan dengan id 11\n");
    printf("%d detik\n",findFdDel(11,fd));
    printf("BUKU RESEP\n");
    bukuResep(resep,fd);
    child = findChild(37,resep);
    printf("Isi child dari id 37\n");
    for (int i = 0;i <NEFF(child);i++)
    {
        printf("|%d|",IINFO(child,i));
    }
    printf("\n");
    createNotificationList(&notif);
    Word ElNotif = {"FRY",3};
    Word ElNotif2 = {"AYAM",4};
    Notifikasi tempNotif;
    AKSINOTIF(tempNotif) = ElNotif;
    NAMANOTIF(tempNotif) = ElNotif2;
    insertNotif(&notif,tempNotif);
    displayNotif(&notif);
    printf("\n");
    printf("Buat Map dan isi Dengan Set\n");
    createMap(&map);
    createSet(&S);
    insert(&S,11);
    insert(&S,12);
    insertElMap(&map,S,11);
    makeMapOfResep(resep,&mapresep);
    printf("KEY : %d\n",KEY(MINFO(map,0)));
    printf("SET : ");
    displaySet(SET(MINFO(map,0)));
}