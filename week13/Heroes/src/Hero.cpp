#include "Hero.hpp"

Hero::Hero (string _name, int _h, int _l, int _d, Weapon* _w)
              : name(_name), health(_h), level(_l), demage(_d), weapon(_w) {
  if (weapon != NULL && weapon->get_level() > level)
    weapon = NULL;

  if (health < 0)
    health = 0;
}

int Hero::attack(Hero* hero, int crit) {
  int dmg = 0;
  if (rand() < crit / 10.0) // miss
    dmg = 0;
  else if (weapon == NULL)
    dmg = this->demage;
  else
    dmg = (this->demage + weapon->hit()) * (1 + rand() % crit);

  hero->health -= dmg;
  return dmg;
}

int Hero::first_attack(Hero* hero) {
  return attack(hero, 1);
}

int Hero::second_attack(Hero* hero) {
  return attack(hero, 2);
}

int Hero::third_attack(Hero* hero) {
  return attack(hero, 3);
}

int Hero::heal() {
  return health;
}

ostream& Hero::print(ostream& os) const {
  os << "("<< name << ", " << health << ", " << level << ", " << demage;
  if (weapon != NULL)
    weapon->print(os);
  os << ")";
  return os;
}
