#include <stdio.h>
#include "simulator.h"

/* *** KONSTRUKTOR *** */
void createUser(SIMULATOR *S, POINT origin, Word name, PrioQueueTime inv){
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/
    USERNAME(*S) = name;
    POSISI(*S) = origin;
    INV(*S) = inv;
}

/* *** INISIASI *** */
void splashScreen(){
/* Mencetak Splash Screen Gambar BMO :) */
    /* FILE * fptr;

    fptr = fopen("../konfigurasi/splash.txt", "r");

    char pic_content[255];

    while(fgets(pic_content,255,fptr) != NULL)
        printf("%s",pic_content);

    fclose(fptr); */
    
printf("\n .----------------.  .-----------------. .----------------.  .----------------. \n");
printf("| .--------------. || .--------------. || .--------------. || .--------------. |\n");
printf("| |   ______     | || | ____  _____  | || | ____    ____ | || |     ____     | |\n");
printf("| |  |_   _ \\    | || ||_   \\|_   _| | || ||_   \\  /   _|| || |   .'    `.   | |\n");
printf("| |    | |_) |   | || |  |   \\ | |   | || |  |   \\/   |  | || |  /  .--.  \\  | |\n");
printf("| |    |  __'.   | || |  | |\\ \\| |   | || |  | |\\  /| |  | || |  | |    | |  | |\n");
printf("| |   _| |__) |  | || | _| |_\\   |_  | || | _| |_\\/_| |_ | || |  \\  `--'  /  | |\n");
printf("| |  |_______/   | || ||_____|\\____| | || ||_____||_____|| || |   `.____.'   | |\n");
printf("| |              | || |              | || |              | || |              | |\n");
printf("| '--------------' || '--------------' || '--------------' || '--------------' |\n");
printf(" '----------------'  '----------------'  '----------------'  '----------------' \n");
printf("\n");                                                                       
printf("        ,@@&%%(/****,,,,,,*,,,*,,,*,,,,,,*,,,,,,,,,,,,**/#%%&@@@@%%.               \n");
printf("    @//////////////////#%%/***///////////////////////////////////***/(%%@&        \n");
printf("   @//////////////////@//////////////////////////////////////////////////@      \n");
printf("   &//////////////////(//////**                                  %%//////(      \n");
printf("   #/////////////////(*/////*/                                      (/////      \n");
printf("   (///@@/////@@/////%%///////                                       &/////      \n");
printf("  ,//////////////////&//////%%                                       &////(      \n");
printf("  @//@/////@/////#(//@//////&                                       &////(      \n");
printf("  @//////////////////&//////@                                       %%////#      \n");
printf("  @////(@////////////#//////&                                       /////%%      \n");
printf("  @//////////////////(//////%%         @@                     &     .*////%%      \n");
printf("  @////////////////////////*#          ,          .##/       &     //////%%      \n");
printf("  @//@@@@@@@@@@@@%%///*/////*#                   /#######           #/////#      \n");
printf("  @/%%@@@@@@@@@@@@@//#*/////*#                   .&&%%&&#            &//////      \n");
printf("  @/%%@@&&@@@@@/@@&//%%*//////%%                                      %%/////,      \n");
printf("  @//@@@@@&@@@@@@///%%*//////&                                      /////*       \n");
printf("  &//((/////////////&*//////*%%(***,,.....                        .%%/////*       \n");
printf("  %%/%%@@@@@@@@@@@@///&*//////////////////////////////////////////////////(       \n");
printf("  %%////(@@@@@@(/////@//////(@@@@@@@@@@@@@@@@@@@&@&&(////////////////////%%       \n");
printf(" .#/%%@&&@@@@@@@&////@//////&&&&&&&&&&&&&&&&&&&&&&&&@///////#&&//////////@       \n");
printf("  (/@@@@@@@@@@@@@///@///////////////////////////////////////////////////@       \n");
printf("  /////#@@@@&(//////@///////////////////////////////////////////////////@       \n");
printf(" .///@@@@@@@@@@@////@//////////////////////////////////////////////////*&#      \n");
printf(" ,//@@@@#///@@@@@///@//////////&&,(*///////////////////&#%%*#///////////*%%(.     \n");
printf(" ,///@@(///(@@@@@///@///////%%///,,,//%%///////////////##%%****%%////*%%&&#/*//(.    \n");
printf(" ,////&////@@@&/////@////////%%&%%/,,%%(///////////////////////////%%#(//&////%%    \n");
printf(" .///%%////%%/////////&/////////*%%#,,*/////////////////////*//////////////%%///&   \n");
printf(" .///%%////%%/////////&///////////////////////////////*&%%&((((((#(///////# ////@  \n");
printf(" .//#///////////////@//////////////////////////////(%%%%(((((((((&//////%% ////// \n");
printf(" .(/@////%%//////////@///////**(#////*(%%(*///////////%%&(((((((((&//////&  #///& \n");
printf("  %%/&////&//////////@///////*&@@#*//(@@@@////////////&%%((((((&////////&  *(///.\n");
printf("   &%%////&//////////@//////////////////////////////////////////////////%%   #&%%@ \n");
printf("    @////@&&#///////&/////////////////////////////////////////////***/&  &#%%    \n");
printf("     %%&#/&        ,%%@@@&&&&@@@@&%%&%%######&,        (((&  @&((((((((((@,&(((@   \n");
printf("                                   @&#(((((((((((& #((((@       @&#(((((((((@   \n");
printf("                                          %%@%%((((((#((((@             %%&#((#    \n");
printf("                                                ,@&((((#                        \n");
printf("\n");
}

