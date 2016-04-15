#include <iostream>
#include "airport.hpp"

using namespace std;

int main() {

  Airport a("Sofia"), b("London"), c("Paris");

  Flight f1("WIZ5414", "17.04.2016 14:45", 156, b);
  Flight f2("BG4715", "13.04.2016 20:15", 100, c);

  a.add_flight(f1);
  a.add_flight(f2);

  a.print_flights();

  cout << "Date ~~~~~~~~" << endl;

  a.filter_by_date("13.04.2016");

  cout << "Datetime ~~~~~~~~" << endl;

  a.filter_by_datetime("17.04.2016 14:45");

  cout << "Destination ~~~~~~~~" << endl;

  a.filter_by_destination("London");

  cout << "Remove ~~~~~~~~" << endl;

  a.remove_flight("WIZ5414");

  a.print_flights();

  cout << "Buy ticket ~~~~~~~~" << endl;

  a.print_flights();
  cout << a.buy_ticket("57473", "Tom Tom", "BG4715") << endl;
  a.print_flights();


  return 0;
}
