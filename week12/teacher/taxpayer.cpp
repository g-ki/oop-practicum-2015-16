#include "taxpayer.h"

TaxPayer::TaxPayer() : Person()
{
	taxNumber = 0;
}

TaxPayer::~TaxPayer()
{
}

TaxPayer& TaxPayer::operator=(TaxPayer const& tp)
{
	if (this != &tp)
	{
		Person::operator=(tp);
		taxNumber = tp.taxNumber;
	}
	return *this;
}

TaxPayer::TaxPayer(char const* _name, int _age, int _taxNumber)
	: Person(_name, _age), taxNumber(_taxNumber)
{
}

TaxPayer::TaxPayer(TaxPayer const& tp) : Person(tp)
{
	taxNumber = tp.taxNumber;
}

std::ostream& operator<<(std::ostream& os, TaxPayer const& tp)
{
	return os << tp.taxNumber << std::endl;
}

void TaxPayer::print() const
{
	std::cout << (Person const&)(*this);
	std::cout << *this << std::endl;
}