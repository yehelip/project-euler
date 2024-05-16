#include <iostream>

int main() {
  int sum = 0;
  int fib1 = 1, fib2 = 2, fib;
  while (fib2 <= 4000000) {
    if (fib2 % 2 == 0) {
      sum += fib2;
    }
    fib = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib;
  }
  std::cout << "Sum of even Fibonacci numbers less than 4 million: " << sum
            << std::endl;
  return 0;
}
