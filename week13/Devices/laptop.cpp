#include "laptop.h"
#include <iostream>

Laptop::Laptop(double maxLife)
{
	maxBatteryLife = batteryLife = maxLife;
}

void Laptop::print() const
{
	std::cout << "Max battery life: " << maxBatteryLife << std::endl <<
		         "Current battery life: " << batteryLife << std::endl;
}

void Laptop::use(int hours)
{
	if (hours >= 0)
	{
		if (batteryLife - hours >= 0)
			batteryLife -= hours;
		else
			batteryLife = 0;
	}
}

void Laptop::repair()
{
	batteryLife = maxBatteryLife;
}