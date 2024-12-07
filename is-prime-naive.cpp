#include<iostream>
using namespace std;

bool isPrimeNaive(int N){
    // Jika N kurang dari atau sama dengan 1, maka bukan bilangan prima
    if (N <= 1){
        return false;
    }

    // Memeriksa pembagi dari 2 hingga N-1
    for (int i = 2; i < N; i++){
       if(N % i == 0){ // Jika N habis dibagi i, maka bukan bilangan prima
            return false;
       }
    }
    

    // Jika tidak ada pembagi, maka N adalah bilangan prima
    return true;
}

int main() {
    int N;
    
    // Memasukkan input angka
    cout << "Masukkan angka :";
    cin >> N;

    // Memanggil fungsi isPrimeNaive untuk mengecek apakah N adalah bilangan prima
    if (isPrimeNaive(N)){
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

    Algoritma 3: Uji keprimaan dengan melakukan pengecekan dari 2 sampai N-1.
    1: function ISPRIMENAIVE(N)
    2:      if N ≤ 1 then
    3:          return f alse
    4:      end if
    5:      for i ← 2, N −1 do
    6:          if N mod i = 0 then
    7:              return f alse
    8:          end if
    9:      end for
    10:     return true
    11: end function


    Masukkan angka :335
    335 bukan bilangan prima.

    Masukkan angka :337
    337 adalah bilangan prima.

    Masukkan angka :92737
    92737 adalah bilangan prima.

    Masukkan angka: 649657
    649657 adalah bilangan prima.

*/