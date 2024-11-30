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

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;

    auto start = chrono::high_resolution_clock::now(); // Start the timer
    // Check if N is a perfect square
    long long sqrtN = round(sqrt(N));
    if (sqrtN * sqrtN == N) {
        cout << "root : " << sqrtN << endl;
        cout << "lampu menyala" << endl;
    } else {
        cout << "lampu mati" << endl;
    }

    auto end = chrono::high_resolution_clock::now(); // End the timer
    
    chrono::duration<double> elapsed = end - start;
    cout << "Execution Time: " << elapsed.count() << " seconds" << endl; 
}

/*
This solution works because of a key mathematical observation about the divisors of a number:

Explanation:

	1.	Divisors and Button Presses:
	    •	Each button  i  changes the state of the lamp if  N  is divisible by  i . Therefore, each divisor of  N  contributes a state toggle.
	    •	For example, if  N = 12 , the divisors are  1, 2, 3, 4, 6,  and  12 . Each divisor corresponds to a button that toggles the lamp.
	2.	Pairs of Divisors:
	    •	Divisors generally come in pairs. For instance, for  N = 12 :
	    •	 1 \times 12 ,  2 \times 6 ,  3 \times 4 .
	    •	Every time a pair toggles the lamp, the state ultimately cancels out because two toggles (one from each in the pair) return the lamp to its initial state.
	3.	Perfect Squares:
	    •	If  N  is a perfect square (e.g.,  N = 4, 9, 16 ), one of its divisors (the square root) does not have a pair. This divisor toggles the lamp an odd number of times, leaving the lamp in the opposite state (ON).
	    •	For example:
	        •	 N = 4 : Divisors are  1, 2, 4 . The toggle sequence is  OFF \to ON \to OFF \to ON .
	4.	Not a Perfect Square:
	    •	If  N  is not a perfect square, all divisors come in pairs, leading to an even number of toggles. This results in the lamp remaining in its initial state (OFF).

The Solution:

	•	Determine if  N  is a perfect square:
	    •	If  N  is a perfect square, the lamp ends up ON.
	    •	Otherwise, the lamp ends up OFF.
	•	This is computationally efficient because checking if  N  is a perfect square involves only calculating the square root and a single multiplication. This approach works well even for very large  N  (up to  10^{18} ).

Why Is This Efficient?

	•	For  N \leq 10^{18} , calculating the square root  \sqrt{N}  is feasible due to modern computational capabilities.
	•	The algorithm runs in  O(1)  time for each input since it only performs a constant number of operations: taking a square root and comparing.

Example Walkthrough:

	•	Input:  N = 5 :
        •	Divisors:  1, 5 .
        •	 1 : Toggle  OFF \to ON .
        •	 5 : Toggle  ON \to OFF .
        •	Lamp is OFF.

	•	Input:  N = 4 :
        •	Divisors:  1, 2, 4 .
        •	 1 : Toggle  OFF \to ON .
        •	 2 : Toggle  ON \to OFF .
        •	 4 : Toggle  OFF \to ON .
	    •	Lamp is ON.
*/