#ifndef _PACKAGE_H
#define _PACKAGE_H

class Package
{
	char id[10];
	int weight;
	int profit;
public:
	Package();
	Package(char const*, int, int);
	
	const char* getId() const;
	int getWeight() const;
	int getProfit() const;
};

#endif