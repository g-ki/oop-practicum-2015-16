#include "lorry.h"
#include <cstring>
#include <iostream>

Lorry::Lorry()
{
	strcpy(id, "");
	busy = false;
	maxWeight = 0;
	salary = 0;
}

Lorry::Lorry(char const* _id, int _maxWeight, int _salary)
{
	strncpy(id, _id, 10);
	maxWeight = _maxWeight;
	salary = _salary;
	busy = false;
}

const char* Lorry::getId() const
{
	return id;
}

int Lorry::getMaxWeight() const
{
	return maxWeight;
}

bool Lorry::getBusy() const
{
	return busy;
}

int Lorry::getSalary() const
{
	return salary;
}

void Lorry::setBusy(bool _busy)
{
	busy = _busy;
}

void Lorry::print() const
{
	std::cout << "Lorry id: " << id << ", max weight: " 
	          << maxWeight << ", salary: " << salary << std::endl;
}