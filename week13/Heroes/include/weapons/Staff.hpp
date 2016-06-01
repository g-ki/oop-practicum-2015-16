#ifndef STAFF_HPP
#define STAFF_HPP

#include "Weapon.hpp"

class Staff : public Weapon {
private:
  /* data */
public:
  Staff () : Weapon(30, 7) {}

  int hit() {
    return demage * (rand() % 3 + 1);
  }

  ostream& print(ostream& os) const {
    return os << "(Staff, " << demage << ", " << level << ")";
  }

};

#endif
