#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Weapon {
protected:
  int demage;
  int level;
public:
  Weapon (int _d = 0, int _l = 0) : demage(_d), level(_l) { }
  virtual ~Weapon () {}

  virtual int hit() =0;

  virtual ostream& print(ostream& os) const =0;

  int get_level() const  { return level; }
  int get_demage() const { return demage; }
};

#endif
