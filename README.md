# Tugas1-PAT
### Deskripsi Tugas
Mengimplementasikan dan Mengukur Kinerja Simple Web Server
### Langkah Menjalankan Server
1) Kompilasi Server
```
$ g++ -o server server.cpp
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