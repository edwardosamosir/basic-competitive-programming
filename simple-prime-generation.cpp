#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// Fungsi untuk memeriksa apakah suatu bilangan N adalah bilangan prima dengan metode √N
bool isPrimeSqrt(int N){ 
    if(N <= 1) {
        return false;
    }

    int i = 2;
    while (i * i <= N){ // i * i ekuivalen dengan i ≤ √N
        if (N % i == 0){ // Jika N habis dibagi i, maka bukan bilangan prima
            return false;
        }
        i++;
    }

    return true; // Jika tidak ada pembagi, maka N adalah bilangan prima
}

// Fungsi untuk menghasilkan daftar bilangan prima hingga N
vector<int> simplePrimeGeneration(int N){ 
    vector<int> primeList;

    // Iterasi dari 2 hingga N
    for (int i = 2; i <= N; i++){
        if (isPrimeSqrt(i)){ // Jika i adalah bilangan prima, tambahkan ke primeList
            primeList.push_back(i);
        }
    }
    return primeList; // Mengembalikan daftar bilangan prima
}

int main() {
    int N;
    
    // Memasukkan input angka N
    cout << "Masukkan angka N untuk menghasilkan bilangan prima hingga N:";
    cin >> N;

    // Menghasilkan bilangan prima hingga N
    vector<int> primes = simplePrimeGeneration(N);

    // Menampilkan bilangan prima yang dihasilkan
    cout << "Bilangan prima hingga " << N << " adalah: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

/*
    Buku Pemrograman Kompetitif Dasar 
    Panduan Memulai OSN Informatika, ACM-ICPC, dan Sederajat
    Ikatan Alumni TOKI
    
    Algoritma 5 Pembangkitan Bilangan Prima dengan iterasi dan uji keprimaan.
    1: function SIMPLEPRIMEGENERATION(N)
    2:      primeList ← {}
    3:      for i ← 2, N do
    4:          if ISPRIMESQRT(i) then
    5:              primeList ← primeList ∪ {i}
    6:          end if
    7:      end for
    8:      return primeList
    9: end function

    contoh input dan output :

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:10
    Bilangan prima hingga 10 adalah: 2 3 5 7 

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:20
    Bilangan prima hingga 20 adalah: 2 3 5 7 11 13 17 19 

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:100
    Bilangan prima hingga 100 adalah: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
*/