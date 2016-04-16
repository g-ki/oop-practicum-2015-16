#include "package.h"
#include <cstring>

Package::Package()
{
	strcpy(id, "");
	weight = 0;
	profit = 0;
}

Package::Package(char const* _id, int _weight, int _profit)
{
	strncpy(id, _id, 10);
	weight = _weight;
	profit = _profit;
}

const char* Package::getId() const
{
	return id;
}

int Package::getWeight() const
{
	return weight;
}

int Package::getProfit() const
{
	return profit;
}