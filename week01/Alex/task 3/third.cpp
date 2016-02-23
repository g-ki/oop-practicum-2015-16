#include <iostream>
#include <algorithm>

using namespace std;

void sieveArray(int* array, int size, bool startFromLeft)
{
	//Ако започваме отляво, можем чрез подходяща размяна
	//да наредим оставащите елементи в първата половина на масива
	//Например 1 2 3 4 5 6 ще се преобразува в 2 4 6 1 3 5
	if (startFromLeft)
	{
		for (int i = 1; i < size; i += 2)
			swap(array[i], array[i / 2]);
	}

	//Идеята е същата
	else
	{
		if (size % 2 == 1)
		{
			for (int i = 1; i < size; i += 2)
				swap(array[i], array[i / 2]);
		}
		else
		{
			for (int i = 2; i < size; i += 2)
				swap(array[i], array[i / 2]);
		}
	}

	size /= 2;

	if (size > 1)
		sieveArray(array, size, !startFromLeft);
}

void sieveMenu()
{
	int size;
	do {
		cout << "Enter size of the array: ";
		cin >> size;
	} while (size < 0 || size > 100);

	int array[100];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter array[" << i << "]: ";
		cin >> array[i];
	}

	bool startFromleft = true;

	sieveArray(array, size, startFromleft);

	cout << "The last remaining element is: " << array[0] << endl;
}

void testSieve()
{
	cout << "For array 1 2 3 4 5 6 7 8 9 the last element should be 6" << endl;
	int a[15];
	for (int i = 0; i < 9; i++)
		a[i] = i + 1;
	sieveArray(a, 9, true);
	cout << "The result is: " << a[0] << endl << endl;

	cout << "For array 1 2 3 4 5 6 7 8 the last element should be 6" << endl;
	for (int i = 0; i < 8; i++)
		a[i] = i + 1;
	sieveArray(a, 8, true);
	cout << "The result is: " << a[0] << endl << endl;

	cout << "For array 1 2 3 4 5 6 7 8 9 10 11 the last element should be 8" << endl;
	for (int i = 0; i < 11; i++)
		a[i] = i + 1;
	sieveArray(a, 11, true);
	cout << "The result is: " << a[0] << endl;
}

/*
int main()
{
	sieveMenu();
	//testSieve();
	system("pause");
}*/