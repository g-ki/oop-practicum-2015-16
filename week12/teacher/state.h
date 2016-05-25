#ifndef _STATE_H
#define _STATE_H

#include <iostream>
#include <cstring>
#include "person.h"

class StateEmployee : virtual public Person
{
	int number;
public:
	StateEmployee();
	~StateEmployee();
	StateEmployee& operator=(StateEmployee const&);
	StateEmployee(char const*, int, int);
	StateEmployee(StateEmployee const&);

	friend std::ostream& operator<<(std::ostream&, StateEmployee const&);
	
	void print() const;
};

#endif