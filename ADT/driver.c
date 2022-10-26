#include <stdio.h>
#include "simulator.h"

int main(){
    ListStatik fd;
    POINT awal;
    Matrix map;
    SIMULATOR sim;
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

    if (startval == 1){
        startSimulator(&sim, &map, &awal, &fd);

        printf("Username: %s\n", USERNAME(sim));
        printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
        displayMatrix(map); printf("\n");

        printf("Enter Command: ");
        scanf("%s", command);
        int gameval = cmdParser(command);

        while(gameval != 2){
            if (gameval == 0 || gameval == 1){
                printf("Perintah tidak valid! Silakan ulangi\n");
            }else{
                /* Lakukan pengurangan/penambahan waktu 
                Manipulasi terhadap Inventory dan beberapa hal
                lainnya */
            }
            printf("Username: %s\n", USERNAME(sim));
            printf("BNMO di Posisi: "); tulisPoint(POSISI(sim));
            displayMatrix(map); printf("\n");

            /* DO SOMETHING HERE */
            if(gameval == 3){
                printf("PERINTAH BUY GES\n");
            }
            
            if(gameval == 13){ // COMMAND INVENTORY
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
        }
        printf("SEE YOU NEXT TIME :)\n");
    }else{
        printf("SEE YOU NEXT TIME :)\n");
    }
    return 0;
}