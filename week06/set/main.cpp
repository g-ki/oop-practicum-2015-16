#include<iostream>
#include "set.hpp"
using namespace std;

int main() {

  Set s;
  cout << s << endl; // empty

  Set b = Set() + 1 + 2 + 3 + 4 + 10 + 6 + 7; // {1,2,3,4,5,6,7}
  s = b;

  s -= 1;
  s += 1;

  if (s == b)
    cout << s << " == " << b << endl;

  Set c = Set() + 1 + 3 + 5 + 7 + 9;

  cout << (s - c) << endl; // {10, 2, 6, 4}

  Set x = Set() + 1 + 2 + 3 + 4;
  Set y = Set() + 2 + 3 + 5 + 6;
  Set z = (x - y) + (y - x); // {1, 4, 6, 5} симетрична разлика
  cout << z << endl;

  cout << (c ^ z) << endl;

  return 0;
}
