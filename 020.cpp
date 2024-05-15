#include "VecInt.h"
#include <iostream>
#include <ostream>

using namespace std;

VecInt factorVec(VecInt &vec) {
  if (vec.getInt() == 1) {
    return VecInt(1);
  }
  VecInt vec_minus_one = VecInt(vec.getInt() - 1);
  VecInt prev = factorVec(vec_minus_one);
  return vec * prev;
}

int main() {
  VecInt vec = VecInt(100);
  cout << "The sum of the digits of 100! is: " << factorVec(vec).digitSum()
       << endl;
}
