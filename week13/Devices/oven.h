#ifndef _OVEN_H
#define _OVEN_H

#include "device.h"

class Oven : public Device
{
	int consumption;
	double temperature;
	double tempRiseCoef;
public:
	Oven();

	void use(int);
	void repair();

	void print() const;
};

#endif