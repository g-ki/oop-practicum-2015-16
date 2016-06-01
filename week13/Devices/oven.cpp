#include "oven.h"
#include <iostream>
#include <cmath>

Oven::Oven()
{
	consumption = 0;
	temperature = 0;
	tempRiseCoef = 1;
}

void Oven::use(int hours)
{
	consumption += 3000 * hours;

	for (int i = 0; i < hours; i++)
	{
		//I have no idea what I'm doing.
		temperature += tempRiseCoef * 50;
		tempRiseCoef *= 19.0 / 20;
	}
}

void Oven::repair()
{
	tempRiseCoef = 1;
}

void Oven::print() const
{
	std::cout << "Consumption: " << consumption << std::endl <<
	             "Temperature: " << temperature << std::endl <<
				 "Coefficient: " << tempRiseCoef << std::endl;
}