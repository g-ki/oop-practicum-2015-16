#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>

class Airport;

class Flight {
private:
  char number[11];
  char datetime[17];
  int free_seats;

  const Airport* destination;

public:
  Flight();
  Flight (const char* _number, const char* _datetime, int _free_seats, const Airport& _airport);

  const char* get_number() const;
  const char* get_datetime() const;
  int get_free_seats() const;
  const Airport* get_destination() const;

  void set_datetime(const char* _datetime);

  void sell_seat();


  friend std::ostream& operator<<(std::ostream& os, const Flight& f);
};

#endif
