/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "charmachine.h"

#define NMax 255
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

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


void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTCONFIGWORD(char *filename);
/* Memulai Konfigurasi dari Word. Melakukan Akuisisi kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVLINE();
/* Melakukan advancement jika bertemu dengan MARK. endWord diubah menjadi False kembali*/

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isSameWord(Word w1, Word w2);
/* Membandingkan apakah w1 = w2 */

int charToInt (Word num);
/* Mengubah char menjadi integer */

char* konkatKata();
/* Melakukan Konkatenasi Kata menjadi satu string 
   Proses: Melakukan ADVKATA hingga MARK
*/

void LowerCase();
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */

#endif