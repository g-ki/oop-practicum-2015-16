#ifndef _LORRY_H
#define _LORRY_H

class Lorry
{
	char id[10];
	int maxWeight;
	bool busy;
	int salary;
public:
	Lorry();
	Lorry(char const*, int, int);
	
	const char* getId() const;
	int getMaxWeight() const;
	bool getBusy() const;
	int getSalary() const;
	
	void setBusy(bool);
	
	void print() const;
};

#endif