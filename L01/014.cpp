#include <iostream>
#include <unordered_map>

int collatz_length(long n, std::unordered_map<long, int> &memo) {
  if (n == 1)
    return 1;

  if (memo.find(n) != memo.end()) {
    return memo[n];
  }

  int length = 0;

  switch (n % 2) {
  case 0:
    length = 1 + collatz_length(n / 2, memo);
    break;
  case 1:
    length = 1 + collatz_length(3 * n + 1, memo);
    break;
  }

  memo[n] = length;

  return length;
}

int main() {
  std::unordered_map<long, int> memo;
  int max_chain_number = 0;
  int max_chain_length = 0;
  for (int i = 1; i < 1'000'000; i++) {
    if (collatz_length(i, memo) > max_chain_length) {
      max_chain_length = collatz_length(i, memo);
      max_chain_number = i;
    }
  }

  std::cout << "Number with the longest Collatz sequence: " << max_chain_number
            << std::endl;
  std::cout << "Length of the sequence: " << max_chain_length << std::endl;

  return 0;
}
