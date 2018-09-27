# Tugas1-PAT
### Deskripsi Singkat Tugas
Kami ditugasi mengimplementasikan dan mengukur kinerja simple web server
Tugas ini menggunakan library libevent
Tools pengukuran kinerja yang digunakan adalah Apache Benchmarking Tool dan Siege

## Persoalan Pertama
Terdapat server menggunakan apache atau nginx. Tugas berupa pengukuran kinerja akses file html pada server tersebut.
Kinerja yang diukur adalah berapa waktu respon rerata dan memori yang digunakan pada saat terjadi 1000 concurrent request untuk akses masing-masing 2 file html berbeda. 2 file HTML berbeda tersebut berukuran ~500 bytes dan ~20kB. File berukuran paling kecil bernama tes1.html sedangkan tes2.html berukuran yang paling besar.

Kami melalukan pengujian dengan server apache.

### Hasil Pengukuran Kinerja
Untuk ***10000 concurrent request***, server apache tidak dapat menampung request tersebut.
#### Apache Benchmarking Tool
Server socket tidak dapat menangani open file yang banyak
```
This is ApacheBench, Version 2.3 <$Revision: 1826891 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking localhost (be patient)
socket: Too many open files (24)
```
#### Siege
Pengujian melalui siege tidak dapat dilakukan karena resource tidak cukup tersedia
```
[error] Inadequate resources to create pool crew.c:87: Resource temporarily unavailable
[fatal] unable to allocate memory for 10000 simulated browser: Resource temporarily unavailable
```
Namun, untuk ***1000 concurrent request***, server apache dapat mengelola request tersebut.
<br>a) file html ~500 bytes (tes1.html)
#### Apache Benchmarking Tool
```
This is ApacheBench, Version 2.3 <$Revision: 1826891 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking localhost (be patient)


Server Software:        Apache/2.4.33
Server Hostname:        localhost
Server Port:            80

Document Path:          /tes1.html
Document Length:        537 bytes

Concurrency Level:      1000
Time taken for tests:   10.726 seconds
Complete requests:      49328
Failed requests:        86
   (Connect: 0, Receive: 0, Length: 86, Exceptions: 0)
Keep-Alive requests:    48781
Total transferred:      43115912 bytes
HTML transferred:       26442954 bytes
Requests per second:    4599.12 [#/sec] (mean)
Time per request:       217.433 [ms] (mean)
Time per request:       0.217 [ms] (mean, across all concurrent requests)
Transfer rate:          3925.72 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1  35.9      0    1037
Processing:     0   32 387.0      2    8783
Waiting:        0   26 335.3      2    8783
Total:          0   34 408.4      2    9795

Percentage of the requests served within a certain time (ms)
  50%      2
  66%      2
  75%      2
  80%      2
  90%      3
  95%      4
  98%     17
  99%    426
 100%   9795 (longest request)
```
#### SIEGE
```
Transactions:		       10000 hits
Availability:		      100.00 %
Elapsed time:		       11.64 secs
Data transferred:	        5.12 MB
Response time:		        0.12 secs
Transaction rate:	      859.11 trans/sec
Throughput:		        0.44 MB/sec
Concurrency:		       99.95
Successful transactions:       10000
Failed transactions:	           0
Longest transaction:	        2.02
Shortest transaction:	        0.00
```
<br>b) file html ~20 kB (tes2.html)
#### Apache Benchmarking Tool
```
This is ApacheBench, Version 2.3 <$Revision: 1826891 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking localhost (be patient)


Server Software:        Apache/2.4.33
Server Hostname:        localhost
Server Port:            80

Document Path:          /tes2.html
Document Length:        20072 bytes

Concurrency Level:      1000
Time taken for tests:   10.158 seconds
Complete requests:      49259
Failed requests:        41
   (Connect: 0, Receive: 0, Length: 41, Exceptions: 0)
Keep-Alive requests:    48739
Total transferred:      1004715384 bytes
HTML transferred:       987903696 bytes
Requests per second:    4849.19 [#/sec] (mean)
Time per request:       206.220 [ms] (mean)
Time per request:       0.206 [ms] (mean, across all concurrent requests)
Transfer rate:          96588.78 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1  38.1      0    1020
Processing:     0   32 431.0      0    9132
Waiting:        0   30 414.0      0    9132
Total:          0   34 457.0      0   10153

Percentage of the requests served within a certain time (ms)
  50%      0
  66%      0
  75%      0
  80%      0
  90%      1
  95%      1
  98%      2
  99%    361
 100%  10153 (longest request)
```
#### Siege
```
Transactions:		       10000 hits
Availability:		      100.00 %
Elapsed time:		       10.22 secs
Data transferred:	      191.42 MB
Response time:		        0.05 secs
Transaction rate:	      978.47 trans/sec
Throughput:		       18.73 MB/sec
Concurrency:		       48.65
Successful transactions:       10000
Failed transactions:	           0
Longest transaction:	        1.27
Shortest transaction:	        0.00
```

