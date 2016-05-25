#include <iostream>
#include "state.h"
#include "person.h"
#include "taxpayer.h"
#include "teacher.h"

using namespace std;

int main()
{
	Teacher t("Grant", 22, 249, 828, "FMI");
	t.print();

	cout << endl;
	Teacher tt;
	tt = t;
	tt.setAge(32);
	tt.print();
	
	cout << endl;
	Teacher ttt = t;
	ttt.setAge(42);
	ttt.print();
}	