#include "../custom/VecInt.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int valueOfName(std::string name) {
  int value = 0;
  for (char c : name) {
    if ('A' <= c && c <= 'Z') {
      value += static_cast<int>(c - 'A' + 1);
    }
  }
  return value;
}

int main() {
  std::ifstream file("data022.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    return 1;
  }

  std::vector<std::string> names;
  std::string name;

  while (std::getline(file, name, ',')) {
    name.erase(0, 1);
    name.erase(name.size() - 1);
    names.push_back(name);
  }

  std::sort(names.begin(), names.end());

  VecInt sum = VecInt();
  int temp;
  for (int i = 0; i < static_cast<int>(names.size()); i++) {
    temp = (i + 1) * (valueOfName(names[i]));
    if (temp == 4410) {
      std::cout << "At number " << i + 1 << " we have " << names[i] << " with "
                << valueOfName(names[i]) << " and a total of " << temp << "\n";
    }
    sum = sum + VecInt(temp);
    // std::cout << "Sum so far is: " << sum << "\n";
  }

  std::cout << "The sum is: " << sum << std::endl;
}
