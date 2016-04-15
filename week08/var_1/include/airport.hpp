#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include "flight.hpp"
#include "ticket.hpp"

class Airport {
private:
  char name[32];
  Flight flights[256];
  int flights_size;

  bool is_full() const { return flights_size >= 256; }
  int find_flight(const char* f_number) const;

public:
  Airport (const char* name);

  const char* get_name() const;

  void add_flight(const Flight& f);
  void remove_flight(const char* f_number);

  void filter_by_date(const char* f_date) const;
  void filter_by_datetime(const char* f_datetime) const;
  void filter_by_destination(const char* f_destination) const;

  void print_flights() const;

  Ticket buy_ticket(const char* ticket_id, const char* p_name, const char* f_number);
};

#endif
