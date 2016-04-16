#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "lorry.h"
#include "package.h"

class Warehouse
{
	Package packages[50];
	Lorry lorries[50];
	int packagesSize;
	int lorriesSize;
	
	int lorryIndex(char const*);
	int packageIndex(char const*);
public:
	Warehouse();
	
	void setPackageToLorry(char const*, char const*);
	void setPackageToBestLorry(char const*);

	double profit() const;
	
	void addPackage(Package const&);
	void addLorry(Lorry const&);
	
	void removePackage(char const*);
	void removeLorry(char const*);
	
	void print() const;
};

#endif