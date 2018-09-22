# Tugas1-PAT
### Deskripsi Tugas
Mengimplementasikan dan Mengukur Kinerja Simple Web Server
Tugas ini menggunakan library libevent
### Instalasi Libevent
<<<<<<< HEAD
1) Download libevent lastest stable from sourceforge https://sourceforge.net/projects... , it’s 2.0.22-stable at this time.

2) after downloaded, go to folder where you saved it, extract the archive:
$ tar -xzvf libevent*.tar.gz

3) Create the makefile:

    $ cd libevent-2.0.22-stable

$ ./configure --prefix=/opt/libevent

4) Compile the sources:
$ make

5) Install the application and clean up:
$ make install && make clean

This will compile and install it in /opt/libevent. You should have libevent installed in /opt/libevent if no errors occurred. To make sure:

    $ ls -la /opt/libevent 
=======
1) Download libevent terbaru:
https://sourceforge.net/projects/levent/files/latest/download

2) Extract arsip
```
$ tar -xzvf libevent*.tar.gz
```

3) Buat makefile:
```
$ cd libevent-2.0.22-stable
$ ./configure --prefix=/opt/libevent
```

4) Kompilasi source code
```
$ make
```
5) Install aplikasi dan clean up
```
$ make install && make clean
```
6) Cek apakah libevent sudah terinstall
```
$ ls -la /opt/libevent
```
**Catatan:** lihat apakah sudah ada informasi direktori terkait 
>>>>>>> 7e37176145c84f5b1a881bb8e75c4e6927247f2e
### Langkah Menjalankan Server
1) Kompilasi Server
```
$ g++ -o server server.cpp -levent
```
2) Menjalankan Server
```
$ ./server
```
3) Buka alamat URL berikut untuk membuka file html terkait:
```
http://localhost:8003/tes1
http://localhost:8003/tes2
```
### Kalau Segmentation Fault, Kill Port
1) Lihat port apa yang sedang berjalan
```
$ netstat --listen
```
2) Kill port
```
$ fuser -k <port>/tcp
```
