#include <iostream>
#include <cmath>

int main() {
    int limit;

    // Prompt the user to enter a limit
    std::cout << "Enter the limit to find prime numbers: ";
    std::cin >> limit;

    // Check if the input is valid
    if (limit < 2) {
        std::cout << "There are no prime numbers less than 2." << std::endl;
        return 0; // Exit the program if the limit is less than 2
    }

    std::cout << "Prime numbers up to " << limit << " are:" << std::endl;

    // Loop through numbers from 2 to the given limit
    for (int num = 2; num <= limit; num++) {
        bool is_prime = true;

        // Check if the current number is prime
        for (int i = 2; i <= std::sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = false;
                break; // No need to check further if divisible
            }
        }

        // If the number is prime, print it
        if (is_prime) {
            std::cout << num << std::endl;
        }
    }

    return 0;
}