void startSimulator(SIMULATOR *S, Matrix *peta, POINT *posisi, ListStatik *foodlist, ListStatik *resep){
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
    PrioQueueTime inventory;
    /* ALGORITMA PROSES 1*/
    readMatrix(peta, posisi);
    inputListFood(foodlist);
    readResep(resep);

    /* ALGORITMA PROSES 2*/
    printf("Masukkan nama Anda: ");
    STARTWORD();
    MakeEmpty(&inventory, 100);
    createUser(S, *posisi, currentWord, inventory);
}

/* *** STOPPER *** */
void exitSimulator(){
/* Menerima state boolean true dan dijadikan false untuk menghentikan simulator*/
   printf("THANK YOU FOR USING BNMO!\n");
   printf("=========================\n");
   printf("        BNMO V.2.        \n");
   printf("13521007 - 13521004 - 13521018\n");
   printf("13521013 - 13521026 - 13521020\n");
}

/* *** COMMAND PARSER *** */
/* Melakukan parsing dari input */
int cmdParser(Word command){
/* Word dibuat uppercase */
    for (int i = 0; i < command.Length; i++){
        if(command.TabWord[i] >= 'a' && command.TabWord[i] <= 'z'){
            command.TabWord[i] = command.TabWord[i] - 32;
        }
    }

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

/* *** COMMANDS *** */
void undo(STACK *S, STACK *OUT, SIMULATOR *sim, Matrix *map, PrioQueueTime *delivery, ListStatik fd, TIME *t, ListStatik resep){
/* Melakukan proses undo */
    if(isEmpty(*S)){
        printf("Belum ada command! Tidak bisa melakukan undo\n");
    }else{
        perintah v;
        Pop(S, &v);
        if (v == 15){
            moveSouth(&POSISI(*sim), map);
        }else if(v == 16){
            moveNorth(&POSISI(*sim), map);
        }else if(v == 17){
            moveWest(&POSISI(*sim), map);
        }else if(v == 18){
            moveEast(&POSISI(*sim), map);
        }else if(v == 11){
            printf("List Makanan\n");
            printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)");
            displayList(fd);printf("\n");
        }else if(v == 13){
            printf("List Makanan di Inventory\n");
            printf("(nama - waktu sisa kedaluwarsa)\n");
            if(IsEmpty(INV(*sim))){
                printf("Inventory Kosong. Silakan melakukan BUY\n");
            }else{
                PrintInventory(INV(*sim));
                printf("\n");
            }
        }else if (v == 19){
            int jam, menit;
            Pop(S, &jam);
            Pop(S, &menit);
            int detik = jam * 3600 + menit * 60;
            *t = reduceTime(t,detik);
        }else if(v == 3){
            int N;
            Pop(S, &N);
            for(int i = 0; i < N; i++){
                // Dequeue 3 kali elemen pada delivery
                infotype m;
                Dequeue(delivery, &m);
            }
        }else if (v==5){
            printf("List Makanan\n");
            printf("(nama - waktu sisa delivery)\n");
            if(IsEmpty(*delivery))
            {
                printf("Delivery Kosong. Silakan melakukan BUY\n");
            }
            else
            {
                PrintDelivery(*delivery);printf("\n");
            }
        }else if (v == 12){
            /* Perintah Display Cook Book*/
            bukuResep(resep,fd);
        // }else if (v == 20){
        //     /* Perintah Terjadi Proses Delesi pada Queue Delivery */
        //     int N;
        //     Pop(S, &N);
        //     int i;
        //     for(i = 0; i < N; i++){
        //         int id;
        //         infotype eq;
        //         Pop(S, &id);
        //         eq.info = findFdName(id, fd);
        //         eq.time = 60;
        //         eq.exp = timeToSecond(findFdExp(id,fd));
        //         eq.id = id;
        //         Enqueue(delivery, eq, true);
        //     }
        //     undo(S, OUT, sim, map, delivery, fd, t, resep);
        // }else if (v == 21){
        //     /* Perintah Terjadi Proses Delesi pada Queue Inventory */
        //     int N;
        //     Pop(S, &N);
        //     int i;
        //     for(i = 0; i < N; i++){
        //         int id;
        //         infotype eq;
        //         Pop(S, &id);
        //         eq.info = findFdName(id, fd);
        //         eq.time = 0;
        //         eq.exp = 60;
        //         eq.id = id;
        //         Enqueue(&INV(*sim), eq, false);
        //     }
        //     undo(S, OUT, sim, map, delivery, fd, t, resep);
        }

        Push(OUT, v);
    }
}

