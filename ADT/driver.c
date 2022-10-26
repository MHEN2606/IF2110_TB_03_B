#include <stdio.h>
#include "simulator.h"

int main(){
    ListStatik fd;
    POINT awal;
    Matrix map;
    SIMULATOR sim;
    char command[50];

    splashScreen();

    printf("START/EXIT: ");
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
        printf("Posisi: "); tulisPoint(POSISI(sim));
        displayMatrix(map); printf("\n");

        printf("Command: ");
        scanf("%s", command);
        int gameval = cmdParser(command);

        while(gameval != 2){
            if (gameval == 0 || gameval == 1){
                printf("Perintah tidak valid! Silakan ulangi\n");
            }
            printf("Username: %s\n", USERNAME(sim));
            printf("Posisi: "); tulisPoint(POSISI(sim));
            displayMatrix(map); printf("\n");

            /* DO SOMETHING HERE */
            if(gameval == 3){
                printf("PERINTAH BUY GES\n");
            }

            printf("Command: ");
            scanf("%s", command);
            gameval = cmdParser(command);
        }
        printf("SEE YOU NEXT TIME :)\n");
    }else{
        printf("SEE YOU NEXT TIME :)\n");
    }
    return 0;
}