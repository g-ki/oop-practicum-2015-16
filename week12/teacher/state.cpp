#include "state.h"

StateEmployee::StateEmployee() : Person()
{
	number = 0;
}

StateEmployee::~StateEmployee()
{
}

StateEmployee& StateEmployee::operator=(StateEmployee const& se)
{
	if (this != &se)
	{
		Person::operator=(se);
		number = se.number;
	}
	return *this;
}

StateEmployee::StateEmployee(char const* _name, int _age, int _number)
	: Person(_name, _age), number(_number)
{
}

StateEmployee::StateEmployee(StateEmployee const& se) : Person(se)
{
	number = se.number;
}

std::ostream& operator<<(std::ostream& os, StateEmployee const& se)
{
	return os << se.number << std::endl;
}

void StateEmployee::print() const
{
	std::cout << (Person const&)(*this);
	std::cout << *this << std::endl;
}