#include <iostream>
#include "dictionary.hpp"
using namespace std;

int main() {
  Dictionary d;

  d.add("kuche", "dog");
  d.add("kotka", "cat");
  d.add("papagal", "parrot");
  d.add("i", "and");


  char t[100];
  strcpy(t, "");

  cout << "kuche, kotka i papagal!!!" << endl;
  cout << " ~~~~~ " << endl;

  d.translate("kuche, kotka i papagal!!!", t);

  cout << t << endl;
  return 0;
}
