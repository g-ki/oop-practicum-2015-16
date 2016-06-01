#ifndef ELF_HPP
#define ELF_HPP

#include "Hero.hpp"

class Elf : public Hero {
private:

public:
  Elf (string _name, int _h = 100, int _l = 1, Weapon* _w = NULL)
          : Hero(_name, _h, _l, 10, _w) { }

  int heal() { return health += 10*level; }
};

#endif
