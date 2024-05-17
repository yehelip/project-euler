#include <iostream>
#define LIMIT 1000

bool condition(int a, int b) { return (a * a < 4 * b); }

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i <= n / 2; i++)
    if (n % i == 0)
      return false;

  return true;
}

int chainLength(int a, int b) {
  int length = 0;
  int n = 1;
  while (isPrime(n * n + a * n + b)) {
    length++;
    n++;
  }
  return length;
}

int solution(int limit) {
  int maxProduct = 0;
  int maxPrimeChainLength = 0;
  int currentPrimeChainLength = 0;
  for (int a = -(limit + 1); a < limit; a++) {
    for (int b = -limit; b < limit + 1; b++) {
      if (condition(a, b)) {
        currentPrimeChainLength = chainLength(a, b);
        if (currentPrimeChainLength > maxPrimeChainLength) {
          maxProduct = a * b;
          maxPrimeChainLength = currentPrimeChainLength;
        }
      }
    }
  }
  return maxProduct;
}

int main() {
  int result = solution(LIMIT);
  std::cout << "The product of the coefficients is: " << result << std::endl;
}
