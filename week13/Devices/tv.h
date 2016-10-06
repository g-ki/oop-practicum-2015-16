#ifndef _TV_H
#define _TV_H

#include "device.h"

class TV : public Device
{
	int width;
	int height;
	double deadPixels;
public:
	TV(int, int);

	void use(int);
	void repair();
	void print() const;
	
	int getDeadPixels() const;
};

#endif