#include "warehouse.h"
#include <cstring>
#include <iostream>

Warehouse::Warehouse()
{
	packagesSize = 0;
	lorriesSize = 0;
}

int Warehouse::lorryIndex(char const* lorryId)
{
	for (int i = 0; i < lorriesSize; i++)
		if (!strcmp(lorries[i].getId(), lorryId))
			return i;
	
	return -1;
}

int Warehouse::packageIndex(char const* packageId)
{
	for (int i = 0; i < packagesSize; i++)
		if (!strcmp(packages[i].getId(), packageId))
			return i;
	
	return -1;
}

void Warehouse::addLorry(Lorry const& newLorry)
{
	int newLorryIndex = lorryIndex(newLorry.getId());

	if (newLorryIndex == -1)
		lorries[lorriesSize++] = newLorry;
}

void Warehouse::addPackage(Package const& newPackage)
{
	int newPackageIndex = packageIndex(newPackage.getId());
	
	if (newPackageIndex == -1)
		packages[packagesSize++] = newPackage;
}

void Warehouse::removeLorry(char const* id)
{
	int toRemoveIndex = lorryIndex(id);
	
	if (toRemoveIndex != -1)
	{
		for (int i = toRemoveIndex; i < lorriesSize - 1; i++)
			lorries[i] = lorries[i + 1];
		
		lorriesSize--;
	}
}

void Warehouse::removePackage(char const* id)
{
	int toRemoveIndex = packageIndex(id);
	
	if (toRemoveIndex != -1)
	{
		for (int i = toRemoveIndex; i < packagesSize - 1; i++)
			packages[i] = packages[i + 1];
		
		packagesSize--;
	}
}

void Warehouse::setPackageToLorry(char const* packageId, char const* lorryId)
{
	int package_index = packageIndex(packageId);
	int lorry_index = lorryIndex(lorryId);
	
	if (package_index != -1 && lorry_index != -1 && !lorries[lorry_index].getBusy() &&
	    lorries[lorry_index].getMaxWeight() >= packages[package_index].getWeight())
	{
		lorries[lorry_index].setBusy(true);
		removePackage(packageId);
	}
}

void Warehouse::setPackageToBestLorry(char const* packageId)
{
	int package_index = packageIndex(packageId);
	
	if (package_index != -1 && lorriesSize > 0)
	{
		int closestWeight = 0;
		int lorryToHireIndex = -1;
		int packageWeight = packages[package_index].getWeight();

		for (int i = 0; i < lorriesSize; i++)
		{
			int lorryWeight = lorries[i].getMaxWeight();
			bool busy = lorries[i].getBusy();

			if (lorryWeight >= packageWeight && !busy &&
			    (closestWeight == 0 || closestWeight > lorryWeight))
			{
				closestWeight = lorryWeight;
				lorryToHireIndex = i;
			}
		}
		
		if (lorryToHireIndex != -1)
		{
			lorries[lorryToHireIndex].setBusy(true);
			removePackage(packageId);
		}
	}
}

double Warehouse::profit() const
{
	int profitFromPackages = 0;
	for (int i = 0; i < packagesSize; i++)
		profitFromPackages += packages[i].getProfit();
	
	int salariesTotal = 0;
	for (int i = 0; i < lorriesSize; i++)
		salariesTotal += lorries[i].getSalary();
	
	if (lorriesSize > 0)
		return profitFromPackages - (double) salariesTotal / lorriesSize * packagesSize;
	return 0;
}

void Warehouse::print() const
{
	for (int i = 0; i < lorriesSize; i++)
		if (!lorries[i].getBusy())
			lorries[i].print();
			
	std::cout << std::endl;
}