#include <stdio.h>
#include "./simulator/simulator.h"
int main(){
    ListStatik fd, resep, notification;
    POINT awal;
    Matrix map;
    SIMULATOR sim;
    TIME t;
    STACK commands, poppedCommands;
    PrioQueueTime delivery;
    Kulkas kulkas;

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
        createNotificationList(&notification);
        createEmptyStack(&commands);
        createEmptyStack(&poppedCommands);
        createKulkas(&kulkas);

        printf("\n");
        printf("Username: ");
        tulisKata(USERNAME(sim));
        printf("\n");
        printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
        printf("Waktu: "); displayTimeTitik(t);
        displayNotif(&notification);printf("\n");
        displayMatrix(map); printf("\n");

        printf("Enter Command: ");
        STARTWORD();
        int gameval = cmdParser(currentWord);
        printf("\n");

        while(gameval != 2){
            /*rTime untuk mengurangi waktu pada Queue delivery dan Queue Inventory*/
            int rTime;
            rTime = 0;
            int nambah;
            nambah = 0;
            if (gameval == 0 || gameval == 1)
            {
                printf("Perintah tidak valid! Silakan ulangi\n");
            }
            else
            {
                /* CEK APAKAH STACK UNDO DAN REDO SUDAH PENUH */
                if(isFull(commands))
                {
                    clearStack(&commands);
                }
                if(isFull(poppedCommands))
                {
                    clearStack(&poppedCommands);
                }

                /* BAGIAN PERINTAH BNMO */
                if(gameval == 9)
                {
                    undo(&commands, &poppedCommands, &sim, &map, &delivery, fd, &t, resep);
                }
                if(gameval == 10)
                {
                    redo(&poppedCommands, &commands, &sim, &map, &delivery, fd, &t, resep);
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
                    if(isAdjacent(POSISI(sim), map, 'T'))
                    {
                        int length = NBElmt(delivery);
                        buy(&delivery, fd);
                        length = NBElmt(delivery) - length;
                        Push(&commands, length); // push berapa elemen yang ditambahkan
                        Push(&commands, gameval);
                        t = addTime(&t,60);
                        rTime += 60;
                    }
                    else
                    {
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 4)
                {
                    if(isAdjacent(POSISI(sim), map, 'F'))
                    {
                        fry(resep, fd, &INV(sim), &nambah);
                        Push(&commands, gameval);
                        t = addTime(&t,nambah);
                        rTime += nambah;
                    }
                    else
                    {
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 7)
                {
                    if(isAdjacent(POSISI(sim), map, 'C'))
                    {
                        chop(resep, fd, &INV(sim), &nambah);
                        Push(&commands, gameval);
                        t = addTime(&t,nambah);
                        rTime += nambah;
                    }
                    else
                    {
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 8)
                {
                    if(isAdjacent(POSISI(sim), map, 'B'))
                    {
                        boil(resep, fd, &INV(sim), &nambah);
                        Push(&commands, gameval);
                        t = addTime(&t,nambah);
                        rTime += nambah;
                    }
                    else
                    {
                        printf("Anda tidak berada di area command!\n");
                    }
                }
                else if(gameval == 6)
                {
                    if(isAdjacent(POSISI(sim), map, 'M'))
                    {
                        mix(resep, fd, &INV(sim), &nambah);
                        Push(&commands, gameval);
                        t = addTime(&t,nambah);
                        rTime += nambah;
                    }
                    else
                    {
                        printf("Anda tidak berada di area command!\n");
                    }
                }

                /* Catalog */
                if(gameval == 11)
                {
                    printf("List Makanan\n");
                    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
                    displayList(fd);printf("\n");
                    // Push(&commands, gameval);
                }
                /* Buku Resep */
                if(gameval == 12)
                {
                    bukuResep(resep,fd);
                    // Push(&commands, gameval);
                }
                /* Delivery */
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
                    // Push(&commands, gameval);
                }

                /* Inventory */
                if(gameval == 13)
                {
                    printf("List Makanan di Inventory\n");
                    printf("(nama - waktu sisa kedaluwarsa)\n");
                    if(IsEmpty(INV(sim)))
                    {
                        printf("Inventory Kosong. Silakan melakukan BUY\n");
                    }
                    else
                    {
                        PrintInventory(INV(sim));
                        printf("\n");
                    }
                    // Push(&commands, gameval);
                }

                /* Kulkas */
                if(gameval == 22)
                {
                    ProcKulkas(&kulkas, &INV(sim));
                }
                /*Cek Rekomendasi*/
                if (gameval == 23)
                {
                    Set setinv;
                    Set tempSet;
                    ListStatik map;
                    Word tempOut;
                    boolean valid;
                    int count = 0;
                    valid = false;
                    createSet(&setinv);
                    createMap(&map);
                    makeMapOfResep(resep,&map);
                    makeSetOfInv(&setinv,INV(sim));
                    //DEBUG
                    // displaySet(setinv);
                    // displaySet(SET(MINFO(map,1)));
                    // displaySet(SET(MINFO(map,0)));
                    printf("List Makanan yang dapat dibuat : \n");
                    //For dilakukan dua kali untuk mengatasi depth yang banyak
                    for (int j = 0; j<NEFF(map);j++)
                    {
                        for (int i = 0 ;i<NEFF(map);i++)
                        {
                            if (isSubset(SET(MINFO(map,i)),setinv))
                            {
                                insert(&setinv,KEY(MINFO(map,i)));
                            }
                        }
                    }
                    for (int i = 0 ;i<NEFF(map);i++)
                    {
                        if (isSubset(SET(MINFO(map,i)),setinv))
                        {
                            count++;
                            tempOut = findFdName(KEY(MINFO(map,i)),fd);
                            printf("    %d. ",count);
                            tulisKata(tempOut);
                            printf("\n");
                            valid = true;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n");
                        printf("    Tidak ada makanan yang dapat dibuat\n");
                        printf("    ~Harap membeli bahan terlebih dahulu~\n");
                    }
                }
                /*UPDATE QUEUE INVENTORY & DELIVERY*/
                reduceExpTime(&INV(sim),&commands,rTime, &notification);
                reduceDelTime(&delivery, &INV(sim), &commands, rTime,&notification);

                /* Cek apakah command yang diberikan sama dengan top dari redo.
                Jika berbeda, maka redo dikosongkan */
                if(gameval != 9 && gameval != 10)
                {
                    if(TOP(poppedCommands) != gameval)
                        clearStack(&poppedCommands);
                }
            }
            
            printf("\n");

            printf("Username: ");
            tulisKata(USERNAME(sim));
            printf("\n");
            printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
            printf("Waktu: "); displayTimeTitik(t);
            displayNotif(&notification);printf("\n");
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