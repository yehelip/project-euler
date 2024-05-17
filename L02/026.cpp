#include <cmath>
#include <iostream>
#include <unordered_map>

int cycleLength(int d) {
  std::unordered_map<int, int> remainders;
  int remainder = 1;
  int position = 0;
  while (remainder != 0) {
    if (remainders.find(remainder) != remainders.end()) {
      return position - remainders[remainder];
    }
    remainders[remainder] = position;
    remainder = (remainder * 10) % d;
    ++position;
  }
  return 0;
}

int maxCycleLength(int n) {
  int maxLength = 0;
  int currentLength = 0;
  int maxD = 0;
  for (int d = 2; d < n; ++d) {
    currentLength = cycleLength(d);
    if (currentLength > maxLength) {
      maxLength = currentLength;
      maxD = d;
    }
  }
  return maxD;
}

int main() {
  int maxD = maxCycleLength(1000);
  std::cout << "The d < 1000 with the longest recurring cycle is: " << maxD
            << std::endl;
  return 0;
}
