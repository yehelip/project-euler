#ifndef VECINT_H
#define VECINT_H

#include <algorithm>
#include <iostream>
#include <vector>

class VecInt {
private:
  std::vector<int> digits;
  bool negative;

public:
  // Constructors
  VecInt() : digits({0}), negative(false) {}
  VecInt(const std::vector<int> &d, bool neg = false)
      : digits(d), negative(neg) {}
  VecInt(const VecInt &other) {
    digits = other.getDigits();
    negative = other.getNegative();
  }
  VecInt(int n) {
    negative = n < 0 ? true : false;
    n = negative ? -1 * n : n;
    if (n == 0) {
      digits.push_back(0);
    }
    while (n != 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    // std::reverse(digits.begin(), digits.end());
  }

  int getInt() const;
  int getAbsInt() const;
  std::vector<int> getDigits() const;
  bool getNegative() const;
  bool isZero() const;
  unsigned int digitSum() const;
  // Operator overloads
  VecInt operator+(const VecInt &other) const;
  VecInt operator-(const VecInt &other) const;
  friend VecInt operator*(const VecInt &lhs, const VecInt &rhs);
  bool operator==(const VecInt &other) const;
  bool operator!=(const VecInt &other) const;
  bool operator<(const VecInt &other) const;
  bool operator>(const VecInt &other) const;

  // Output stream operator overload
  friend std::ostream &operator<<(std::ostream &os, const VecInt &vecInt);
};

#endif // VECINT_H
