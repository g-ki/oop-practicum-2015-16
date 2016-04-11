#ifndef _PATIENT_H
#define _PATIENT_H

class Patient
{
	char name[30];
	char dateOfBirth[10];
	int visits;
public:
	Patient();
	Patient(char const*, char const*, int);
	//Така го беше направил Жоро в часа
	//На контролното, ако не е споменато изрично, няма нужда от двете
	void setPatient(char const*, char const*, int);
	
	int getVisits() const;
	//За целите на проверката само
	const char* getName() const;
};

#endif