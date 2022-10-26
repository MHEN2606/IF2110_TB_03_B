#include <stdio.h>
#include <math.h>
#include "wordmachine.h"
#include "charmachine.h"
 
boolean endWord;
Word currentWord;
 
/* KUMPULAN COMMAND */
Word Start = {"START", 5}; //Start lowercase untuk membedakan dengan START
Word EXIT = {"EXIT", 4};
Word BUY = {"BUY", 3};
Word FRY = {"FRY", 3};
Word DELIVERY = {"DELIVERY", 8};
/* KURANG MOVE NORTH/SOUTH/EAST/WEST */
Word MIX = {"MIX", 3};
Word CHOP = {"CHOP", 4};
Word BOIL = {"BOIL", 4};
Word UNDO = {"UNDO", 4};
Word REDO = {"REDO", 4};
Word CATALOG = {"CATALOG", 7};
Word COOKBOOK = {"COOKBOOK", 8};

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}
 
void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        endWord = true;
    }else{
        endWord = false;
        ADVWORD();
    }
}

void STARTCONFIGWORD(char *filename){
    /* Memulai Config dari file */
    startConfig(filename);
    IgnoreBlanks();
    if(currentChar == MARK){
        endWord = true;
    }else{
        endWord = false;
        ADVWORD();
    }
}
 
void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if(currentChar == MARK){
        endWord = true;
    }else{ /*currentChar != MARK */
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVLINE(){
/* Melakukan advancement jika bertemu dengan MARK. endWord diubah menjadi False kembali*/
    if(currentChar == MARK){
        endWord = false;
        ADV();
        CopyWord();
    }
}
 
void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata 'dipotong' */
    int i = 0;
    while(currentChar != BLANK && currentChar != MARK && i < NMax){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

boolean isSameWord(Word w1, Word w2){
/* Membandingkan apakah w1 = w2 */
    if (w1.Length != w2.Length){
        return false;
    }else{
        boolean same = true;
        int i = 0;
        while (same && i < w1.Length){
            if(w1.TabWord[i] != w2.TabWord[i]){
                same = false;
            }else{
                i++;
            }
        }
        return same;
    }
}

int charToInt (Word num){
/* Mengubah char menjadi integer khusus untuk char berupa angka */
    int i;
    int power = 1;
    int number = 0;
    for (i = num.Length-1; i >= 0; i--){
        number += (int)(num.TabWord[i]-48) * power;
        power*=10;
    }
    return number;
}

Word konkatKata(){
/* Melakukan Konkatenasi Kata menjadi satu string 
   Proses: Melakukan ADVKATA hingga MARK
*/
    Word gabung;
    int len = 0;
    while (!endWord){
        for (int i = 0; i < currentWord.Length; i++){
            gabung.TabWord[len] = currentWord.TabWord[i];
            len++;
        }
        if (currentChar == BLANK){
            gabung.TabWord[len] = ' ';
            len++;
            ADV();
            CopyWord();
        }else if (currentChar == MARK){
            endWord = true;
        }
    }
    gabung.Length = len;
    return gabung;
}

void tulisKata(Word w){
/* Menuliskan Kata w */
    for (int i = 0; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
}

void LowerCase(){
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
 
/* F.S. currentword menjadi lowercase di setiap karakternya */
    for (int i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] == 65){
            currentWord.TabWord[i] = 97;
        }else if (currentWord.TabWord[i] == 66){
            currentWord.TabWord[i] = 98;
        }else if (currentWord.TabWord[i] == 67){
            currentWord.TabWord[i] = 99;
        }else if (currentWord.TabWord[i] == 68){
            currentWord.TabWord[i] = 100;
        }else if (currentWord.TabWord[i] == 69){
            currentWord.TabWord[i] = 101;
        }else if (currentWord.TabWord[i] == 70){
            currentWord.TabWord[i] = 102;
        }else if (currentWord.TabWord[i] == 71){
            currentWord.TabWord[i] = 103;
        }else if (currentWord.TabWord[i] == 72){
            currentWord.TabWord[i] = 104;
        }else if (currentWord.TabWord[i] == 73){
            currentWord.TabWord[i] = 105;
        }else if (currentWord.TabWord[i] == 74){
            currentWord.TabWord[i] = 106;
        }else if (currentWord.TabWord[i] == 75){
            currentWord.TabWord[i] = 107;
        }else if (currentWord.TabWord[i] == 76){
            currentWord.TabWord[i] = 108;
        }else if (currentWord.TabWord[i] == 77){
            currentWord.TabWord[i] = 109;
        }else if (currentWord.TabWord[i] == 78){
            currentWord.TabWord[i] = 110;
        }else if (currentWord.TabWord[i] == 79){
            currentWord.TabWord[i] = 111;
        }else if (currentWord.TabWord[i] == 80){
            currentWord.TabWord[i] = 112;
        }else if (currentWord.TabWord[i] == 81){
            currentWord.TabWord[i] = 113;
        }else if (currentWord.TabWord[i] == 82){
            currentWord.TabWord[i] = 114;
        }else if (currentWord.TabWord[i] == 83){
            currentWord.TabWord[i] = 115;
        }else if (currentWord.TabWord[i] == 84){
            currentWord.TabWord[i] = 116;
        }else if (currentWord.TabWord[i] == 85){
            currentWord.TabWord[i] = 117;
        }else if (currentWord.TabWord[i] == 86){
            currentWord.TabWord[i] = 118;
        }else if (currentWord.TabWord[i] == 87){
            currentWord.TabWord[i] = 119;
        }else if (currentWord.TabWord[i] == 88){
            currentWord.TabWord[i] = 120;
        }else if (currentWord.TabWord[i] == 89){
            currentWord.TabWord[i] = 121;
        }else if (currentWord.TabWord[i] == 90){
            currentWord.TabWord[i] = 122;
        }
    }
}