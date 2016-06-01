#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "Hero.hpp"

class Wizard : public Hero {
private:

public:
  Wizard (string _name, int _h = 100, int _l = 1, Weapon* _w = NULL)
          : Hero(_name, _h, _l, 20, _w) { }

  int heal() { return health += 5*health; }
};

#endif
