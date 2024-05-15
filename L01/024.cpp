#include <bitset>
#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#define INDEX 1'000'000
#define length 10

class OutOfRangeException : std::exception {
public:
  OutOfRangeException(const int index, const int maxValue)
      : m_index(index), m_maxValue(maxValue) {}
  const char *what() const noexcept override {
    std::ostringstream oss;
    oss << "The maximal valid index is: " << m_maxValue
        << "\nYou entered: " << m_index;
    m_message = oss.str();
    return m_message.c_str();
  }

private:
  mutable std::string m_message = "";
  int m_index;
  int m_maxValue;
};

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void calc(int n, int index, std::vector<int> &vec) {
  int blockSize = factorial(n - 1);
  int max = n * blockSize;
  if (index > factorial(n)) {
    throw OutOfRangeException(index, max);
  }
  if (n == 0) {
    return;
  }
  int temp = 0;
  while ((temp + 1) * blockSize < index) {
    temp++;
  }
  vec.push_back(temp);
  calc(n - 1, index - (blockSize * temp), vec);
  return;
}

std::vector<int> modify(std::vector<int> &vec) {
  std::vector<int> res;
  std::bitset<length> been;
  int counter = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (been[j] == false) {
        if (counter == vec[i]) {
          been[j].flip();
          res.push_back(j);
        }
        counter++;
      } else {
        continue;
      }
    }
    counter = 0;
  }
  return res;
}

int main() {
  std::vector<int> vec;
  try {
    calc(length, INDEX, vec);
  } catch (const OutOfRangeException &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  std::vector<int> res = modify(vec);
  std::cout << "The permutation at index " << INDEX << " is:" << "\n";
  for (const int &num : res) {
    std::cout << num;
  }
  std::cout << std::endl;
}
