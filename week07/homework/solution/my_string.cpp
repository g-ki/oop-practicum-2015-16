#include "my_string.h"
#include <cstring>

using namespace std;

String::String()
{
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* s)
{
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}

String::~String()
{
	delete[] str;
}

void String::copy(String const& s)
{
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
}

String& String::operator=(String const& rs)
{
	if (this != &rs)
	{
		delete[] str;
		copy(rs);
	}
	return *this;
}

String& String::operator+=(String const& rs)
{
	char* newStr = new char[strlen(str) + strlen(rs.str) + 1];
	strcpy(newStr, str);
	strcat(newStr, rs.str);
	delete[] str;
	str = newStr;
	return *this;
}

String String::operator+(String const& rs)
{
	String temp = *this;
	temp += rs;
	return temp;
}

String& String::operator*=(int times)
{
	char* temp = new char[strlen(str) + 1];
	strcpy(temp, str);

	char* newStr = new char[strlen(str) * times + 1];
	for (int i = 0; i < times; i++)
		strcat(newStr, temp);
	
	delete[] str;
	str = newStr;
	
	delete[] temp;
	
	return *this;
}

String String::operator*(int times)
{
	String temp = *this;
	temp *= times;
	return temp;
}

bool String::operator<=(String const& rs)
{
	if (strcmp(str, rs.str) <= 0)
		return true;
	return false;
}

bool String::operator>=(String const& rs)
{
	if (strcmp(str, rs.str) >= 0)
		return true;
	return false;
}

bool String::operator==(String const& rs)
{
	return !strcmp(str, rs.str);
}

String::String(String const& s)
{
	copy(s);
}

char& String::operator[](int index)
{
	//Може и без подобна проверка, операторът [] на стандартния string в C++
	//показва и символи, извън обхвата на низа
	if (index >= 0 && index < strlen(str))
		return str[index];
	return str[0];
}

ostream& operator<<(ostream& os, String const& s)
{
	return os << s.str;
}