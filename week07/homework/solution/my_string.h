#ifndef _STRING_H
#define _STRING_H

#include <iostream>

class String
{
	char* str;
	
	void copy(String const&);
public:
	String();
	String(const char*);
	String(String const&);
	
	~String();
	
	String& operator=(String const&);

	String& operator+=(String const&);
	String operator+(String const&);
	
	String& operator*=(int);
	String operator*(int);
	
	bool operator<=(String const&);
	bool operator>=(String const&);
	bool operator==(String const&);
	
	char& operator[](int);
	
	friend std::ostream& operator<<(std::ostream&, String const&);
};

#endif