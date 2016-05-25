#include "person.h"

Person::Person()
{
	name = new char[0];
	age = 1;
}

void Person::setAge(int _age)
{
	age = _age;
}

void Person::copy(Person const& p)
{
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	age = p.age;
}

Person::~Person()
{
	delete[] name;
}

Person::Person(char const* _name, int _age)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	age = _age;
}

Person& Person::operator=(Person const& p)
{
	if (this != &p)
	{
		delete[] name;
		copy(p);
	}
	return *this;
}

Person::Person(Person const& p)
{
	copy(p);
}

std::ostream& operator<<(std::ostream& os, Person const& p)
{
	return os << p.name << " " << p.age << std::endl;
}