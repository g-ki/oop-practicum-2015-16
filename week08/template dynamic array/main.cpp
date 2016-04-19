#include <iostream>
#include "d_array.h"

using namespace std;

int main()
{
	DArray<int> d;
	d.pushBack(1);
	d.pushBack(2);
	d.pushBack(3);
	d.pushBack(4);
	cout << d;
	
	DArray<int> x = d;
	x.deleteValue(0);
	cout << endl << x << d << endl;
	
	DArray<int> y;
	y = d;
	y.deleteValue(0);
	cout << y << d << endl;
	
	d[0] = 10;
	cout << d << endl;
}