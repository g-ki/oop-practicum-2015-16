#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int countDigits(int n)
{
	if (n < 10)
		return 1;
	return 1 + countDigits(n / 10);
}

void splitKeyIntoArray(int* keyArray, int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		keyArray[i] = key / pow(10, size - i - 1);
		key = key % (int)pow(10, size - i - 1);
	}
}

char encodeHelper(char c, int i)
{
	return c + i;
}

char decodeHelper(char c, char i)
{
	return c - i;
}

void encode(char* text, const int* key, int size)
{
	for (int i = 0; i < strlen(text); i++)
		text[i] = encodeHelper(text[i], key[i % size]);
}

void decode(char* text, const int* key, int size)
{
	for (int i = 0; i < strlen(text); i++)
		text[i] = decodeHelper(text[i], key[i % size]);
}


void encodeMenu()
{
	int key;
	do {
		cout << "Enter key: ";
		cin >> key;
	} while (key < 0 || key > 999999999);

	int keyArray[10];
	int actualSize = countDigits(key);
	splitKeyIntoArray(keyArray, actualSize, key);

	cout << "Enter the string: ";
	char sentence[50];
	cin.ignore();
	cin.getline(sentence, 50);

	encode(sentence, keyArray, actualSize);
	cout << sentence << endl;
	decode(sentence, keyArray, actualSize);
	cout << sentence << endl;
}

void testEncoding()
{
	char sentence[10] = "baba";
	int key = 123;
	int keyArray[10];
	splitKeyIntoArray(keyArray, countDigits(key), key);
	encode(sentence, keyArray, 3);
	cout << "Encoding on string 'baba' with key 123 should be cceb" << endl;
	cout << "The result is: " << sentence << endl << endl;

	char second[10] = "abc";
	key = 1;
	splitKeyIntoArray(keyArray, countDigits(key), key);
	encode(second, keyArray, 1);
	cout << "Encoding on string 'abc' with key 1 should be bcd" << endl;
	cout << "The reuslt is: " << second << endl;
}

/*
int main()
{
	encodeMenu();
	//testEncoding();
	system("pause");
}*/
