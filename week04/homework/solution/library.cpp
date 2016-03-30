#include "library.h"

#include <cstring>
#include <iostream>

Library::Library(Card _books[50], int bookNumber)
{
	for (int i = 0; i < bookNumber; i++)
		books[i] = _books[i];
	index = bookNumber;
}

int Library::getBookIndex(char const* title) const
{
	for (int i = 0; i < index; i++)
		if (books[i].titleMatch(title))
			return i;
	
	return -1;
}

//Тъй като borrowBook и returnBook си приличат,
//е възможно да ги обединим в една фунцкия, която приема
//допълнителни параметри (в случая едно цяло число)
//Подходящо е тази функция да е private, тъй като служи
//само за имплементация на публични функции и в случая не искаме
//потребителят да може безразборно да променя броя налични книги
void Library::alterBookAmount(char const* title, int change)
{
	int bookIndex = getBookIndex(title);
	if (bookIndex != -1 && 
			(change > 0 || (change < 0 && books[bookIndex].getBookAmount() > 0)))
		books[bookIndex].setBookAmount(books[bookIndex].getBookAmount() + change);
}

void Library::borrowBook(char const* title)
{
	alterBookAmount(title, -1);
}

void Library::returnBook(char const* title)
{
	alterBookAmount(title, 1);
}

bool Library::full() const
{
	return index == 50;
}

void Library::print() const
{
	for (int i = 0; i < index; i++)
		books[i].print();
}

void Library::addBook(Card const& newBook)
{
	if (!full())
		books[index++] = newBook;
}

void Library::removeBook(char const* title)
{
	int bookIndex = getBookIndex(title);
	if (bookIndex != -1)
	{
		for (int i = bookIndex; i < index - 1; i++)
			books[i] = books[i + 1];
		
		index--;
	}
}