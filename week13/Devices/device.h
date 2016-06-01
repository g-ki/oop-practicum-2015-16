#ifndef _DEVICE_H
#define _DEVICE_H

class Device
{
public:
	virtual void use(int) = 0;
	virtual void repair() = 0;

	virtual void print() const = 0;
	
	virtual ~Device() {}
};

#endif