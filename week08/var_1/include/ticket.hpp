#ifndef TICKET_HPP
#define TICKET_HPP

#include <iostream>

class Flight;

class Ticket {
private:
  char id[11];
  char name[32];
  const Flight* flight;

public:

  Ticket();

  Ticket (const char* _id, const char* _name, const Flight& _flight);

  const char* get_id() const;
  const char* get_name() const;
  const Flight* get_airport() const;

  friend std::ostream& operator<<(std::ostream& os, const Ticket& t);
};

#endif
