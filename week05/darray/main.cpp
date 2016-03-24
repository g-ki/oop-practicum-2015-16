#include <iostream>
#include "d_array.h"

using namespace std;

int main()
{
	DArray d;
	
	for (int i = 0; i < 20; i++)
		d.pushBack(i);

	d.print();

	d.setValue(5, 2452);
	d.print();
	
	d.deleteValue(5);
	d.print();
	
	d.popBack();
	d.print();
	
	d.setValue(22, 12222);
	d.print();
	
	cout << d.getSize() << " " << d.getValue(0) << endl;
	
	//Пробвайте това, като изтриете конструктора за копиране
	DArray copyD = d;
	copyD.setValue(0, 55);
	d.print();
	copyD.print();
}