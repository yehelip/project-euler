#include "VecInt.h"
#include <algorithm>
#include <numeric>
#include <vector>

int VecInt::getInt() const {
  int res = 0;
  for (auto it = digits.rbegin(); it != digits.rend(); it++) {
    res *= 10;
    res += *it;
  }
  return negative ? -res : res;
}

std::vector<int> VecInt::getDigits() const {
  std::vector<int> digs = digits;
  std::reverse(digs.begin(), digs.end());
  return digs;
}

bool VecInt::getNegative() const { return negative; }

unsigned int VecInt::digitSum() const {
  return std::accumulate(digits.begin(), digits.end(), 0);
}

int VecInt::getAbsInt() const {
  int num = getInt();
  return negative ? -1 * num : num;
}

bool VecInt::isZero() const { return (getInt() == 0); }
/*
VecInt VecInt::pow(const int exponent) const {
  VecInt res = VecInt(*this);
  for (int i = 0; i < exponent; i++) {
    res = res * (*this);
  }
  return res;
}
*/
VecInt VecInt::pow(int exponent) const {
  VecInt res(1);
  VecInt base(*this);
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      res = res * base;
    }
    base = base * base;
    exponent /= 2;
  }
  return res;
}

VecInt operator*(const VecInt &lhs, const VecInt &rhs) {
  if (lhs.digits.size() == 1 && lhs.digits[0] == 0) {
    return VecInt(0);
  } else if (rhs.digits.size() == 1 && rhs.digits[0] == 0) {
    return VecInt(0);
  }

  bool sign = lhs.negative != rhs.negative;
  std::vector<int> resultDigits(lhs.digits.size() + rhs.digits.size(), 0);
  for (size_t i = 0; i < lhs.digits.size(); ++i) {
    int carry = 0;
    for (size_t j = 0; j < rhs.digits.size() || carry; ++j) {
      int temp = resultDigits[i + j] +
                 lhs.digits[i] * (j < rhs.digits.size() ? rhs.digits[j] : 0) +
                 carry;
      resultDigits[i + j] = temp % 10;
      carry = temp / 10;
    }
  }
  while (!resultDigits.empty() && resultDigits.back() == 0) {
    resultDigits.pop_back();
  }
  return VecInt(resultDigits, sign);
}

// Operator overloads
VecInt VecInt::operator+(const VecInt &other) const {
  // If one of the numbers is negative, perform subtraction instead
  if (negative != other.negative) {
    if (negative) {
      VecInt temp = other;
      temp.negative = false; // Change sign for subtraction
      return *this - temp;
    } else {
      VecInt temp = *this;
      temp.negative = false; // Change sign for subtraction
      return other - temp;
    }
  }

  // Perform addition digit by digit
  std::vector<int> result;
  int carry = 0;
  size_t maxLength = std::max(digits.size(), other.digits.size());

  for (size_t i = 0; i < maxLength || carry; i++) {
    int sum = carry;
    if (i < digits.size())
      sum += digits[i];
    if (i < other.digits.size())
      sum += other.digits[i];
    carry = sum / 10;
    result.push_back(sum % 10);
  }

  return VecInt(result, negative);
}

VecInt VecInt::operator-(const VecInt &other) const {
  // If one of the numbers is negative, perform addition instead
  if (negative != other.negative) {
    if (negative) {
      VecInt temp = other;
      temp.negative = true; // Change sign for addition
      return *this + temp;
    } else {
      VecInt temp = other;
      temp.negative = true; // Change sign for addition
      return *this + temp;
    }
  }

  if (!negative && !other.negative && (*this < other)) {
    return VecInt((other - *this).digits, true);
  }

  // Perform subtraction digit by digit
  std::vector<int> result;
  bool borrow = false;
  size_t maxLength = std::max(digits.size(), other.digits.size());

  for (size_t i = 0; i < maxLength; i++) {
    int diff = digits[i] - borrow;
    if (i < other.digits.size())
      diff -= other.digits[i];
    if (diff < 0) {
      diff += 10;
      borrow = true;
    } else {
      borrow = false;
    }
    result.push_back(diff);
  }

  return VecInt(result, negative);
}

bool VecInt::operator==(const VecInt &other) const {
  return (negative == other.negative) && (digits == other.digits);
}

bool VecInt::operator!=(const VecInt &other) const { return !(*this == other); }

bool VecInt::operator<(const VecInt &other) const {
  if (negative != other.negative) {
    return negative; // Negative numbers are less than positive numbers
  }
  if (digits.size() != other.digits.size()) {
    return digits.size() < other.digits.size();
  }
  for (size_t i = digits.size() - 1; i < digits.size(); i--) {
    if (digits[i] != other.digits[i]) {
      return (negative ? digits[i] > other.digits[i]
                       : digits[i] < other.digits[i]);
    }
  }
  return false; // Equal
}

bool VecInt::operator>(const VecInt &other) const { return other < *this; }

std::ostream &operator<<(std::ostream &os, const VecInt &vecInt) {
  if (vecInt.negative)
    os << "-";
  for (auto it = vecInt.digits.rbegin(); it != vecInt.digits.rend(); ++it) {
    os << *it;
  }
  return os;
}
