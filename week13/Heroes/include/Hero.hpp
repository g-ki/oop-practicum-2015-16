#ifndef HERO_HPP
#define HERO_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>
using namespace std;

class Hero {
protected:
  string name;
  int health;
  int level;
  int demage;
  Weapon* weapon;

  int attack(Hero* hero, int crit);

public:
  Hero (string _name, int _h = 100, int _l = 1, int _d = 1, Weapon* _w = NULL);

  string get_name() const { return name; }
  int get_health() const { return health; }
  int get_level() const { return level; }
  int get_demage() const { return  demage; }
  const Weapon* get_weapon() const { return weapon; }

  virtual ostream& print(ostream& os) const;

  virtual int first_attack(Hero* hero);
  virtual int second_attack(Hero* hero);
  virtual int third_attack(Hero* hero);
  virtual int heal();

  virtual ~Hero () {}
};

#endif
