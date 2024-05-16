#include <iostream>

long long largestPrimeFactor(long long n) {
  long long factor = 2;
  while (n > 1) {
    if (n % factor == 0) {
      n /= factor;
    } else {
      factor++;
    }
  }
  return factor;
}

int main() {
  long long number = 600851475143;
  std::cout << "Largest prime factor of " << number << ": "
            << largestPrimeFactor(number) << std::endl;
  return 0;
}
