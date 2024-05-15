#include <iostream>

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    int largestPalindrome = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            int product = i * j;
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }
    std::cout << "Largest palindrome made from the product of two 3-digit numbers: " << largestPalindrome << std::endl;
    return 0;
}

