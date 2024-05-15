#include <iostream>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long result = 1;
    for (int i = 2; i <= 20; ++i) {
        result = lcm(result, i);
    }
    std::cout << "Smallest positive number that is evenly divisible by all of the numbers from 1 to 20: " << result << std::endl;
    return 0;
}

