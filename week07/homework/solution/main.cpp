#include <iostream>
#include "my_string.h"

using namespace std;

int main()
{
	String a = "abc";
	String b = "xyz";
	
	cout << (a <= b) << endl << (a >= b) << endl << (a == b) << endl;
	
	(a += "xyz") += "123";
	cout << a << endl;

	a[4] = 'Y';
	cout << a << endl;
	
	String x = "abc";
	String my = b + x;
	cout << my << endl;
	
	String s = "sjjasa";
	cout << s[29] << endl;
	
	String c = b * 5;
	cout << c << endl;
	
	b *= 5;
	cout << b << endl;
}