#include <iostream>
#include "heroes/Elf.hpp"
#include "heroes/Wizard.hpp"
#include "heroes/Knight.hpp"
#include "weapons/Bow.hpp"
#include "weapons/Staff.hpp"
#include "weapons/Blade.hpp"
using namespace std;

ostream& operator<<(ostream& os, const Hero& h) {
  return h.print(os);
}

int main() {
  srand(time(0));

  Hero* heroes[3];

  Bow bow;
  Blade blade;
  Staff staff;

  heroes[0] = new Elf("Sara", 1000, 10, &bow);
  heroes[1] = new Wizard("Mitrele", 1000, 10, &staff);
  heroes[2] = new Knight("BK_Boeca", 1000, 10, &blade);

  // за удобство
  Hero* sara = heroes[0];
  Hero* mitrele = heroes[1];
  Hero* boeca = heroes[2];

  mitrele->first_attack(boeca);

  boeca->heal();

  boeca->third_attack(mitrele);

  sara->second_attack(mitrele);

  for (int i=0;i<3;i++)
    cout << *heroes[i] << endl;

  return 0;
}
