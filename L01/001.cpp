#include <iostream>
#define LIMIT 1'000
using namespace std;

int main() {
  int sum = 0;
  for (int num = 1; num < LIMIT; num++) {
    if (num % 5 == 0 || num % 3 == 0) {
      sum += num;
    }
  }
  cout << "Sum of all the numbers divisible by 3 or 5 below " << LIMIT
       << " is: " << sum << endl;
}
