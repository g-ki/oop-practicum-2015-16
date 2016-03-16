#include <iostream>
using namespace std;
// .hpp грубо казано каза, че кода в файла е написан на c++, а не на c(.h).
// http://stackoverflow.com/a/152671
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

  void translate(const char*, char*);

  int get_size() const { return size; }
};
