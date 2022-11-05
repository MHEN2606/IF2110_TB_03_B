#include <stdio.h>
#include "./simulator/simulator.h"
int main(){
    ListStatik fd, resep;
    POINT awal;
    Matrix map;
    SIMULATOR sim;
    TIME t;
    STACK notification, commands, poppedCommands;
    PrioQueueTime delivery;

    splashScreen();

    printf("Enter START/EXIT: ");
    STARTWORD();
    int startval = cmdParser(currentWord);

    while (startval == 0 || (startval >= 3 && startval <= 19))
    {
        printf("Perintah tidak valid! Silakan Ulangi!\n");
        printf("Enter START/EXIT: ");
        STARTWORD();
        startval = cmdParser(currentWord);
    }

    if (startval == 1)
    {
        startSimulator(&sim, &map, &awal, &fd, &resep);
        createTime(&t, 0,0,0);
        MakeEmpty(&delivery, 100);
        createEmptyStack(&notification);
        createEmptyStack(&commands);
        createEmptyStack(&poppedCommands);

        printf("\n");
        printf("Username: ");
        tulisKata(USERNAME(sim));
        printf("\n");
        printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
        printf("Waktu: "); displayTimeTitik(t);
        printf("Notifikasi: "); printf("-\n");
        displayMatrix(map); printf("\n");

        printf("Enter Command: ");
        STARTWORD();
        int gameval = cmdParser(currentWord);
        printf("\n");

        while(gameval != 2){
            /*rTime untuk mengurangi waktu pada Queue delivery dan Queue Inventory*/
            int rTime = 0;
            if (gameval == 0 || gameval == 1)
            {
                printf("Perintah tidak valid! Silakan ulangi\n");
            }
            else
            {
                /*BUY CHOP MIX FRY BOIL menambah waktu 60 detik*/
                /* !! INI MASIH BUTUH VALIDASI COMMAND VALID/GAK*/
                if (gameval==3 || gameval == 6 || gameval == 7 || gameval == 8 || gameval == 9)
                {
                    t = addTime(&t,60);
                    rTime += 60;
                }
                if(gameval == 9){
                    undo(&commands, &poppedCommands, &sim, &map, &delivery, fd, &t);
                }
                if(gameval == 19)
                {
                    int jam,menit,detik;
                    ADVWORD();
                    jam = charToInt(currentWord);
                    ADVWORD();
                    menit = charToInt(currentWord);
                    detik = jam * 3600 + menit * 60;
                    t = addTime(&t,detik);
                    rTime += detik;
                    printf("PERINTAH WAIT\n");
                    Push(&commands, menit); //push y
                    Push(&commands, jam); // push x
                    Push(&commands, gameval); // push wait
                }

                /* PERINTAH MOVE DIJALANKAN DI SINI */
                if (gameval == 14) 
                {
                    /* COMMAND 'MOVE' diterima, parse command arah */
                    ADVWORD();
                    int gerak = cmdParser(currentWord);
                    if(gerak < 15 || gerak > 18){
                        printf("Perintah tidak valid!\n");
                    }else{
                        if(gerak == 15){
                            /* MOVE NORTH */
                            moveNorth(&POSISI(sim), &map);
                        }else if (gerak == 16){
                            /* MOVE SOUTH */
                            moveSouth(&POSISI(sim), &map);
                        }else if (gerak == 17){
                            /* MOVE EAST */
                            moveEast(&POSISI(sim), &map);
                        }else{
                            /* MOVE WEST*/
                            moveWest(&POSISI(sim), &map);
                        }
                        Push(&commands, gerak);
                        t = addTime(&t,60);
                        rTime += 60;
                    }
                }

                /* PERINTAH YANG BERKAITAN DENGAN MAKANAN DIJALANKAN DI SINI */
                if(gameval == 3)
                {
                    if(isAdjacent(POSISI(sim), map, 'T')){
                        int length = NBElmt(delivery);
                        buy(&delivery, fd);
                        length = NBElmt(delivery) - length;
                        Push(&commands, length); // push berapa elemen yang ditambahkan
                        Push(&commands, gameval);
                    }else{
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 4)
                {
                    if(isAdjacent(POSISI(sim), map, 'F')){
                        printf("PERINTAH FRY\n");
                        Push(&commands, gameval);
                    }else{
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 7)
                {
                    if(isAdjacent(POSISI(sim), map, 'C')){
                        printf("PERINTAH CHOP\n");
                        Push(&commands, gameval);
                    }else{
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 8)
                {
                    if(isAdjacent(POSISI(sim), map, 'B')){
                        printf("Perintah BOil\n");
                        Push(&commands, gameval);
                    }else{
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 6)
                {
                    if(isAdjacent(POSISI(sim), map, 'M')){
                        printf("Perintah MIX\n");
                        Push(&commands, gameval);
                    }else{
                        printf("Anda tidak berada di area command!\n");
                    }
                }

                /*Catalog*/
                if(gameval == 11)
                {
                    printf("List Makanan\n");
                    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
                    displayList(fd);printf("\n");
                    Push(&commands, gameval);
                }
                if(gameval == 12)
                {
                    bukuResep(resep,fd);
                }
                if (gameval == 5)
                {
                    printf("List Makanan\n");
                    printf("(nama - waktu sisa delivery)\n");
                    if(IsEmpty(delivery))
                    {
                        printf("Delivery Kosong. Silakan melakukan BUY\n");
                    }
                    else
                    {
                        PrintDelivery(delivery);printf("\n");
                    }
                    Push(&commands, gameval);
                }

                /* PERINTAH YANG BERKAITAN DENGAN DISPLAY DIJALANKAN DI SINI*/
                if(gameval == 13)
                { // COMMAND INVENTORY
                    printf("List Makanan di Inventory\n");
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                    if(IsEmpty(INV(sim))){
                        printf("Inventory Kosong. Silakan melakukan BUY\n");
                    }else{
                        PrintInventory(INV(sim));
                        printf("\n");
                    }
                    Push(&commands, gameval);
                }
                /*UPDATE QUEUE INVENTORY & DELIVERY*/
                reduceDelTime(&delivery, &INV(sim),rTime);
                reduceExpTime(&INV(sim),rTime);
            }
            
            printf("\n");

            printf("Username: ");
            tulisKata(USERNAME(sim));
            printf("\n");
            printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
            printf("Waktu: "); displayTimeTitik(t);
            printf("Notifikasi: "); printf("-\n");
            displayMatrix(map); printf("\n");

            printf("Enter Command: ");
            STARTWORD();
            gameval = cmdParser(currentWord);
            printf("\n");
        }
        exitSimulator();
    }else{
        exitSimulator();
    }
    return 0;
}