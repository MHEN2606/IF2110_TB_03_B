#include <stdio.h>
#include "liststatik.h"

/* *** CREATOR *** */
void createList(ListStatik *l){
/* Membuat list kosong dengan NEFF = 0*/
    NEFF(*l) = 0;
}

/* *** INPUT *** */
void inputListFood(ListStatik *l){
/* Membaca banyak makanan yang dimasukkan lalu membuat list makanan 
input dilakukan dari sebuah file (implementasi input dari file pada food.h)*/
    int N; //jumlah data yang akan dimasukkan
    int i = 0;
    FOOD fd; // fd adalah food

    /* Buat List Food l */
    createList(l);

    STARTCONFIGWORD("../config/makanan.txt");// buka file konfigurasi

    // baca line pertama simpan sebagai N
    N = charToInt(currentWord);
    NEFF(*l) = N;
    ADVLINE();

    // ulang proses memasukkan data sebanyak N kali
    while (i < N)
    {
        /* Terima ID Makanan */
        int id = charToInt(currentWord);
        ADVLINE();

        /* Terima Nama Makanan*/
        /* Untuk nama makanan perlu dipikirkan kondisi kalo nama makanannya lebih
        dari 1 word. Misal Daging Anjing. Itu musti jadi 1 */
        Word namaMakanan = konkatKata();
        ADVLINE();

        /* Terima Waktu Expired */
        TIME exp;
        int e1,e2,e3;
        e1 = charToInt(currentWord);
        ADVWORD();
        e2 = charToInt(currentWord);
        ADVWORD();
        e3 = charToInt(currentWord);
        createTime(&exp, e1,e2,e3);
        ADVLINE();

        /* Terima Waktu Send*/
        TIME send;
        int s1,s2,s3;
        s1 = charToInt(currentWord);
        ADVWORD();
        s2 = charToInt(currentWord);
        ADVWORD();
        s3 = charToInt(currentWord);
        createTime(&send, s1,s2,s3);
        ADVLINE();

        /* Terima Aksi */
        Word aksi = currentWord;
        ADVLINE();

        /* Buat Food */
        createFood(&fd, id, namaMakanan, exp, send, aksi);

        /* Masukkan ke List */
        ELMT(*l,i) = fd;

        /* INCREMENT */
        i++;
    }
    closeFile();
}

/* *** TULIS / SALIN *** */
void displayList(ListStatik l){
/* Menuliskan isi list food*/
    for (int i = 0; i < NEFF(l); i++){
        printf("%d. ", i+1);
        tulisKata(FOODNAME(ELMT(l,i)));
        printf(" - ");
        tulisKata(AKSI(ELMT(l,i)));
        printf(" - %d menit\n", timeToMinute(SEND(ELMT(l,i))));
    }
}
void displayResep(ListStatik l)
{
    // printf("START DISINI");
    for(int i = 0 ; i<NEFF(l) ; i++)
    {
    // printf("%d\n",tInfo(*RINFO(l,2)));
        Node x;
        x = *RINFO(l,i);
        if (firstChild(&x))
        {
            printf("%d\n",tInfo(x));
            // while (nextSibling(&x) != NULL)
            // {
            //     printf("%d",tInfo(*nextSibling(&x)));
            //     x = *nextSibling(&x);
            // }
        }
    }
    // printf("END DISINI");
}
ListStatik copyList(ListStatik *l){
/* Menyalin seluruh l ke l1*/
    ListStatik lcopy;

    createList(&lcopy);
    NEFF(lcopy) = NEFF(*l);

    for (int i = 0; i < NEFF(*l); i++){
        ELMT(lcopy, i) = ELMT(*l, i);
    }

    return lcopy;
}

int panjangList(ListStatik l){
/* Mengembalikan panjang efektif dari l */
    return(NEFF(l));
}

void readResep(ListStatik *l)
/*Membaca file konfigurasi dari resep lalu menyimpannya ke tree
x berperan sebagai node utama dari tree (parent)
x memiliki beberapa child (tidak ada sibling karena pertama)*/
{
    Node x;
    Node y;
    STARTCONFIGWORD("../config/resep.txt");
    int n = charToInt(currentWord);
    //printf("%d",n);
    NEFF(*l) = n;
    ADVLINE();
    for (int i = 0 ; i<n ; i++)
    {
        /*Isi LIST dengan tree*/
        // x = *createNode(charToInt(currentWord));

        RINFO(*l,i) = createNode(charToInt(currentWord));
        //printf("Masuk : %d\n",(tInfo(*RINFO(*l,i))));
        ADVWORD();
        int m = charToInt(currentWord);
        // printf("Childnya sebanyak : %d\n",m);
        ADVWORD();
        for (int j = 0 ; j<m ; j ++)
        {
            newChild(RINFO(*l,i),charToInt(currentWord));
            // printf("%d\n", charToInt(currentWord));
            ADVWORD();
        }
        ADVLINE();
    }
}

