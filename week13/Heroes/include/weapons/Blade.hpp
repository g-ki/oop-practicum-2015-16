#ifndef BLADE_HPP
#define BLADE_HPP

#include "Weapon.hpp"

class Blade : public Weapon {
private:
  /* data */
public:
  Blade () : Weapon(50, 9) {}

  int hit() {
    return demage * (rand() % 2 + 1);
  }

  ostream& print(ostream& os) const {
    return os << "(Blade, " << demage << ", " << level << ")";
  }

};

#endif
