#include <stdio.h>
#include "time.h"

/* *** KONSTRUKTOR *** */
void createTime(TIME *T, int DD, int HH, int MM){
/* Membuat time sembarang */
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* *** BACA/TULIS *** */
void displayTime(TIME T){
/* Menuliskan time T dalam format
    DD Hari MM Jam YY Menit (Contoh 1 Jam 2 Menit).
    Jika nilai satuan waktu = 0, maka tidak dituliskan
*/
    if(Day(T) == 0 && Hour(T) != 0){
        printf("%d Jam %d Menit\n", Hour(T), Minute(T));
    }else if(Hour(T) == 0 && Day(T) == 0){
        printf("%d Menit\n", Minute(T));
    }else{
        printf("%d Hari %d Jam %d Menit\n", Day(T), Hour(T), Minute(T));
    }
}

void displayTimeTitik(TIME T){
/* Menuliskan time dalam bentuk titik.
    Aturan sama dengan displayTime(TIME T)
*/
    if(Day(T) == 0 && Hour(T) != 0){
        printf("%d.%d\n", Hour(T), Minute(T));
    }else if(Hour(T) == 0 && Day(T) == 0){
        printf("0.%d\n", Minute(T));
    }else{
        printf("%d.%d.%d\n", Day(T), Hour(T), Minute(T));
    }
}

/* *** OPERASI KONVERSI *** */
int timeToSecond(TIME T){
/* Mengubah TIME T menjadi detik */
    return (Minute(T) * 60 + Hour(T) * 3600 + Day(T) * 3600 * 24);
}

int timeToMinute(TIME T){
/* Mengubah TIME T menjadi menit */
    return(Minute(T) + Hour(T) * 60 + Day(T) * 60 * 24);
}

TIME secondToTime(int s){
/* Mengubah detik s menjadi TIME */
    TIME T;
    int d,h,m,sisa;
    d = s/(3600 * 24);
    sisa = s % (3600*24);
    h = sisa/3600;
    m = (sisa % 3600) / 60;
    createTime(&T,d,h,m);
    return T;
}

/* *** Operasi Penambahan Waktu *** */
TIME addTime(TIME *T, int s){
/* Waktu T ditambah sebanyak detik s, mengembalikan sebuah
time baru yang sudah ditambah sebanyak s detik */
    TIME newTime;
    int sekon;
    sekon = timeToSecond(*T);
    sekon += s;
    newTime = secondToTime(sekon);
    return newTime;
}

TIME reduceTime(TIME *T, int s){
/* Waktu T dikurang sebanyak detik s */
    TIME newTime;
    int sekon;
    sekon = timeToSecond(*T);
    sekon -= s;
    newTime = secondToTime(sekon);
    return newTime;
}