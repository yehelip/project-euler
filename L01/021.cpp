// #include <bitset>
#include <cmath>
#include <iostream>

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

/*void amicable_chain(int n, std::bitset<10001> &amicable,
                    std::bitset<10001> &numbers) {
  if (numbers[sumDivisors(n)] == true && n != sumDivisors(n)) {
    amicable[n].flip();
    amicable[sumDivisors(n)].flip();
  }
  numbers[n].flip();
}*/

int main() {
  int result = 0;
  for (int i = 1; i < 10000; i++) {
    if (i == sumDivisors(sumDivisors(i)) && sumDivisors(i) < 10000 &&
        sumDivisors(i) != i) {
      result += i;
    }
  }
  std::cout << "The number of amicable number under 10000 is: " << result
            << std::endl;
  return 0;
}
