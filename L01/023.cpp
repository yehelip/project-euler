#include <bitset>
#include <cmath>
#include <iostream>
#define BOUND 28123

int sumDivisors(int n) {
  int sum = 0;
  int sqrtN = sqrt(n);
  for (int i = 1; i <= sqrtN; i++) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
  }
  if (sqrtN * sqrtN == n) {
    sum -= sqrtN;
  }
  sum -= n;
  return sum;
}

bool isAbundant(int n) { return (n < sumDivisors(n)); }

int main() {
  std::bitset<BOUND + 1> abundant;
  std::bitset<BOUND + 1> sums_of_abundant;
  for (int i = 12; i <= BOUND - 12; i++) {
    if (isAbundant(i)) {
      abundant.flip(i);
    }
  }
  for (int i = 12; i <= BOUND; i++) {
    if (abundant[i]) {
      for (int j = i; j <= BOUND; j++) {
        if (abundant[j] && i + j <= BOUND) {
          sums_of_abundant[i + j] = true;
        }
      }
    }
  }
  int sum = 0;
  for (int i = 12; i <= BOUND; i++) {
    if (sums_of_abundant[i] == true) {
      sum += i;
    }
  }

  std::cout << "The sum of the amicable numbers is: " << sum << std::endl;
  std::cout << ((BOUND) * (BOUND + 1) / 2) - sum << std::endl;
}
