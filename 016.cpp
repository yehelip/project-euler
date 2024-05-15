#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int dig_sum(vector<int> &digits) {
  int sum = 0;
  for (const int &digit : digits) {
    sum += digit;
  }
  return sum;
}

void multiply_vector(vector<int> &digits, int n) {
  int product, carry = 0;
  for (auto it = digits.begin(); it != digits.end(); it++) {
    product = (*it) * n + carry;
    (*it) = product % 10;
    carry = product / 10;
  }
  while (carry != 0) {
    digits.push_back(carry % 10);
    carry /= 10;
  }
}

int main() {
  vector<int> digits = {1};
  for (int i = 1; i <= 1000; i++) {
    multiply_vector(digits, 2);
    cout << "2^" << i << " is: ";
    for (auto it = digits.rbegin(); it != digits.rend(); it++) {
      cout << *it;
    }
    cout << "\n";
    cout << "Digit sum of 2^" << i << " is " << dig_sum(digits) << "\n";
  }
}
