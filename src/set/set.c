#include "set.h"

void createSet(Set *S)
/*Membuat suatu set kosong dengan length = 0*/
{
    LENST(*S) = 0;
}
void insert(Set *S, int x)
/*Memasukkan elemen x ke dalam set S, apabila elemen
x sudah terdapat di S maka akan dilewatkan karena
set terdiri dari elemen unik*/
{
    if (!isMember(*S,x))
    {
        ELST(*S,LENST(*S)) = x;
        LENST(*S)++;
    }
}
boolean isMember(Set S, int x)
/*Mengembalikan true apabila x merupakan anggota
dari set S*/
{
    for (int i = 0; i<LENST(S) ; i++)
    {
        if(ELST(S,i)==x)
        {
            return true;
        }
    }
    return false;
}

void deleteElSet(Set *S, int x)
/*Menghapus elemen x di set S*/
{
    boolean valid = false; 
    int i = 0;
    while (i<LENST(*S) && !valid)
    {
        if (ELST(*S,i)==x)
        {
            ELST(*S,i) = ELST(*S,LENST(*S)-1);
            LENST(*S)--;
            valid = true;
        }
        i++;
    }
}
void displaySet(Set S)
/*Menampilkan seluruh isi elemen dari set*/
{
    printf("{");
    if(!isEmptySet(S))
    {
        for (int i = 0; (i<LENST(S)-1);i++)
        {
            printf("%d,",ELST(S,i));
        }
        printf("%d",ELST(S,LENST(S)-1));
    }
    printf("}");
}

boolean isSubset(Set S1, Set S2)
/*Fungsi mengembalikan true apabila Set 1 merupakan subset
dari Set 2*/
{
    for (int i = 0; i<LENST(S1);i++)
    {
        if (!isMember(S2,ELST(S1,i)))
        {
            return false;
        }
    }
    return true;
}

boolean isEmptySet(Set S)
/*Mengembalikan true jika set kosong*/
{
    return (LENST(S)==0);
}