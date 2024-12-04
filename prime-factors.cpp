#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long n;
    std::cout << "Enter a number to find its prime factors: ";
    std::cin >> n;

    // Function to find and print prime factors
    std::vector<int> factors;

    // Handle 2 as a special case (smallest prime factor)
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors starting from 3
    for (int divisor = 3; divisor <= std::sqrt(n); divisor += 2) {
        while (n % divisor == 0) {
            factors.push_back(divisor);
            n /= divisor;
        }
    }

    // If n is still greater than 2, then it must be prime
    if (n > 2) {
        factors.push_back(n);
    }

    // Output the prime factors
    std::cout << "Prime factors of the number: ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
