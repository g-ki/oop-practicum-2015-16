#include "airport.hpp"

Airport::Airport(const char* _name) {
  strncpy(name, _name, 31);
  name[31] = '\0';
  flights_size = 0;
}

const char* Airport::get_name() const {
  return name;
}

void Airport::add_flight(const Flight& f) {
  if (!is_full())
    flights[flights_size++] = f;
}

int Airport::find_flight(const char* f_number) const {
  for (int i = 0; i < flights_size; ++i)
    if (strcmp(f_number, flights[i].get_number()) == 0)
      return i;

  return -1;
}

void Airport::remove_flight(const char* f_number) {
  int index = find_flight(f_number);
  
  if (index < 0)
    return;

  --flights_size;
  for (int i = index; i < flights_size; ++i)
    flights[i] = flights[i + 1];
}

void Airport::filter_by_date(const char* f_date) const {
  for (int i = 0; i < flights_size; ++i)
    if (strncmp(f_date, flights[i].get_datetime(), 10) == 0)
      std::cout << flights[i] << std::endl;
}

void Airport::filter_by_datetime(const char* f_datetime) const {
  for (int i = 0; i < flights_size; ++i)
    if (strcmp(f_datetime, flights[i].get_datetime()) == 0)
      std::cout << flights[i] << std::endl;
}

void Airport::filter_by_destination(const char* f_destination) const {
  for (int i = 0; i < flights_size; ++i)
    if (strcmp(f_destination, flights[i].get_destination()->get_name()) == 0)
      std::cout << flights[i] << std::endl;
}

Ticket Airport::buy_ticket(const char* ticket_id, const char* p_name, const char* f_number) {
  int index = find_flight(f_number);

  if (index < 0 || flights[index].get_free_seats() <= 0)
    return Ticket();

  flights[index].sell_seat();
  return Ticket(ticket_id, p_name, flights[index]);
}

void Airport::print_flights() const {
  for (int i = 0; i < flights_size; ++i)
    std::cout << flights[i] << std::endl;
}
