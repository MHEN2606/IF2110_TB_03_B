# IF2110_TB_03_B
Tugas Besar Algoritma Struktur Data

Simulator Memasak BNMO

# Anggota Kelompok
| Nama | NIM |
| ----------- | ----------- |
| Matthew Mahendra | 13521007 |
| Henry Anand Septian Radityo | 13521004 |
| Syarifa Dwi Purnamasari | 13521018 |
| Eunice Sarah Siregar | 13521013 |
| Kartini Copa | 13521026
| Varraz Hazzandra Abrar | 13521020|

# Deskripsi Program
Simulator Memasak BNMO merupakan sebuah simulator memasak. Program ini dapat membuat
simulasi memasak dari berbagai makanan seperti melakukan aksi potong, aksi merebus,
aksi menggoreng, dll. Program ini berbasis bahasa C.
# Run Program tanpa GCC
1. Pergi ke direkotori src. 
2. Untuk pengguna dengan sistem operasi windows cukup run file `main.exe` untuk menjalankan program dan untuk pengguna dengan sistem operasi linux cukup run file `main.out` untuk menjalankan program.
# Instalasi dengan GCC
1. Pastikan pada OS Anda sudah terpasang gcc
2. Lakukan <i>change directory</i> ke src dengan cara `cd src`
3. Jalankan perintah ini

``` 
gcc -c "./simulator/simulator.c" -o simulator.o
gcc -c "./liststatik/liststatik.c" -o liststatik.o
gcc -c "./charmachine/charmachine.c" -o charmachine.o
gcc -c "./wordmachine/wordmachine.c" -o wordmachine.o
gcc -c "./food/food.c" -o food.o
gcc -c "./time/time.c" -o time.o
gcc -c "./matrix/matrix.c" -o matrix.o
gcc -c "./point/point.c" -o point.o
gcc -c "./prioqueuetime/prioqueuetime.c" -o prioqueuetime.o
gcc -c "./stack/stack.c" -o stack.o
gcc -c "./tree/tree.c" -o tree.o
gcc -c "./set/set.c" -o set.o
gcc -c "./kulkas/kulkas.c" -o kulkas.o
gcc main.c liststatik.o charmachine.o wordmachine.o food.o time.o simulator.o matrix.o point.o prioqueuetime.o stack.o tree.o kulkas.o set.o
```

4. Pada windows, jalankan perintah `./a` untuk menjalankan. Pada linux, `./a.out`

# Pembagian Tugas
| Nama                           |   NIM    |                                         Workload management                                                   |
| ------------------------------ | :------: | :-----------------------------------------------------------------------------------------------------------------: |
| Matthew Mahendra   | 13521007 | ADT Food, ADT Simulator, Command Parser, Inisiasi (START/EXIT, Splash Screen), Undo, Inventory, Catalog, Buy, Main File, Konfigurasi Food dari file, Modifikasi Charmachine dan Wordmachine, Bonus 1, Bonus 2|
| Henry Anand Septian Radityo  | 13521004 |Pengurangan waktu pada inventory dan delivery, Waktu yang bertambah pada BNMO, Wait, ADT Tree, Inventory, Konfigurasi resep dari file, Cookbook, Bonus 3 |
| Syarifa Dwi Purnamasari | 13521013 | Move North, Move south, Pengurangan waktu pada inventory dan delivery, Konfigurasi resep dari peta, Chop, Mix |
| Eunice Sarah Siregar | 13521018 |Notifikasi, ADT Tree, Fungsi ‘Cek if is adjacent’, Fry, Redo |
| Kartini Copa| 13521026 | Notifikasi, Buy, Delivery, Catalog, CookBook |
| Varraz Hazzandra Abrar| 13521020 | Move west, move east, Waktu yang bertambah pada BNMO, Boil, Redo|

# Alur Program
Ketika memulai program, akan diberikan splash screen. Lalu diminta untuk menjalankan START/EXIT. Ketikkan
kata 'START' untuk memulai dan 'EXIT' untuk keluar program. Setelahnya akan diminta username pada program.

Setelah memasukkan username, program sudah dapat dijalankan. Ada beberapa perintah yang dapat dipanggil
1. `Move East/West/North/South` untuk bergerak pada peta
2. `Buy` untuk membeli makanan
3. `Fry` untuk menggoreng makanan
4. `Chop` untuk memotong makanan
5. `Mix` untuk mencampur makanan
6. `Boil` untuk merebus makanan
7. `Undo` untuk melakukan undo
8. `Redo` untuk melakukan redo
9. `Wait x y` untuk menambah waktu sebanyak x jam dan y menit
10. `Catalog` untuk melihat catalog makanan
11. `Inventory` untuk melihat makanan pada inventory
12. `Delivery` untuk melihat makanan yang sedang diantar
13. `Cookbook` untuk melihat resep makanan
14. `Exit` untuk keluar dari program

Adapun tambahan seperti
1. `Kulkas` untuk melihat sebuah kulkas dimana waktu kedaluwarsa dari makanan tidak berlaku jika makanan dimasukkan ke kulkas
2. `Rekomendasi` untuk melihat daftar makanan yang dapat dibuat berdasarkan makanan yang dimiliki di inventory

Perintah yang diinput tidak case-sensitive dan untuk perintah nomor 2-6, harus dilakukan pada lokasi yang bertetanggaan dengan simbolnya pada peta. `BUY` dapat dilakukan di simbol `T`, `MIX` dapat dilakukan di simbol `M`, `CHOP` dapat dilakukan di simbol `C`, `FRY` dapat dilakukan di simbol `F`, dan `BOIL` dapat dilakukan di simbol `B`

Untuk setiap perintah yang berhasil dijalankan, maka waktu pada program bertambah. Waktu pada program akan memengaruhi waktu pengantaran dan waktu kedaluwarsa tiap makanan. Untuk setiap makanan yang sudah selesai diantar dan kedaluwarsa, program akan mengirimkan notifikasi.


# Daftar Fitur dan Status Pengerjaan
| Fitur | Status |
| ----------- | ----------- |
| Splash Screen | Selesai |
| START | Selesai |
| Move | Selesai |
| Buy | Selesai |
| Chop | Selesai |
| Mix | Selesai |
| Fry | Selesai
| Boil | Selesai |
| Undo | Selesai |
| Redo | Selesai |
| Wait | Selesai |
| Catalog | Selesai |
| Inventory | Selesai |
| Delivery | Selesai |
|Cookbook | Selesai |
| Kulkas | Selesai |
| Rekomendasi | Selesai |
| Exit | Selesai |

