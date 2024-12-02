#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime(int num) {
    if (num <= 1) return false;  // Numbers <= 1 are not prime
    if (num == 2 || num == 3) return true;  // 2 and 3 are prime
    if (num % 2 == 0) return false;  // Eliminate even numbers > 2

    int limit = static_cast<int>(sqrt(num));  // Store sqrt(num) for performance
    for (int divisor = 3; divisor <= limit; divisor += 2) {  // Check odd divisors only
        if (num % divisor == 0) {
            return false;  // Found a divisor, so it's not prime
        }
    }

    return true;  // No divisors found, so it's prime
}

int main() {
    int num;
    cout << "Enter a number to check if it is prime: ";
    cin >> num;

    if (checkPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}
