#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
  char name[30];
  int salary;
};

struct Firm {
  char name[30];
  Employee employees[15];
  int size;
};

void print(const Employee& e) {
  cout << e.name << " $" << e.salary;
}

void init(Employee& e, const char* name, int salary) {
  strncpy(e.name, name, 30);
  e.salary = salary;
}
// Тази и горната функция имат еднакви имена, но различни по тип и брой аргументи!
// C++ е достатъчно умен, когато извикате init(Employee, "name", 6) да извика правилната фукнция.
void init(Firm& f, const char* name) {
  strncpy(f.name, name, 30);
  f.size = 0;
}

int is_employed(const Firm& f, const char* name) {
  for (int i = 0; i < f.size; ++i)
    if (strcmp(name, f.employees[i].name) == 0)
      return i;

  return -1;
}

bool is_full_firm(const Firm& f) {
  return f.size >= 15;
}

void add_employee(Firm& f, const Employee& e) {
  if (f.size < 15)
    f.employees[f.size++] = e;
}

void remove_employee(Firm& f, char const* name) {
  int index = is_employed(f, name);

  if (index < 0)
    return;

  // Намалям размера с 1
  --f.size;
  // от позицията на служителя, който трябва да бъде изтрит, до края
  // измествам с една позиция наляво всичи служители.
  for(;index < f.size; ++index)
    f.employees[index] = f.employees[index + 1];
}

void change_salary(Firm& f, char const* name , double percent) {
  int i = is_employed(f, name);
  if (i < 0)
    return;

  f.employees[i].salary += f.employees[i].salary * percent;
}

void view_employees(const Firm& f) {
  for(int i = 0; i < f.size; ++i) {
    print(f.employees[i]);
    cout << endl;
  }
}
// Пробвайте се да вкарате всички функции в съответните структури :).
int main() {

  Firm FMI;
  init(FMI, "Treta Grupa");

  view_employees(FMI);

  Employee first;
  init(first, "Jon Erickson", 3500);
  add_employee(FMI, first);

  view_employees(FMI);

  Employee second;
  init(second, "Jack D.", 2100);
  add_employee(FMI, second);

  Employee third;
  init(third, "Johnnie D.", 5000);
  add_employee(FMI, third);

  cout << "~~~~~~~\n";
  view_employees(FMI);

  cout << "Remove Jack D." << endl;
  remove_employee(FMI, "Jack D.");
  view_employees(FMI);

  return 0;
}
