#include <iostream>
#include <cmath>

using namespace std;

int digits(int number)
{
	if (number < 10)
		return 1;
	return 1 + digits(number / 10);
}

bool containsNumberHelper(int smaller, int bigger, int digits)
{
	if (smaller > bigger)
		return false;
	if (bigger % (int)pow(10, digits) == smaller)
		return true;
	return containsNumberHelper(smaller, bigger / 10, digits);
}

bool containsNumber(int smaller, int bigger)
{
	int smallerDigits = digits(smaller);
	return containsNumberHelper(smaller, bigger, smallerDigits);
}

int main()
{
	cout << containsNumber(123, 52123567) << endl;
	cout << containsNumber(123, 521243567) << endl;
	cout << containsNumber(0, 521203567) << endl;
	cout << containsNumber(124, 852) << endl;
	system("pause");
}