#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Hero.hpp"

class Knight : public Hero {
private:

public:
  Knight (string _name, int _h = 100, int _l = 1, Weapon* _w = NULL)
          : Hero(_name, _h, _l, 30, _w) { }

  int heal() { return health += 2*health; }
};

#endif
