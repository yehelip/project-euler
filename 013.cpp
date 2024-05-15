#include <algorithm> // For std::max
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string sumFirstTenDigits(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;
  std::vector<int> sum(52, 0); // Initialize a vector to hold the sum,
                               // considering maximum length of 52 digits
  int carry = 0;

  // Adding without considering carry (sum is reversed)
  while (std::getline(file, line)) {
    std::reverse(line.begin(), line.end());
    for (size_t i = 0; i < line.size(); i++) {
      int digit = line[i] - '0';
      sum[i] += digit;
    }
  }

  // Perform carry propagation
  for (size_t i = 0; i < sum.size(); i++) {
    sum[i] += carry;
    carry = sum[i] / 10;
    sum[i] %= 10;
  }

  std::reverse(sum.begin(),
               sum.end()); // Reverse the sum again

  // Convert the sum to a string
  std::string result;
  for (int i = 0; i < static_cast<int>(sum.size()); i++) {
    result += static_cast<char>(sum[i] + '0');
  }

  // Return the first ten digits of the sum
  return result.substr(0, 10);
}

int main() {
  std::string filename = "numbers.txt";
  std::string firstTenDigits = sumFirstTenDigits(filename);
  std::cout << "The first ten digits of the sum are: " << firstTenDigits
            << std::endl;
  return 0;
}
