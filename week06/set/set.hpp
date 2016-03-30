#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
private:
  int* data;
  unsigned capacity;
  unsigned size;

  void resize();
  void clone(const Set&);
public:
  Set ();
  Set (int);
  Set (const Set&);
  ~Set();

  Set& operator=(const Set&);

  bool full() const { return size >= capacity; }
  bool is_empty() const { return size == 0; }

  int find(int) const;
  bool include(int) const;

  void insert(int);
  void remove(int);

  bool operator==(const Set&) const;

  Set& operator+=(const Set&);
  Set operator+(const Set&) const;

  Set& operator-=(const Set&);
  Set operator-(const Set&) const;

  Set& operator^=(const Set&);
  Set operator^(const Set&) const;

  friend std::ostream& operator<<(std::ostream&, const Set&);
};

#endif
