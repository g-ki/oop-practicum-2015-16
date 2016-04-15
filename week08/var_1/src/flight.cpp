#include "flight.hpp"

#include "iostream"
#include "airport.hpp"

Flight::Flight() {
  strcpy(number, "");
  strcpy(datetime, "");
  free_seats = 0;
  destination = NULL;
}

Flight::Flight(const char* _number, const char* _datetime, int _free_seats, const Airport& _airport) {
  strncpy(number, _number, 10);
  number[10] = '\0';
  strncpy(datetime, _datetime, 16);
  datetime[16] = '\0';

  free_seats = _free_seats;

  destination = &_airport;
}

const char* Flight::get_number() const {
  return number;
}

const char* Flight::get_datetime() const {
  return datetime;
}

int Flight::get_free_seats() const {
  return free_seats;
}

const Airport* Flight::get_destination() const {
  return destination;
}

void Flight::set_datetime(const char* _datetime) {
  strncpy(datetime, _datetime, 16);
  datetime[16] = '\0';
}

void Flight::sell_seat() {
  if (free_seats > 0)
    --free_seats;
}

std::ostream& operator<<(std::ostream& os, const Flight& f) {
  os << f.number << " " << f.datetime << " " << f.free_seats;
  return os << " " << f.destination->get_name();
}
