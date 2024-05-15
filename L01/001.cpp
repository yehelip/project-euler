#include <iostream>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    std::cout << "Sum of multiples of 3 and 5 below 1000: " << sum << std::endl;
    return 0;
}

