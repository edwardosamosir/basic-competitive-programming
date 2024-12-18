/*
    Lampu dan Tombol
     
    Batas waktu: 1 detik
    Batas memori: 64 MB

    Terdapat N tombol yang dinomori dari 1 hingga N dan sebuah lampu dalam keadaan
    mati. Apabila tombol ke-i ditekan, keadaan lampu akan berubah (dari mati menjadi
    menyala, atau sebaliknya) apabila N habis dibagi oleh i. Apabila masing-masing
    tombol ditekan tepat sekali, bagaimana keadaan lampu pada akhirnya?

    Format Masukan
    Sebuah baris berisi sebuah bilangan, yaitu N.

    Format Keluaran
    Sebuah baris berisi:
        • "lampu mati", apabila keadaan akhir lampu adalah mati.
        • "lampu menyala", apabila keadaan akhir lampu adalah menyala.

    Contoh Masukan 1
    5
    Contoh Keluaran 1
    lampu mati

    Contoh Masukan 2
    4
    Contoh Keluaran 2
    lampu menyala

    Penjelasan
    Pada contoh pertama, tombol yang mempengaruhi keadaan lampu adalah tombol
    1 dan tombol 5. Penekanan tombol 1 mengakibatkan lampu menjadi menyala, dan
    penekanan tombol 5 mengembalikannya ke keadaan mati.

    Pada contoh kedua, tombol yang mempengaruhi keadaan lampu adalah tombol 1,
    tombol 2, dan tombol 4. Penekanan tombol 1 mengakibatkan lampu menjadi menyala,
    penekanan tombol 2 mengembalikannya ke keadaan mati, dan penekanan tombol 4
    menjadikan lampu kembali menyala.

    Batasan

    • 1 ≤ N ≤ 1018
*/

#include<iostream>
#include <cmath>
#include <chrono>
using namespace std;

int main(){
    long long N;
    cin >> N;

    long long num = N;
    int divisorCount = 1;
    vector<long long> primeFactors;

    auto start = chrono::high_resolution_clock::now(); // Start the timer
    
    for (long long i = 2; i * i <= num; i++){
        int factorCount = 0;
        while (num % i == 0){
            factorCount++;
            num /= i;
            primeFactors.push_back(i);
        }

        divisorCount *= (1 + factorCount);        
    }

    /*
        remaining factor, only possible for one prime number that greater that sqrt(dynamic remaining num),
        each factor is equi to multiplication of 2 (for 1 and the number itself)
    */
    if(num > 1){
        divisorCount *= 2;
        primeFactors.push_back(num);
    }
    auto end = chrono::high_resolution_clock::now(); // End the timer

    // Print the prime factors
    cout << "Prime factors: ";
    for (long long factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    if(divisorCount % 2 == 0){
        cout << "lampu mati" << endl;
    } else {
        cout << "lampu menyala" << endl;
    }
    
    chrono::duration<double> elapsed = end - start;
    cout << "Execution Time: " << elapsed.count() << " seconds" << endl; 
}