#include <iostream>
using namespace std;

struct Record {
  char first[32], second[32];

  void set(const char* f, const char* s) {
    strncpy(first, f, 32);
    strncpy(second, s, 32);
  }
};


class Dictionary {
private:
  Record data[1000];
  int size;
public:

  Dictionary();

  void add(const char*, const char*);
  void remove(const char*);
  int search(const char*);

  char translate(const char*, char*);
};
