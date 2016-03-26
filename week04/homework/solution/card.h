#ifndef _CARD_H
#define _CARD_H

class Card
{
	char title[41];
	char author[31];
	int inStock;
public:
    //Слагаме стойност по подразбиране на inStock 0
    //По този начин на практика създаваме два конструктора
	Card(char const*, char const*, int _inStock = 0);
	Card();

	int getBookAmount() const;
	bool titleMatch(char const*) const;
	void print() const;

	void setBookAmount(int);
};

#endif