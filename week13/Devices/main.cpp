#include <iostream>

#include "laptop.h"
#include "tv.h"
#include "oven.h"

using namespace std;

int main()
{
	Device** devices = new Device*[3];

	devices[0] = new Laptop(10);
	devices[1] = new TV(1920, 1080);
	devices[2] = new Oven();

	for (int i = 0; i < 3; i++)
	{
		devices[i]->print();
		devices[i]->use(10);
		devices[i]->print();
		devices[i]->repair();
		devices[i]->print();
		cout << endl;
	}
}