#include "kulkas.h"
#include <stdio.h>

/* KONSTRUKTOR */
void createKulkas(Kulkas *k)
/* Membuat kulkas kosong. Definisi Kosong adalah
   setiap infotype memiliki id -999 */
{
    infotype kosong;
    Word empty = {"EMPTY",5};
    kosong.exp = 0;
    kosong.info = empty;
    kosong.time = 0;
    kosong.id = ID_KOSONG;
    int i;
    for (i = 0; i<MAKS_BARIS; i++)
    {
        int j;
        for (j = 0; j < MAKS_KOLOM; j++)
        {
            IsiKulkas(*k, i, j) = kosong;
        }
    }
    BarisKulkas(*k) = MAKS_BARIS;
    KolomKulkas(*k) = MAKS_KOLOM;
}

/* BACA / TULIS */
void displayKulkas(Kulkas k)
/* Menampilkan kulkas. Yang ditampilkan adalah ID dari
   tiap food yang dimasukkan */
{
    int i;
    int j;
    for (i = 0; i < MAKS_BARIS; i++)
    {
        printf("| ");
        for (j = 0; j < MAKS_KOLOM; j++)
        {
            if(j != MAKS_KOLOM-1)
            {
                if(IDFood(IsiKulkas(k,i,j)) == ID_KOSONG)
                {
                    printf("- ");
                }
                else
                {
                    printf("%d ", IDFood(IsiKulkas(k,i,j)));
                }
            }
            else
            {
                if(IDFood(IsiKulkas(k,i,j)) == ID_KOSONG)
                {
                    printf("-");
                }
                else
                {
                    printf("%d", IDFood(IsiKulkas(k,i,j)));
                }
            }
        }
        printf(" |\n");
    }
}

/* VALIDATOR */
boolean isAvailable(Kulkas k, int i, int j)
/* Melihat apakah pada baris i dan kolom j 
   kulkas sudah terisi atau belum */
{
    return(IDFood(IsiKulkas(k,i,j)) == ID_KOSONG);
}

boolean isValid(int i, int j)
/* Melihat apakah baris i dan kolom j 
    valid pada kulkas atau tidak */
{
    return(i < MAKS_BARIS && j < MAKS_KOLOM);
}

boolean isKulkasKosong(Kulkas k)
/* Melihat apakah kulkas kosong atau tidak.
   Semua ID pada ElKulkas kosong */
{
    boolean kosong;
    kosong = true;
    int i,j;
    i = 0;j = 0;
    while(i < MAKS_BARIS && kosong)
    {
        while(j < MAKS_KOLOM && kosong)
        {
            if(IDFood(IsiKulkas(k, i, j)) != ID_KOSONG)
            {
                kosong = false;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return kosong;
}

/* OPERATOR */
void insertFood(Kulkas *k, PrioQueueTime *inv)
/* Memasukkan makanan dari inventory ke kulkas 
   makanan yang dimasukkan ke kulkas adalah makanan 
   yang berada di ujung depan queue. Melakukan traversal
   sampai ditemukan tempat kosong pertama */
{
    infotype food;
    Dequeue(inv, &food);
    int i,j;
    i = 0; j = 0;
    boolean found;
    found = false;
    while(i < MAKS_BARIS && !found)
    {
        while(j < MAKS_KOLOM && !found)
        {
            if(isAvailable(*k, i, j))
            {
                IsiKulkas(*k,i,j) = food;
                found = true;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    if(found)
    {
        printf("Proses memasukkan makanan ");
        tulisKata(Info(food));
        printf(" berhasil!\n");
    }
    else
    {
        printf("Proses memasukkan gagal karena kulkas penuh!\n");
    }
}

void removeFood(Kulkas *k, int i, int j, PrioQueueTime *inv)
/* Memasukkan makanan dari kulkas pada baris i
   dan kolom j ke inventory. Makanan dimasukkan 
   ke inventory diurutkan berdasarkan waktu */
{
    i = i-1;
    j = j-1;
    if(isValid(i,j))
    {
        infotype food;
        infotype kosong;
        Word empty = {"EMPTY",5};
        kosong.exp = 0;
        kosong.info = empty;
        kosong.time = 0;
        kosong.id = ID_KOSONG;

        if(IDFood(IsiKulkas(*k, i, j)) == ID_KOSONG)
        {
            printf("Lokasi yang dipilih kosong\n");
        }
        else
        {
        food = IsiKulkas(*k, i, j);
        IsiKulkas(*k, i, j) = kosong;

        Enqueue(inv, food, false);
        printf("Sukses mengeluarkan makanan dari kulkas!\n");
        }
    }
    else
    {
        printf("Lokasi pada kulkas tidak valid!\n");
    }
}