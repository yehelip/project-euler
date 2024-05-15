#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    int number = 1;
    while (count < 10001) {
        number++;
        if (isPrime(number)) {
            count++;
        }
    }
    std::cout << "10001st prime number: " << number << std::endl;
    return 0;
}

