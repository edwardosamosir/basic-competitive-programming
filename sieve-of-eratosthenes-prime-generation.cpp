#include<iostream>
#include<vector>

using namespace std;

// Fungsi untuk menghasilkan semua bilangan prima hingga N menggunakan algoritma Sieve of Eratosthenes
vector<long long> sieveOfEratosthenes(long long N) {
    if (N < 2) return vector<long long>();

    // Vector boolean untuk menandai angka-angka yang sudah dieliminasi (bukan prima)
    vector<bool> eliminated(N + 1, false); // Inisialisasi vector dengan ukuran N+1, semua elemen diset false (asumsi semua angka prima)

    // Vector untuk menyimpan bilangan prima yang ditemukan
    vector<long long> primeList;

    // Perulangan untuk memeriksa angka dari 2 hingga N-1
    for (long long i = 2; i <= N; i++){
        // Jika angka 'i' belum dieliminasi, berarti angka tersebut adalah prima
        if(!eliminated[i]){
            primeList.push_back(i); // Menambahkan 'i' ke dalam daftar bilangan prima

            // Menandai semua kelipatan dari 'i' sebagai bukan prima, mulai dari i*i
            long long j = i * i; // Mulai dari i^2 (karena semua kelipatan kecil dari 'i' sudah ditandai sebelumnya)
            while (j <= N){
                eliminated[j] = true; // Menandai angka ini sebagai bukan prima
                j += i; // Pindah ke kelipatan berikutnya dari 'i'
            }
        }
    }

    // Mengembalikan daftar bilangan prima yang ditemukan
    return primeList;
}

int main() {
    long long N;

    try {
        // Memasukkan input angka N
        cout << "Masukkan angka N untuk menghasilkan bilangan prima hingga N:";
        cin >> N;

        // Memanggil fungsi sieveOfEratosthenes untuk mendapatkan bilangan prima hingga N
        vector<long long> primes = sieveOfEratosthenes(N);
        
        // Perulangan untuk mencetak setiap bilangan prima dalam vector
        cout << "Bilangan prima hingga " << N << " adalah: ";
        for (long long prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
    catch(const bad_alloc& e){
        cout << "Alokasi memori gagal. Coba gunakan angka yang lebih kecil.\n";
        return 1;
    }
    catch(const std::exception& e){
        cout << "Terjadi kesalahan: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}


/*
    Buku Pemrograman Kompetitif Dasar 
    Panduan Memulai OSN Informatika, ACM-ICPC, dan Sederajat
    Ikatan Alumni TOKI
    
    Algoritma 6 Sieve of Eratosthenes
    1: function SIEVEOFERATOSTHENES(N)
    2:    eleminated ← new boolean[N +1] . Siapkan array boolean eleminated
    3:    FILLARRAY(eleminated, f alse) . Isi seluruh elemen eleminated dengan f alse
    4:    primeList ← {}
    5:    for i ← 2, N do
    6:      if not eleminated[i] then
    7:          primeList ← primeList ∪ {i}
    8:          j ← i×i
    9:          while j ≤ n do
    10:            eleminated[ j] ← true
    11:            j ← j +i
    12:         end while
    13:     end if
    14:   end for
    15:   return primeList
    16: end function

    contoh input dan output :

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:10
    Bilangan prima hingga 10 adalah: 2 3 5 7 

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:20
    Bilangan prima hingga 20 adalah: 2 3 5 7 11 13 17 19 

    Masukkan angka N untuk menghasilkan bilangan prima hingga N:100
    Bilangan prima hingga 100 adalah: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
*/