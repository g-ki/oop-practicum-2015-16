#ifndef _TEACHER_H
#define _TEACHER_H

#include <iostream>
#include <cstring>

#include "state.h"
#include "taxpayer.h"

class Teacher : public StateEmployee, public TaxPayer
{
	char* school;
	
	void copy(Teacher const&);
public:
	Teacher();
	~Teacher();
	Teacher& operator=(Teacher const&);
	Teacher(char const*, int, int, int, char const*);
	Teacher(Teacher const&);

	friend std::ostream& operator<<(std::ostream&, Teacher const&);

	void print() const;
};

#endif