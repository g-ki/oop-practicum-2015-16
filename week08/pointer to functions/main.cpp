#include <iostream>

using namespace std;

//Вместо да пишем в декларацията на функцията double (*F)(double),
//което е указател към функция, която приема double и връща double,

typedef double (*F)(double);
typedef double (*G)(double, double);

double accumulate(double start, double end, double base,
                  G operation, F term, F next)
{
	double result = base;
	
	//Циклим от start до end, като функцията next е тази,
	//която ни определя как ще се променя i
	for (double i = start; i <= end; i = next(i))
		//Прилагаме операцията върху текущия резултат и term-а
		//Term-ът може да си го представяте като функцията, която
		//стои вътре в квантора за сума например
		result = operation(result, term(i));
	
	return result;
}

double id(double a)
{
	return a;
}

double plusOne(double a)
{
	return a + 1;
}

double myPlus(double a, double b)
{
	return a + b;
}

double myMulti(double a, double b)
{
	return a * b;
}

double squared(double a)
{
	return a * a;
}

double plusTwo(double a)
{
	return a + 2;
}

double minusTwo(double a)
{
	return a - 2;
}

int main()
{
	//Намира сумата от числата от 1 до 10
	cout << accumulate(1, 10, 0, myPlus, id, plusOne) << endl;

	//Намира сумата от квадратите на числата от 1 до 10
	cout << accumulate(1, 10, 0, myPlus, squared, plusOne) << endl;

	//Намира сумата от всички нечетни числа от 1 до 10
	cout << accumulate(1, 10, 0, myPlus, id, plusTwo) << endl;

	//Намира произведението на числата от 1 до 5
	cout << accumulate(1, 5, 1, myMulti, id, plusOne) << endl;

	//Еквивалентно
	cout << accumulate(3, 7, 1, myMulti, minusTwo, plusOne) << endl;
}