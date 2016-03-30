#include "card.h"
#include <cstring>
#include <iostream>

Card::Card()
{
	strcpy(title, "");
	strcpy(author, "");
	inStock = 0;
}

Card::Card(char const* _title, char const* _author, int _inStock)
{
	strncpy(title, _title, 40);
	strncpy(author, _author, 40);
	inStock = _inStock;
}

bool Card::titleMatch(char const* _title) const
{
	return !strcmp(title, _title);
}

void Card::setBookAmount(int books)
{
	inStock = books;
}

int Card::getBookAmount() const
{
	return inStock;
}

void Card::print() const
{
	std::cout << title << ", " << author << ", " << inStock << std::endl;
}