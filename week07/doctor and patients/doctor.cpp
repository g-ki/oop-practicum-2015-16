#include "doctor.h"

Doctor::Doctor()
{
	size = 0;
}

bool Doctor::full() const
{
	return size == 50;
}

void Doctor::addPatient(Patient const& newPatient)
{
	if (!full())
		//Нямаме динамична памет, така че операторът = ще си работи без проблеми
		patients[size++] = newPatient;
}

double Doctor::avgVisits() const
{
	int totalVisits = 0;
	for (int i = 0; i < size; i++)
		totalVisits += patients[i].getVisits();

	if (size > 0)
		return (double) totalVisits / size;
	return 0;
}

int Doctor::regularCustomers(int visitsToSurpass, Patient* result) const
{
	int index = 0;
	for (int i = 0; i < size; i++)
		if (patients[i].getVisits() > visitsToSurpass)
			result[index++] = patients[i];
	
	return index;
}