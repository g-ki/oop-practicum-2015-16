#include "ticket.hpp"
#include "flight.hpp"

Ticket::Ticket() {
  strcpy(id, "");
  strcpy(name, "");
  flight = NULL;
}

Ticket::Ticket (const char* _id, const char* _name, const Flight& _flight) {
  strncpy(id, _id, 10);
  id[10] = '\0';
  strncpy(name, _name, 31);
  name[31] = '\0';
  flight = &_flight;
}

const char* Ticket::get_id() const {
  return id;
}

const char* Ticket::get_name() const {
  return name;
}

const Flight* Ticket::get_airport() const {
  return flight;
}

std::ostream& operator<<(std::ostream& os, const Ticket& t) {
  return os << t.id << " " << t.name << " " << t.flight->get_number();
}
