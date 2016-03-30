#include <iostream>
#include "library.h"

using namespace std;

int main()
{
	Card _1984("1984", "George Orwell", 5);
	Card lotr("The Lord of the Rings", "J.R.R. Tolkien", 10);
	Card tkam("To Kill a Mockingbird", "Harper Lee", 7);
	Card mc("The Count of Monte Cristo", "Alexander Dumas", 4);
	
	Card books[5];
	books[0] = _1984;
	books[1] = lotr;
	
	Library l(books, 2);
	l.addBook(tkam);
	l.addBook(mc);
	l.print();

	l.removeBook("To Kill a Mockingbird");
	cout << endl;
	l.print();
	
	l.borrowBook("The Count of Monte Cristo");
	cout << endl;
	l.print();
	
	l.returnBook("The Lord of the Rings");
	cout << endl;
	l.print();
}