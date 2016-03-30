#ifndef _LIBRARY_H
#define _LIBRARY_H

#include "card.h"

class Library
{
	Card books[50];
	int index;
	
	int getBookIndex(char const*) const;
	void alterBookAmount(char const*, int);
		
	bool full() const;
public:
	Library(Card[], int);

	void borrowBook(char const*);
	void returnBook(char const*);
	void addBook(Card const&);
	void removeBook(char const*);
	
	void print() const;
};

#endif