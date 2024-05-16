#include "../custom/VecInt.h"
#include <iostream>

int main() {

  VecInt back = 1;
  VecInt fib = 1;
  int index = 2;
  while (fib.getDigits().size() < 1000) {
    VecInt temp = VecInt(fib.getDigits(), fib.getNegative());
    fib = VecInt(fib + back);
    back = VecInt(temp);
    index++;
  }

  std::cout
      << "The index of the first fibbonachi number with over 1000 digits is: "
      << index << std::endl;
  return 0;
}
