#include "patient.h"
#include <cstring>

Patient::Patient()
{
	strcpy(name, "");
	strcpy(dateOfBirth, "");
	visits = 0;
}

Patient::Patient(char const* _name, char const* _dateOfBirth, int _visits)
{
	strncpy(name, _name, 30);
	strncpy(dateOfBirth, _dateOfBirth, 10);
	visits = _visits;
}

void Patient::setPatient(char const* _name, char const* _dateOfBirth, int _visits)
{
	strncpy(name, _name, 30);
	strncpy(dateOfBirth, _dateOfBirth, 10);
	visits = _visits;
}

int Patient::getVisits() const
{
	return visits;
}

const char* Patient::getName() const
{
	return name;
}