#include "teacher.h"

Teacher::Teacher()
	: Person(), StateEmployee(), TaxPayer()
{
	school = 0;
}

Teacher::~Teacher()
{
}

void Teacher::copy(Teacher const& t)
{
	school = new char[strlen(t.school) + 1];
	strcpy(school, t.school);
}

Teacher& Teacher::operator=(Teacher const& t)
{
	if (this != &t)
	{
		delete[] school;

		Person::operator=(t);
		StateEmployee::operator=(t);
		TaxPayer::operator=(t);

		copy(t);
	}
	return *this;
}

Teacher::Teacher(char const* _name, int _age, int _number, int _taxNumber, char const* _school)
	: Person(_name, _age),
	  StateEmployee(_name, _age, _number),
	  TaxPayer(_name, _age, _taxNumber)
{
	school = new char[strlen(_school) + 1];
	strcpy(school, _school);
}

Teacher::Teacher(Teacher const& t)
	: Person(t), StateEmployee(t), TaxPayer(t)
{
	copy(t);
}

std::ostream& operator<<(std::ostream& os, Teacher const& t)
{
	os << (StateEmployee const&)t;
	os << (TaxPayer const&)t;
	os << t.school << std::endl;
	return os;
}

void Teacher::print() const
{
	std::cout << (Person const&)(*this);
	std::cout << *this;
}