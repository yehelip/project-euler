#include <iostream>

int main() {
    int sumOfSquares = 0, squareOfSum = 0;
    for (int i = 1; i <= 100; ++i) {
        sumOfSquares += i * i;
        squareOfSum += i;
    }
    squareOfSum *= squareOfSum;
    int difference = squareOfSum - sumOfSquares;
    std::cout << "Difference between the sum of the squares of the first one hundred natural numbers and the square of the sum: " << difference << std::endl;
    return 0;
}