// void undo(STACK *S, STACK *OUT, SIMULATOR *sim, Matrix *map, PrioQueueTime *delivery, ListStatik fd, TIME *t, ListStatik resep){
// /* Melakukan proses undo */
//     if(isEmpty(*S)){
//         printf("Belum ada command! Tidak bisa melakukan undo\n");
//     }else{
//         perintah v;
//         Pop(S, &v);
//         if (v == 15){
//             moveSouth(&POSISI(*sim), map);
//         }else if(v == 16){
//             moveNorth(&POSISI(*sim), map);
//         }else if(v == 17){
//             moveWest(&POSISI(*sim), map);
//         }else if(v == 18){
//             moveEast(&POSISI(*sim), map);
//         }else if(v == 11){
//             printf("List Makanan\n");
//             printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)");
//             displayList(fd);printf("\n");
//         }else if(v == 13){
//             printf("List Makanan di Inventory\n");
//             printf("(nama - waktu sisa kedaluwarsa)\n");
//             if(IsEmpty(INV(*sim))){
//                 printf("Inventory Kosong. Silakan melakukan BUY\n");
//             }else{
//                 PrintInventory(INV(*sim));
//                 printf("\n");
//             }
//         }else if (v == 19){
//             int jam, menit;
//             Pop(S, &jam);
//             Pop(S, &menit);
//             int detik = jam * 3600 + menit * 60;
//             *t = reduceTime(t,detik);
//         }else if(v == 3){
//             int N;
//             Pop(S, &N);
//             for(int i = 0; i < N; i++){
//                 // Dequeue 3 kali elemen pada delivery
//                 infotype m;
//                 Dequeue(delivery, &m);
//             }
//         }else if (v==5){
//             printf("List Makanan\n");
//             printf("(nama - waktu sisa delivery)\n");
//             if(IsEmpty(*delivery))
//             {
//                 printf("Delivery Kosong. Silakan melakukan BUY\n");
//             }
//             else
//             {
//                 PrintDelivery(*delivery);printf("\n");
//             }
//         }else if (v == 12){
//             /* Perintah Display Cook Book*/
//             bukuResep(resep,fd);
//         // }else if (v == 20){
//         //     /* Perintah Terjadi Proses Delesi pada Queue Delivery */
//         //     int N;
//         //     Pop(S, &N);
//         //     int i;
//         //     for(i = 0; i < N; i++){
//         //         int id;
//         //         infotype eq;
//         //         Pop(S, &id);
//         //         eq.info = findFdName(id, fd);
//         //         eq.time = 60;
//         //         eq.exp = timeToSecond(findFdExp(id,fd));
//         //         eq.id = id;
//         //         Enqueue(delivery, eq, true);
//         //     }
//         //     undo(S, OUT, sim, map, delivery, fd, t, resep);
//         // }else if (v == 21){
//         //     /* Perintah Terjadi Proses Delesi pada Queue Inventory */
//         //     int N;
//         //     Pop(S, &N);
//         //     int i;
//         //     for(i = 0; i < N; i++){
//         //         int id;
//         //         infotype eq;
//         //         Pop(S, &id);
//         //         eq.info = findFdName(id, fd);
//         //         eq.time = 0;
//         //         eq.exp = 60;
//         //         eq.id = id;
//         //         Enqueue(&INV(*sim), eq, false);
//         //     }
//         //     undo(S, OUT, sim, map, delivery, fd, t, resep);
//         }

//         Push(OUT, v);
//     }
// } 
