#ifndef BOW_HPP
#define BOW_HPP

#include "Weapon.hpp"

class Bow : public Weapon {
private:
  /* data */
public:
  Bow () : Weapon(20, 1) {}

  int hit() {
    return demage * (rand() % 3 + 1);
  }

  ostream& print(ostream& os) const {
    return os << "(Bow, " << demage << ", " << level << ")";
  }

};

#endif
