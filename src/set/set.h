#include <stdio.h>
#include "../boolean/boolean.h"

typedef struct 
{
    int elSet[100];
    int length;
} Set;

#define ELST(S,i) (S).elSet[(i)]
#define LENST(S) (S).length

void createSet(Set *S);
/*Membuat suatu set kosong dengan length = 0*/

boolean isMember(Set S, int x);
/*Mengembalikan true apabila x merupakan anggota
dari set S*/

void insert(Set *S, int x);
/*Memasukkan elemen x ke dalam set S, apabila elemen
x sudah terdapat di S maka akan dilewatkan karena
set terdiri dari elemen unik*/

void deleteElSet(Set *S, int x);
/*Menghapus elemen x di set S*/

void displaySet(Set S);
/*Menampilkan seluruh isi elemen dari set*/

boolean isSubset(Set S1, Set S2);
/*Fungsi mengembalikan true apabila Set 1 merupakan subset
dari Set 2*/

void deleteAllElemen(Set *S);
/*Menghapus semua elemen yang ada di dalam set*/

boolean isEmptySet(Set S);
/*Mengembalikan true jika set kosong*/