#include <iostream>
#include <string>
#include <unordered_map>

// Function to convert a number to its word representation
std::string numberToWords(int number) {
  static const std::unordered_map<int, std::string> words = {
      {0, "Zero"},     {1, "One"},        {2, "Two"},       {3, "Three"},
      {4, "Four"},     {5, "Five"},       {6, "Six"},       {7, "Seven"},
      {8, "Eight"},    {9, "Nine"},       {10, "Ten"},      {11, "Eleven"},
      {12, "Twelve"},  {13, "Thirteen"},  {14, "Fourteen"}, {15, "Fifteen"},
      {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
      {20, "Twenty"},  {30, "Thirty"},    {40, "Forty"},    {50, "Fifty"},
      {60, "Sixty"},   {70, "Seventy"},   {80, "Eighty"},   {90, "Ninety"}};

  if (number <= 20) {
    return words.at(number);
  } else if (number < 100) {
    return words.at(number / 10 * 10) +
           (number % 10 != 0 ? "-" + words.at(number % 10) : "");
  } else if (number < 1000) {
    return words.at(number / 100) + " Hundred" +
           (number % 100 != 0 ? " and " + numberToWords(number % 100) : "");
  } else {
    return "One Thousand";
  }
}

int main() {
  int totalLetters = 0;
  for (int i = 1; i <= 1000; ++i) {
    std::string word = numberToWords(i);
    // Remove spaces and hyphens, and count letters
    for (char c : word) {
      if (c != ' ' && c != '-') {
        ++totalLetters;
      }
    }
  }
  std::cout << "Total number of letters used: " << totalLetters << std::endl;
  return 0;
}
