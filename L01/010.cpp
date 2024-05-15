#include <bitset>
#include <iostream>

long long sumOfPrimes(int n) {
  std::bitset<2000001> isPrime;
  isPrime.set();
  long long sum = 0;
  for (int i = 2; i <= n; ++i) {
    if (isPrime[i]) {
      sum += i;
      for (int j = i * 2; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return sum;
}

int main() {
  int n = 2000000;
  long long sum = sumOfPrimes(n);
  std::cout << "Sum of all the primes below two million: " << sum << std::endl;
  return 0;
}
