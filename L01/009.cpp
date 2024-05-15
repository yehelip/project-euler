#include <iostream>

int main() {
    int product = 0;
    for (int a = 1; a < 1000; ++a) {
        for (int b = a + 1; b < 1000; ++b) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                product = a * b * c;
                break;
            }
        }
        if (product != 0) {
            break;
        }
    }
    std::cout << "Product of the Pythagorean triplet: " << product << std::endl;
    return 0;
}

