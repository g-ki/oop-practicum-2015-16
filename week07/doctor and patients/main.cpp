#include <iostream>
#include "doctor.h"

using namespace std;

//На контролното може и да не пишете примерно тестове на програмата,
//но нека има един main файл с празен main, така че да се компилира кодът ви
int main()
{
	Patient henry("Henry", "12.06.1976", 5);
	Patient joey("Joey", "02.11.1988", 1);
	Patient tom("Tom", "21.05.1990", 2);
	Patient kevin("Kevin", "25.08.1962", 3);
	
	Doctor haus;
	haus.addPatient(henry);
	haus.addPatient(joey);
	haus.addPatient(tom);
	haus.addPatient(kevin);
	
	cout << haus.avgVisits() << endl;
	Patient patients[10];
	int regulars = haus.regularCustomers(2, patients);
	cout << regulars << endl;
	
	for (int i = 0; i < regulars; i++)
		cout << patients[i].getName() << endl;
}