Word findFdName(int N, ListStatik l)
/*Mengembalikan nama makanan dengan id = N*/
{
    int i;
    for (i = 0; i<NEFF(l) ; i++)
    {
        if(ID(ELMT(l,i)) == N)
        {
            return FOODNAME(ELMT(l,i));
        }
    }
}
Word findFdAksi(int N, ListStatik l)
/*Mengembalikan aksi dari makanan dengan id = N*/
{
    int i;
    for (i = 0; i<NEFF(l) ; i++)
    {
        if(ID(ELMT(l,i)) == N)
        {
            return AKSI(ELMT(l,i));
        }
    }
}
int findFdExp(int N, ListStatik l)
/*Mengembalikan waktu exp dari makanan dengan id = N*/
{
    int i;
    for (i = 0; i<NEFF(l) ; i++)
    {
        if(ID(ELMT(l,i)) == N)
        {
            return timeToSecond(EXP(ELMT(l,i)));
        }
    }
}
int findFdDel(int N, ListStatik l)
/*Mengembalikan waktu delivery/masak dari makanan dengan id = N*/
{
    int i;
    for (i = 0; i<NEFF(l) ; i++)
    {
        if(ID(ELMT(l,i)) == N)
        {
            return timeToSecond(SEND(ELMT(l,i)));
        }
    }
}
void bukuResep(ListStatik l, ListStatik f)
/*  ListStatik *l = list yang berisi tree yang mengandung resep
    ListStatik f = list yang berisi makanan (untuk ubah id menjadi word makanan)
*/
{
    int i,number,tempInt;
    Word tempWord;
    Node *tempNode;
    printf("List Resep\n");
    printf("(aksi yang diperlukan - bahan...)\n");
    for(i = 0 ; i<NEFF(l);i++)
    {
        printf("   %d.",i+1);
        tempInt = tInfo(*RINFO(l,i));
        tempWord = findFdName(tempInt,f);
        tulisKata(tempWord);
        printf("\n");
        tempWord = findFdAksi(tempInt,f);
        printf("     ");
        tulisKata(tempWord);
        // printf("-");
        tempNode = firstChild(RINFO(l,i));
        while(tempNode != NULL)
        {
            printf(" - ");
            tempInt = tInfo(*tempNode);
            tempWord = findFdName(tempInt,f);
            tulisKata(tempWord);
            tempNode = nextSibling(tempNode);
        }
        printf("\n");
    }
}

ListStatik findChild(int id, ListStatik resep)
/*Membuat suatu list statik yang berisi child dari
makanan dengan id = "id"*/
{
    ListStatik L;
    Node temp;
    createList(&L);
    int i;
    for(i = 0 ; i<NEFF(resep);i++)
    {
        if(id == tInfo(*RINFO(resep,i)))
        {
            temp = *RINFO(resep,i);
        }
    }

    i = 0;
    temp = *firstChild(&temp);
    NEFF(L) = 1;
    IINFO(L,i) = tInfo(temp);
    while (nextSibling(&temp) != NULL)
    {
        i++;
        temp = *nextSibling(&temp);
        IINFO(L,i) = tInfo(temp);
        NEFF(L)++;
    }
    return L;
}
void createNotificationList(ListStatik *n){
    NEFF(*n) = 0;
}

void destruktor(ListStatik *n){
    NEFF(*n) = 0;
}

void insertNotif(ListStatik *n, Notifikasi val)
{
    NTF(*n,NEFF(*n)) = val;
    NEFF(*n)++;
}

void displayNotif(ListStatik *notif){
    Word delivery = {"delivery", 8};
    Word expired = {"expired", 7};
    printf("Notifikasi: ");
    if(NEFF(*notif) == 0)
    {
        printf("-\n");
    }
    else
    {
        printf("\n");
        int i;
        int count;
        count = 0;
        for (i = 0; i<NEFF(*notif); i++){
            printf("%d. ", ++count);
            tulisKata(NAMANOTIF(NTF(*notif,i)));
            if(isSameWord(AKSINOTIF(NTF(*notif,i)),delivery))
            {
                printf(" telah dikirim\n");
            }
            else if (isSameWord(AKSINOTIF(NTF(*notif,i)),expired))
            {
                printf(" telah expired\n");
            }
        }
        destruktor(notif);
    }
}

void createMap(ListStatik *M)
/*Membuat map kosong, map kosong dengan length = 0*/
{
    NEFF(*M) = 0;
}
void insertElMap(ListStatik *M,Set S,int key)
/*Memasukkan elemen set dengan key "key" ke dalam map*/
{
    ElMap temp;
    KEY(temp) = key;
    SET(temp) = S;
    MINFO(*M,NEFF(*M)) = temp;
    NEFF(*M)++;
}
void makeMapOfResep(ListStatik resep, ListStatik *Map)
/*Membuat liststatik dengan tipe data sesuai dengan map
key merepresentasikan parent pada resep
set merepresentasikan bahan pada resep
Makanan akan dapat dibuat apabila merupakan subset dari set inventory*/
{
    int key;
    ListStatik tempList;
    Set tempSet;
    createSet(&tempSet);
    for(int i = 0; i<NEFF(resep); i++)
    {
        key = tInfo(*RINFO(resep,i));
        tempList = findChild(key,resep);
        /*Buat set untuk semua child dari resep*/
        for (int i = 0; i<NEFF(tempList);i++)
        {
            insert(&tempSet,IINFO(tempList,i));
        }
        insertElMap(Map,tempSet,key);
        LENST(tempSet) = 0;
    }
}