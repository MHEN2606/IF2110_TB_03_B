#include <stdio.h>
#include "charmachine.c"
#include "wordmachine.c"

int main(){
    STARTCONFIGWORD("../konfigurasi/map.txt");

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf(" ");

    ADVWORD();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");

    ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
     ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
    
    ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");

    ADVLINE();

    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }

    printf("\n");
    ADVLINE();
    return 0;
}