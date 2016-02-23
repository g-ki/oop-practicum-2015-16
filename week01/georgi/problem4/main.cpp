#include <iostream>
#include <cmath>
using namespace std;


int int_size(int n) {
  int i = 1;
  while (n /= 10)
    ++i;
  return i;
}

bool sub_num(int a, int b) {

  if (a < b) return false;

  int remainder = pow(10, int_size(b));
  if (b == a % remainder)
    return true;

  return sub_num(a / 10, b);
}

int main() {

  cout << sub_num(17371, 71) << endl;
  cout << sub_num(17371, 1) << endl;
  cout << sub_num(17371, 7137) << endl;

  return 0;
}
