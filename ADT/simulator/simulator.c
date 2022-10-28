#include <stdio.h>
#include "simulator.h"

/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, char *name, PrioQueueTime inv){
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/
    USERNAME(*S) = name;
    POSISI(*S) = origin;
    INV(*S) = inv;
}

/* *** INISIASI *** */
void splashScreen(){
/* Mencetak Splash Screen Gambar BMO :) */
    FILE * fptr;

    fptr = fopen("../konfigurasi/splash.txt", "r");

    char pic_content[255];

    while(fgets(pic_content,255,fptr) != NULL)
        printf("%s",pic_content);

    fclose(fptr);
}

void startSimulator(SIMULATOR *S, Matrix *peta, POINT *posisi, ListStatik *foodlist){
/* Start Simulator terdiri dari beberapa proses:
    Proses 1:
    Melakukan load dari file konfigurasi.
    Loading menggunakan mesin kata, mesin karakter
    Hasil Load Peta dijadikan matriks
    Hasil Load Makanan dijadikan list makanan
    Hasil Load Resep dijadikan Tree Resep
    
    Proses 2:
    Membuat user dengan create user.
    Point origin berdasarkan peta (simbol S)
    char name dari masukan keyboard
    priority queue inventory kosong
*/
    /* ALGORITMA PROSES 1*/
    readMatrix(peta, posisi);
    inputListFood(foodlist);
    //Kurang load tree

    /* ALGORITMA PROSES 2*/
    char *name;
    printf("Masukkan nama Anda: ");
    scanf("%s", name);
    PrioQueueTime inventory;
    MakeEmpty(&inventory, 100);
    createUser(S, *posisi, name, inventory);
}

/* *** STOPPER *** */
void exitSimulator(boolean state){
/* Menerima state boolean true dan dijadikan false untuk menghentikan simulator*/
   !state;
}

/* *** COMMAND PARSER *** */
/* Melakukan parsing dari input */
int cmdParser(char cmd[50]){
/* Menyimpan input string menjadi sebuah Word dengan tiap character 
dibuat uppercase */
    Word command;
    char *t;
    int len = 0;
    for (t = &cmd[0]; *t != '\0'; t++){
        command.TabWord[len] = *t;
        /* Konversi tiap karakter lowercase jadi uppercase */
        if(command.TabWord[len] >= 'a' && command.TabWord[len] <= 'z'){
            command.TabWord[len] = command.TabWord[len] - 32;
        }
        len++;
    }
    command.Length = len;

    /* KUMPULAN COMMAND */
    Word START = {"START", 5}; //Mengeluarkan 1
    Word EXIT = {"EXIT", 4}; //  Mengeluarkan 2
    Word BUY = {"BUY", 3}; // Mengeluarkan 3
    Word FRY = {"FRY", 3}; // Mengeluarkan 4
    Word DELIVERY = {"DELIVERY", 8}; // Mengeluarkan 5
    Word MIX = {"MIX", 3}; // Mengeluarkan 6
    Word CHOP = {"CHOP", 4}; // Mengeluarkan 7
    Word BOIL = {"BOIL", 4}; // Mengeluarkan 8
    Word UNDO = {"UNDO", 4}; // Mengeluarkan 9
    Word REDO = {"REDO", 4}; // Mengeluarkan 10
    Word CATALOG = {"CATALOG", 7}; // Mengeluarkan 11
    Word COOKBOOK = {"COOKBOOK", 8}; // Mengeluarkan 12
    Word INVENTORY = {"INVENTORY", 9}; //Mengeluarkan 13
    Word MOVE = {"MOVE", 4}; //Mengeluarkan 14
    Word NORTH = {"NORTH", 5}; // Mengeluarkan 15
    Word SOUTH = {"SOUTH", 5}; // Mengeluarkan 16
    Word EAST = {"EAST", 4}; // Mengeluarkan 17
    Word WEST = {"WEST", 4}; // Mengeluarkan 18
    Word WAIT = {"WAIT", 4}; //Mengeluarkan 19

    // 0 untuk error silakan ulangi

    if (isSameWord(START, command)){
        return 1 ;
    }else if(isSameWord(EXIT, command)){
        return 2;
    }else if(isSameWord(BUY, command)){
        return 3;
    }else if(isSameWord(FRY, command)){
        return 4;
    }else if (isSameWord(DELIVERY, command)){
        return 5;
    }else if (isSameWord(MIX, command)){
        return 6;
    }else if(isSameWord(CHOP, command)){
        return 7;
    }else if(isSameWord(BOIL, command)){
        return 8;
    }else if (isSameWord(UNDO, command)){
        return 9;
    }else if (isSameWord(REDO, command)){
        return 10;
    }else if(isSameWord(CATALOG, command)){
        return 11;
    }else if(isSameWord(COOKBOOK, command)){
        return 12;
    }else if(isSameWord(INVENTORY, command)){
        return 13;
    }else if(isSameWord(MOVE, command)){
        return 14;
    }else if(isSameWord(NORTH, command)){
        return 15;
    }else if(isSameWord(SOUTH, command)){
        return 16;
    }else if(isSameWord(EAST, command)){
        return 17;
    }else if(isSameWord(WEST, command)){
        return 18;
    }else if(isSameWord(WAIT, command)){
        return 19;
    }else{
        return 0;
    }

}