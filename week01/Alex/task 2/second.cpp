#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

void addPrimesToArray(int* primeNumbers, int matrix[][15], int matrixSize, int& arrayLimit)
{
	int lastPrimeIndex = 0;

	//Обхождаме над главния диагонал
	for (int j = 0; j < matrixSize; j++)
	{
		int flexibleJ = j;
		for (int i = 0; i <= j; i++)
		{
			if (flexibleJ >= 0 && isPrime(matrix[i][flexibleJ]))
				primeNumbers[lastPrimeIndex++] = matrix[i][flexibleJ];
			flexibleJ--;
		}
	}

	//Обхождаме под главния диагонал
	for (int i = 1; i < matrixSize; i++)
	{
		int flexibleI = i;
		for (int j = matrixSize - 1; j >= i; j--)
		{
			if (flexibleI < matrixSize && isPrime(matrix[flexibleI][j]))
				primeNumbers[lastPrimeIndex++] = matrix[flexibleI][j];
			flexibleI++;	
		}
	}

	arrayLimit = lastPrimeIndex;
}

void printMatrix(int matrix[][15], int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
		cout << array[i] << " ";
	cout << array[size - 1];
}

void menu()
{
	int matrixSize;
	do {
		cout << "Enter the size of the square matrix: ";
		cin >> matrixSize;
	} while (matrixSize < 1 || matrixSize > 15);

	int matrix[15][15];
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << "Enter element at position (" << i << ", " << j << "): ";
			cin >> matrix[i][j];
		}
	}

	int primeNumbers[225];
	int actualSize;

	addPrimesToArray(primeNumbers, matrix, matrixSize, actualSize);

	printMatrix(matrix, matrixSize, matrixSize);
	printArray(primeNumbers, actualSize);
}

void testMatrix()
{
	int matrix[][15] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int primes[10];
	int size;
	addPrimesToArray(primes, matrix, 3, size);
	cout << "Example one:" << endl;
	cout << "1 2 3" << endl;
	cout << "4 5 6" << endl;
	cout << "7 8 9" << endl;
	cout << "The result should be 2 3 5 7." << endl << "The result is: ";
	for (int i = 0; i < size; i++)
		cout << primes[i] << " ";

	int second[][15] = { { 2, 3, 5 }, { 7, 11, 13 }, {17, 19, 23} };
	addPrimesToArray(primes, second, 3, size);
	cout << endl << endl << "Example two:" << endl;
	cout << "2 3 5" << endl;
	cout << "7 11 13" << endl;
	cout << "17 19 23" << endl;
	cout << "The result should be 2 3 7 5 11 17 13 19 23" << endl;
	cout << "The result is: ";
	for (int i = 0; i < size; i++)
		cout << primes[i] << " ";
	cout << endl;
}

/*
int main()
{
	menu();
	//testMatrix();
	system("pause");
}*/