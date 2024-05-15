#include <iostream>
#include <cmath>

int countDivisors(long long n) {
    int count = 0;
    int sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; ++i) {
        if (n % i == 0) {
            count += 2; 
        }
    }

    if (sqrtN * sqrtN == n) {
        count--;
    }
    return count;
}

int main() {
    long long result = 1;
    int i = 2;
    while (countDivisors(result) <= 500) {
        result += i++;
    }

    std::cout << "The first triangle number to have over 500 divisors is: " << result << std::endl;

    return 0;
}

