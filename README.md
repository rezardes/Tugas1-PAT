# Tugas1-PAT
### Deskripsi Tugas
Mengimplementasikan dan Mengukur Kinerja Simple Web Server
Tugas ini menggunakan library libevent
### Instalasi Libevent
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
