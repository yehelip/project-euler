#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

int digitSum(int n) {
  std::array<int, 10> values = {0,    1,    32,    243,   1024,
                                3125, 7776, 16807, 32768, 59049};
  int sum = 0;
  while (n != 0) {
    sum += values[n % 10];
    n /= 10;
  }
  return sum;
}

int main() {
  std::vector<int> winners;
  for (int i = 10; i < 240'000; i++) {
    std::cout << i << "\n";
    if (digitSum(i) == i) {
      std::cout << "Found!! -> " << i << "\n";
      winners.push_back(i);
    }
  }
  std::cout << "The sum of all of the relavent numbers is: "
            << std::accumulate(winners.begin(), winners.end(), 0) << std::endl;
}
