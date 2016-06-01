#ifndef _LAPTOP_H
#define _LAPTOP_H

#include "device.h"

class Laptop : public Device
{
	double batteryLife;
	double maxBatteryLife;
public:
	Laptop(double);

	void print() const;
	void use(int);
	void repair();
};

#endif