#include <stdio.h>
#include "./simulator/simulator.h"

int main(){
    ListStatik fd;
    POINT awal;
    Matrix map;
    SIMULATOR sim;
    TIME t;
    char command[50];

    splashScreen();

    printf("Enter START/EXIT: ");
    scanf("%s", command);
    int startval = cmdParser(command);

    while (startval == 0 || (startval >= 3 && startval <= 12))
    {
        printf("Perintah tidak valid! Silakan Ulangi!\n");
        printf("START/EXIT: ");
        scanf("%s", command);
        startval = cmdParser(command);
    }

    if (startval == 1)
    {
        startSimulator(&sim, &map, &awal, &fd);
        createTime(&t, 0,0,0);

        printf("Username: %s\n", USERNAME(sim));
        printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
        printf("Waktu: %d.%d\n", Hour(t), Minute(t));
        displayMatrix(map); printf("\n");

        printf("Enter Command: ");
        scanf("%s", command);
        int gameval = cmdParser(command);
        printf("\n");

        while(gameval != 2){
            if (gameval == 0 || gameval == 1)
            {
                printf("Perintah tidak valid! Silakan ulangi\n");
            }

            /* PERINTAH YANG BERKAITAN DENGAN MAKANAN (KHUSUS UNTUK MENAMBAH WAKTU)
            DIJALANKAN DI SINI. JUGA YANG MEMANIPULASI WAKTU*/
            if(gameval == 19)
            {
                printf("PERINTAH WAIT\n");
            }

            /* PERINTAH MOVE DIJALANKAN DI SINI */
            if (gameval == 14) 
            {
                /* COMMAND 'MOVE' diterima, parse command arah */
                char arah[50];
                scanf("%s", arah);
                int gerak = cmdParser(arah);
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
                    }else{
                        /* MOVE WEST*/
                    }
                }
            }

            printf("Username: %s\n", USERNAME(sim));
            printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
            printf("Waktu: %d.%d\n", Hour(t), Minute(t));
            displayMatrix(map); printf("\n");

            /* PERINTAH YANG BERKAITAN DENGAN MAKANAN DIJALANKAN DI SINI */
            if(gameval == 3)
            {
                printf("PERINTAH BUY\n");
            }
            else if(gameval == 4)
            {
                printf("PERINTAH FRY\n");
            }
            else if(gameval == 7)
            {
                printf("PERINTAH CHOP\n");
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
            }

            printf("Enter Command: ");
            scanf("%s", command);
            gameval = cmdParser(command);
            printf("\n");
        }
        printf("SEE YOU NEXT TIME :)\n");
    }else{
        printf("SEE YOU NEXT TIME :)\n");
    }
    return 0;
}