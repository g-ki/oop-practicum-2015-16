#ifndef _TAX_H
#define _TAX_H

#include <iostream>
#include <cstring>
#include "person.h"

class TaxPayer : virtual public Person
{
	int taxNumber;
public:
	TaxPayer();
	~TaxPayer();
	TaxPayer& operator=(TaxPayer const&);
	TaxPayer(char const*, int, int);
	TaxPayer(TaxPayer const&);

	friend std::ostream& operator<<(std::ostream&, TaxPayer const&);
	
	void print() const;
};

#endif