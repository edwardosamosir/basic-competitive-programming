#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

long long fpb_gcd_naive_of_two_numbers(long long a, long long b){
    long long min_val = min(a,b);
    for (long long i = min_val; i > 0; i--){
        if (a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}

/*
vector<long long> prime_factorization(long long n){
    vector<long long> factors;

    // Membagi dengan 2
    while (n % 2 == 0){
        factors.push_back(2);
        n /= 2;
    }
    
    // Membagi dengan angka ganjil dimulai dari 3
    for (long long i = 3; i <= sqrt(n); i+=2){
        while (n % i){
            factors.push_back(i);
            n /= i;
        }
    }

    // Jika n lebih besar dari 2, maka itu adalah faktor prima
    if (n > 2){
        factors.push_back(n);
    }
    return factors;
}
*/

// Faktorisasi Prima (menggunakan map untuk menyimpan faktor dan pangkatnya)
map<long long, int> prime_factorization(long long n){
    map<long long, int> factorPrimes;

    // Membagi dengan 2
    while (n % 2 == 0){
        factorPrimes[2]++;
        n /= 2;
    }
    
    // Membagi dengan angka ganjil dimulai dari 3
    for (long long i = 3; i <= sqrt(n); i+=2){
        while (n % i == 0){
            factorPrimes[i]++;
            n /= i;
        }
    }
    
    // Jika n lebih besar dari 2, maka itu adalah faktor prima
    if (n > 2){
        factorPrimes[n]++;
    }

    return factorPrimes;
}

// Mencari FPB dengan Faktorisasi Prima
long long fpb_gcd_prime_factored_of_two_numbers(long long a, long long b){
    // Mendapatkan faktor prima dari a dan b dalam bentuk map (prime, exponent)
    map<long long, int> prime_factors_a = prime_factorization(a);
    map<long long, int> prime_factors_b = prime_factorization(b);

    long long fpb = 1;

    // Menyusun faktor-faktor yang sama dan mengambil pangkat yang terkecil
    for (auto &factor_a : prime_factors_a){
        long long prime = factor_a.first;
        int exponent_a = factor_a.second;

        if (prime_factors_b.find(prime) != prime_factors_b.end()){
            // Jika faktor sama, ambil pangkat terkecil
            int exponent_b = prime_factors_b[prime];
            int common_exponent = min(exponent_a, exponent_b);

            // Kalikan faktor dengan pangkat terkecil
            fpb *= pow(prime, common_exponent);
        }
    }
    
    return fpb;
}

long long fpb_gcd_euclid_iteration(long long a, long long b){
    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long fpb_gcd_euclid_recursive(long long a, long long b){
    if (b == 0){
        return a;
    }
    return fpb_gcd_euclid_recursive(b, a % b);
}

long long kpk_lcm_naive(long long a, long long b){
    long long max_val = max(a,b);
    while (true){
        if (max_val % a == 0 && max_val % b == 0){
            return max_val;
        }
        max_val++;
    }
}

long long kpk_lcm_iteration(long long a, long long b){
    return(a * b) / fpb_gcd_euclid_iteration(a, b);
}

long long kpk_lcm_recursive(long long a, long long b){
     return(a * b)/ fpb_gcd_euclid_recursive(a, b);
}

   


int main(){
    long long a, b;

    // Masukkan dua angka untuk dicari nilai FPB atau Greatest Common Divisor nya
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;


    cout << "FPB atau GCD dengan metode sederhana dari " << a << " dan " << b << " adalah " << fpb_gcd_naive_of_two_numbers(a, b) << endl;
    cout << "FPB atau GCD dengan metode faktorisasi prima dari " << a << " dan " << b << " adalah " << fpb_gcd_prime_factored_of_two_numbers(a, b) << endl;
    cout << "FPB atau GCD dengan metode iterasi euclid dari " << a << " dan " << b << " adalah " << fpb_gcd_euclid_iteration(a, b) << endl;
    cout << "FPB atau GCD dengan metode rekursif euclid dari " << a << " dan " << b << " adalah " << fpb_gcd_euclid_recursive(a, b) << endl;

    cout << "KPK atau LCM dengan metode sederhana dari " << a << " dan " << b << " adalah " << kpk_lcm_naive(a, b) << endl;
    cout << "KPK atau LCM dengan metode iterasi euclid dari " << a << " dan " << b << " adalah " << kpk_lcm_iteration(a, b) << endl;
    cout << "KPK atau LCM dengan metode rekursif euclid dari " << a << " dan " << b << " adalah " << kpk_lcm_recursive(a, b) << endl;
}

/*
    Buku Pemrograman Kompetitif Dasar 
    Panduan Memulai OSN Informatika, ACM-ICPC, dan Sederajat
    Ikatan Alumni TOKI
    
    Algoritma 7 Algoritma Euclid untuk mencari FPB secara rekursif.
    1: function EUCLID(a,b)
    2:      if b = 0 then
    3:          return a
    4:      else
    5:          return EUCLID(b,a mod b)
    6:      end if
    7: end function

    contoh input dan output :

    Masukkan angka pertama: 4725
    Masukkan angka kedua: 7875
    FPB atau GCD dengan metode sederhana dari 4725 dan 7875 adalah 1575
    FPB atau GCD dengan metode faktorisasi prima dari 4725 dan 7875 adalah 1575
    FPB atau GCD dengan metode iterasi euclid dari 4725 dan 7875 adalah 1575
    FPB atau GCD dengan metode rekursif euclid dari 4725 dan 7875 adalah 1575
*/