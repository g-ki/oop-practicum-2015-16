#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <cstring>

class Person
{
	char* name;
	int age;
	
	void copy(Person const&);
public:
	Person();
	~Person();
	Person(char const*, int);
	Person& operator=(Person const&);
	Person(Person const&);

	void setAge(int);

	friend std::ostream& operator<<(std::ostream&, Person const&);
};

#endif