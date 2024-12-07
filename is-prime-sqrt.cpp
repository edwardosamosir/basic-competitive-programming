#include<iostream>
#include <cmath>

using namespace std;

// Fungsi untuk memeriksa apakah suatu bilangan N adalah bilangan prima dengan metode √N
bool isPrimeSqrt(int N){
    // Jika N kurang dari atau sama dengan 1, maka bukan bilangan prima
    if (N <= 1){
        return false;
    }

    // Mulai dengan i = 2, memeriksa pembagi dari 2 hingga √N
    int i = 2;
    while (i * i <= N){ // i*i ekuivalen dengan i ≤ √N
        if (N % i == 0){ // Jika N habis dibagi i, maka bukan bilangan prima
           return false;
        }
        i++;
    }

    // Jika tidak ada pembagi, maka N adalah bilangan prima
    return true;
}

int main() {
    int N;

    // Masukkan input angka
    cout << "Masukkan angka : ";
    cin >> N;

    // Memanggil fungsi isPrimeSqrt untuk mengecek apakah N adalah bilangan prima
    if (isPrimeSqrt(N)) {
        cout << N << " adalah bilangan prima." << endl;
    } else {
        cout << N << " bukan bilangan prima." << endl;
    }

    return 0;
}

/*
    Buku Pemrograman Kompetitif Dasar 
    Panduan Memulai OSN Informatika, ACM-ICPC, dan Sederajat
    Ikatan Alumni TOKI

    Algoritma 4 Uji keprimaan dengan melakukan pengecekan dari 2 sampai √N.
    1: function ISPRIMESQRT(N)
    2:      if N ≤ 1 then
    3:          return f alse
    4:      end if
    5:      i ← 2
    6:      while i×i ≤ N do . Pertidaksamaan ini ekuivalen dengan i ≤√N
    7:          if N mod i = 0 then
    8:              return f alse
    9:          end if
    10:         i ← i+1
    11:     end while
    12:     return true
    13: end function


    Masukkan angka :335
    335 bukan bilangan prima.

    Masukkan angka :337
    337 adalah bilangan prima.

    Masukkan angka :92737
    92737 adalah bilangan prima.

    Masukkan angka: 649657
    649657 adalah bilangan prima.

*/