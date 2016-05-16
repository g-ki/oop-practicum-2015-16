#include <iostream>

#include "doge.h"
#include "cate.h"

using namespace std;

Pet& cuterPet(Pet& first, Pet& second)
{
	if (first.getCuteness() >= second.getCuteness())
		return first;
	return second;
}

int main()
{
	Cate garfield("Garfield", 14, "I don't know his name", 20, 6);
	Doge fenton("Fenton", 7, "Rupert", 65, "Black labrador");
	
	//Проверка на конструктора за копиране
	Cate g = garfield;
	g.setName("Gar");
	cout << g.getName() << endl << garfield.getName() << endl << endl;
	
	Doge f = fenton;
	f.setName("Fenny");
	cout << f.getName() << endl << fenton.getName() << endl << endl;
	
	//Проверка на оператор =
	g = garfield;
	g.setName("Garry");
	cout << g.getName() << endl << garfield.getName() << endl << endl;
	
	f = fenton;
	f.setName("Fenster");
	cout << f.getName() << endl << fenton.getName() << endl << endl;
	Pet& winner = cuterPet(garfield, fenton);

	cout << "By far, the cuter pet is " << winner.getName();
}