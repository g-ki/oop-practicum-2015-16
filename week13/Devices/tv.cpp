#include "tv.h"
#include <iostream>

TV::TV(int _width, int _height)
{
	width = _width;
	height = _height;
	deadPixels = 0;
}

void TV::use(int hours)
{
	if (hours >= 0)
		deadPixels += 0.1 * hours;
}

void TV::repair()
{
	deadPixels = 0;
}

int TV::getDeadPixels() const
{
	return deadPixels;
}

void TV::print() const
{
	std::cout << "Dimensions: " << width << "x" << height << std::endl <<
	             "Dead pixels: " << deadPixels << std::endl;
}