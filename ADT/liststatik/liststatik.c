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

    STARTCONFIGWORD("../konfigurasi/makanan.txt");// buka file konfigurasi

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
        printf("%d",ID(ELMT(l,i)));
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

void buy(PrioQueueTime *q, ListStatik fd){
    int x; infotype eq;
    ListStatik display;
    createList(&display);
    Word BUY = {"Buy", 3};
    printf("======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");
    printf("List Bahan Makanan\n");
    int j = 0;
    for (int i = 0; i < panjangList(fd); i++){
        if(isSameWord(BUY, AKSI(ELMT(fd,i)))){
            ELMT(display,j) = ELMT(fd,i);
            printf("%d. ", j+1);
            tulisKata(FOODNAME(ELMT(display,j)));
            printf(" (%d menit)\n", timeToMinute(SEND(ELMT(display,j))));
            j++;
        }
    }
    NEFF(display) = j-1;
    printf("Kirim 0 untuk exit.\n");
    printf("Enter command: ");
    STARTWORD();
    x = charToInt(currentWord);
    while (x-1 != -1) {
        if(x-1 < 0 || x-1 > panjangList(display)){
            printf("ID tidak valid, coba lagi!\n");
            printf("Enter command: ");
            STARTWORD();
            x = charToInt(currentWord);
        }
        else
        {
            printf("Berhasil memesan ");
            tulisKata(FOODNAME(ELMT(display,x-1)));
            printf(". ");
            tulisKata(FOODNAME(ELMT(display,x-1)));
            printf(" akan diantar dalam %d menit.\n", timeToMinute(SEND(ELMT(display,x-1))));

            /* PROSES ENQUEUE KE Priority Queue q */
            eq.time = timeToSecond(SEND(ELMT(display,x-1)));
            eq.exp = timeToSecond(EXP(ELMT(display,x-1)));
            eq.info = FOODNAME(ELMT(display,x-1));
            eq.id = ID(ELMT(display, x-1));
            Enqueue(q,eq,true);

            printf("\n");
            printf("Enter command: ");
            STARTWORD();
            x = charToInt(currentWord);
        }
    }
}
void readResep(ListStatik *l)
/*Membaca file konfigurasi dari resep lalu menyimpannya ke tree
x berperan sebagai node utama dari tree (parent)
x memiliki beberapa child (tidak ada sibling karena pertama)*/
{
    Node x;
    Node y;
    STARTCONFIGWORD("../konfigurasi/resep.txt");
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
TIME findFdExp(int N, ListStatik l)
/*Mengembalikan waktu exp dari makanan dengan id = N*/
{
    int i;
    for (i = 0; i<NEFF(l) ; i++)
    {
        if(ID(ELMT(l,i)) == N)
        {
            return EXP(ELMT(l,i));
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

void chop(ListStatik fc, ListStatik f){
    int tempInfo;
    Word tempAksi, tempName;
    Word CHOP = {"Chop", 4};
    printf("======================\n");
    printf("==      CHOP        ==\n");
    printf("======================\n");
    int count = 0;
    printf("List Bahan Makanan yang Bisa Dibuat: ");
    for (int i = 0; i < NEFF(fc); i++)
    {
        tempInfo = tInfo(*RINFO(fc, i)); 
        tempAksi = findFdAksi(tempInfo, f);
        if(isSameWord(tempAksi, CHOP)){
            count++;
            tempName = findFdName(tempInfo, f);
            printf("   %d.",count);
            tulisKata(tempName);
        }
    }  
    printf("Kirim 0 untuk exit.\n");
    printf("Enter command: ");
    STARTWORD();
    int x = charToInt(currentWord);
    while(x != 0){
        /* VALIDASI INPUT*/
        printf("Kirim 0 untuk exit.\n");
        printf("Enter command: ");
        STARTWORD();
        int x = charToInt(currentWord);
    }
}

void fry(ListStatik fc, ListStatik f){
    int tempInfo;
    Word tempAksi, tempName;
    Word FRY = {"Fry", 3};
    printf("======================\n");
    printf("==       FRY        ==\n");
    printf("======================\n");
    int count = 0;
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    for (int i = 0; i < NEFF(fc); i++)
    {
        tempInfo = tInfo(*RINFO(fc, i)); 
        tempAksi = findFdAksi(tempInfo, f);
        if(isSameWord(tempAksi, FRY)){
            count++;
            tempName = findFdName(tempInfo, f);
            printf("   %d.",count);
            tulisKata(tempName);printf("\n");
        }
    }
    printf("Kirim 0 untuk exit.\n");
    printf("Enter command: ");
    STARTWORD();
    int x = charToInt(currentWord);
    while(x != 0){
        /* VALIDASI INPUT*/
        printf("Kirim 0 untuk exit.\n");
        printf("Enter command: ");
        STARTWORD();
        int x = charToInt(currentWord);
    }
}

void mix(ListStatik fc, ListStatik f){
    int tempInfo;
    Word tempAksi, tempName;
    Word MIX = {"Mix", 3};
    printf("======================\n");
    printf("=        MIX         =\n");
    printf("======================\n");
    int count = 0;
    printf("List Bahan Makanan yang Bisa Dibuat: \n");
    for (int i = 0; i < NEFF(fc); i++)
    {
        tempInfo = tInfo(*RINFO(fc, i)); 
        tempAksi = findFdAksi(tempInfo, f);
        if(isSameWord(tempAksi, MIX)){
            count++;
            tempName = findFdName(tempInfo, f);
            printf("   %d.",count);
            tulisKata(tempName);
            printf("\n");
        }
    }
    printf("Kirim 0 untuk exit.\n");
    printf("Enter command: ");
    STARTWORD();
    int x = charToInt(currentWord);
    while(x != 0){
        /* VALIDASI INPUT*/
        printf("Kirim 0 untuk exit.\n");
        printf("Enter command: ");
        STARTWORD();
        int x = charToInt(currentWord);
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
    while (nextSibling(&temp))
    {
        IINFO(L,i) = tInfo(temp);
        NEFF(L)++;
    }
}