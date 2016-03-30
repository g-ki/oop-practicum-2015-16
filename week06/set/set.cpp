#include "set.hpp"
using namespace std;

void Set::resize() {
  capacity = capacity*2 + 1;
  int* tmp = new int[capacity];

  for (int i = 0; i < size; ++i)
    tmp[i] = data[i];

  delete [] data;
  data = tmp;
}

void Set::clone(const Set& s) {
  delete [] data;

  size = s.size;
  capacity = s.capacity;
  data = new int[capacity];

  for (unsigned i = 0; i < size; ++i)
    data[i] = s.data[i];
}

Set::Set() {
  data = nullptr;
  size = 0;
  capacity = 0;
}

Set::Set(int n) {
  size = capacity = 1;
  data = new int[size];
  data[0] = n;
}

Set::Set(const Set& s) {
  data = nullptr;
  clone(s);
}

Set::~Set() {
  delete [] data;
}

Set& Set::operator=(const Set& s) {
  if (this != &s)
    clone(s);

  return *this;
}

int Set::find(int n) const {
  for (unsigned i = 0; i < size; ++i)
    if (data[i] == n)
      return i;

  return -1;
}

bool Set::include(int n) const {
  return find(n) >= 0;
}

void Set::insert(int n) {
  if (full())
    resize();

  data[size++] = n;
}

void Set::remove(int n) {
  int to_remove = find(n);

  if (index >= 0) {
    --size;
    data[to_remove] = data[size];
    // замествам с последния елемент от масива, в множеството няма наредба
  }
}

bool Set::operator==(const Set& s) const {
  if (size != s.size)
    return false;

  for (unsigned i = 0; i < size; ++i)
    if (!include(s.data[i]))
      return false;

  return true;
}

Set& Set::operator+=(const Set& s) {
  for (unsigned i = 0; i < s.size; ++i)
    if (!include(s.data[i]))
      insert(s.data[i]);

  return *this;
}

Set Set::operator+(const Set& s) const {
  Set tmp = *this;
  tmp += s;
  return tmp;
}

Set& Set::operator-=(const Set& s) {
  for (unsigned i = 0; i < s.size; ++i)
    if (include(s.data[i]))
      remove(s.data[i]);

  return *this;
}

Set Set::operator-(const Set& s) const {
  Set tmp = *this;
  tmp -= s;
  return tmp;
}

Set& Set::operator^=(const Set& s) {
  for (unsigned i = 0; i < size; ++i)
    if (!s.include(data[i]))
      remove(data[i--]);
      // изтриваме елемента и се връщаме назад, така при следващото минаване
      // на цикъла елемента поставен на дадената позиция също ще бъде проверен

  return *this;
}

Set Set::operator^(const Set& s) const {
  Set tmp = *this;
  tmp ^= s;
  return tmp;
}

std::ostream& operator<<(std::ostream& os, const Set& s) {
  os << "{";
  for (int i = 0; i < s.size; ++i)
    if (i + 1 < s.size)
      os << s.data[i] << ", ";
    else
      os << s.data[i];

  return os << "}";
}
