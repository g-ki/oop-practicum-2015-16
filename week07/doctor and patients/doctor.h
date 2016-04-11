#ifndef _DOCTOR_H
#define _DOCTOR_H

#include "patient.h"

class Doctor
{
	Patient patients[50];
	int size;
public:
	Doctor();
	
	bool full() const;
	void addPatient(Patient const&);
	double avgVisits() const;
	int regularCustomers(int, Patient*) const;
};

#endif