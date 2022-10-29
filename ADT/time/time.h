#ifndef TIME_H
#define TIME_H

typedef struct{
    int DD; // DAY
    int HH; // JAM
    int MM; // MENIT
} TIME;

/* *** SELEKTOR *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM

/* *** KONSTRUKTOR *** */
void createTime(TIME *T, int DD, int HH, int MM);
/* Membuat time sembarang */

/* *** BACA/TULIS *** */
void displayTime(TIME T);
/* Menuliskan time T dalam format
    DD.MM.YY (Contoh 1.23).
    Jika nilai satuan waktu = 0, maka tidak dituliskan
*/

void displayTimeTitik(TIME T);
/* Menuliskan time dalam bentuk titik.
    Aturan sama dengan displayTime(TIME T)
*/

/* *** OPERASI KONVERSI *** */
int timeToSecond(TIME T);
/* Mengubah TIME T menjadi detik */

int timeToMinute(TIME T);
/* Mengubah TIME T menjadi menit */

TIME secondToTime(int s);
/* Mengubah detik s menjadi TIME */

/* *** Operasi Penambahan Waktu *** */
TIME addTime(TIME *T, int s);
/* Waktu T ditambah sebanyak detik s */

#endif