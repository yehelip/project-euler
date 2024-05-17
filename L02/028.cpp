// Found seuquence for numbers on the down-left diagonal
// on OEIS they are: 4*n^2 - 10*n + 7

#include <iostream>

int sumSquare(int n) {
  if (n == 1)
    return 1;
  int indexInSequence = n / 2 + 1;
  int downLeft =
      4 * indexInSequence * indexInSequence - 10 * indexInSequence + 7;
  return (4 * downLeft) + ((n - 1) * 6);
}

int sumDiagonals(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i = i + 2) {
    sum += sumSquare(i);
  }
  return sum;
}

int main() {
  int sum = sumDiagonals(1001);
  std::cout << "The sum of the diagonals on a 1001 X 1001 square is: " << sum
            << std::endl;
}