## Persoalan Kedua
Terdapat server yang harus dibuat dengan pemrograman C++. Server dibuat dengan library low-level. Kami menggunakan library libevent untuk menyelesaikan persoalan tersebut. Server yang dibuat harus diukur kinerjanya sama seperti persoalan pertama.

### Instalasi Libevent
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
6) Cek apakah libevent sudah terinstall dengan melihat informasi direktori terkait
```
$ ls -la /opt/libevent
```

### Langkah Menjalankan Server
1) Make Clean terlebih dahulu
```
$ make clean
```
2) Lalu kompilasi dengan make
```
$ make
```
3) Kemudian, jalankan Server
```
$ ./server
```
4) Buka alamat URL berikut untuk membuka file html terkait:
```
http://localhost:8003/tes1
http://localhost:8003/tes2
```
### Kalau Segmentation Fault, Kill Port
1) Lihat port apa yang sedang berjalan
```
$ netstat --listen
```
2) Kalau misalnya port untuk server terpakai, kill port
```
$ fuser -k <port>/tcp
```
***Catatan:*** Port yang dipakai adalah 8083

### Hasil Pengukuran Kinerja
Setelah kami melakukan request sebanyak 10000 concurrent request, ternyata server tidak dapat menampung request tersebut.
Dari server terdapat error sebagai berikut:

Dari apache benchmarking tool, error yang tampil adalah sebagai berikut ketika mengakses kedua file:
![10000_request](Screenshot/10000_request.png)

Dari siege, error yang tampil adalah sebagai berikut:
a) akses tes1.html 10000 concurrent request (~500 bytes)<br>
![10000_siege_tes1](Screenshot/10000_siege_tes1.JPG)
<br>b) akses tes2.html 10000 concurrent request (~20 kB)<br>
![10000_siege_tes2](Screenshot/10000_siege_tes2.png)

Namun, akses kedua file html tersebut dengan 1000 concurrent request mungkin dilakukan.

a) akses tes1.html 1000 concurrent request (~500 bytes)
#### Apache Benchmarking Tool
```
This is ApacheBench, Version 2.3 <$Revision: 1826891 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking 127.0.0.1 (be patient)


Server Software:        
Server Hostname:        127.0.0.1
Server Port:            8003

Document Path:          /tes1
Document Length:        600 bytes

Concurrency Level:      1000
Time taken for tests:   1.883 seconds
Complete requests:      50000
Failed requests:        48662
   (Connect: 0, Receive: 0, Length: 48662, Exceptions: 0)
Keep-Alive requests:    50000
Total transferred:      6155476 bytes
HTML transferred:       802800 bytes
Requests per second:    26559.62 [#/sec] (mean)
Time per request:       37.651 [ms] (mean)
Time per request:       0.038 [ms] (mean, across all concurrent requests)
Transfer rate:          3193.11 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   3.1      0      43
Processing:     9   36   3.8     37      43
Waiting:        0   36   3.8     37      43
Total:          9   37   3.3     37      57

Percentage of the requests served within a certain time (ms)
  50%     37
  66%     38
  75%     38
  80%     38
  90%     40
  95%     41
  98%     41
  99%     49
100% 57 (longest request)
```
#### Siege
![1000_siege_tes1](Screenshot/1000_siege_tes1.JPG)

b) akses tes2.html 10000 concurrent request (~20 kB)
#### Apache Benchmarking Tool
```
This is ApacheBench, Version 2.3 <$Revision: 1826891 $>
Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
Licensed to The Apache Software Foundation, http://www.apache.org/

Benchmarking 127.0.0.1 (be patient)


Server Software:        
Server Hostname:        127.0.0.1
Server Port:            8003

Document Path:          /tes2
Document Length:        20100 bytes

Concurrency Level:      1000
Time taken for tests:   1.963 seconds
Complete requests:      50000
Failed requests:        49105
   (Connect: 0, Receive: 0, Length: 49105, Exceptions: 0)
Keep-Alive requests:    50000
Total transferred:      23343080 bytes
HTML transferred:       17989500 bytes
Requests per second:    25466.03 [#/sec] (mean)
Time per request:       39.268 [ms] (mean)
Time per request:       0.039 [ms] (mean, across all concurrent requests)
Transfer rate:          11610.46 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   2.9      0      40
Processing:     9   38   5.1     38      87
Waiting:        0   37   3.3     38      48
Total:         10   38   4.6     38      87

Percentage of the requests served within a certain time (ms)
  50%     38
  66%     38
  75%     39
  80%     39
  90%     40
  95%     41
  98%     52
  99%     60
100% 87 (longest request)
```
#### Siege
![1000_siege_tes2](Screenshot/1000_siege_tes2.JPG)
