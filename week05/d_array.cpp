#include "d_array.h"
#include <iostream>

//Идеята на конструктора за копиране е при създаване на обект да го инициализира
//с "празни", но валидни стойности
//Един вариант е всичко да е 0/NULL, друг вариант е:
DArray::DArray()
{
	capacity = 10; //Задаваме максимална дължина на масива 10
	array = new double[capacity]; //Заделяме в динамичната памет масив с големина capacity
	size = 0; //Масивът е празен => размерът му е 0
}

//Конструкторът за копиране се извиква в случаите:
//1. Искаме да създадем копие на 1 обект
//   Пример: Darray copyX = x;
//2. Когато подаваме като аргумент на функция обект
//   (а не обкет const& или указател към обект или псведоним на обект)
//   Пример: void function(Darray d)
//   В този случай ще се създаде копие на d, с което ще работи функцията и съответна ще
//   се извика конструкторът за копиране на класа Darray
//3. Когато връщаме обект като резултат от функция
//   Пример: Darray function()
//Идеята на конструктора за копиране е още при създаване на новия обект
//да копира член данните от образеца в новия обект
//При работа с динамична памет трябва да напишем наш конструктор за копиране
//В останалите случаи се създава системен такъв, който копира полетата дословно
DArray::DArray(DArray const& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	array = new double[capacity];
	
	for (int i = 0; i < size; i++)
		array[i] = rhs.array[i];
}

//Деструкторът се извиква автоматично при "умиране" на обекта
//Той също не е необходим да се пише, ако нямаме работа с динамично памет
//В противен случай трябва да се погрижим да се освободи заделената памет
//когато обектът спре да съществува и съответно няма нужда от тази памет
DArray::~DArray()
{
	delete[] array;
}

void DArray::resize()
{
	capacity *= 1.5;
	
	//Заделяме си нов масив с по-голям капацитет от текущия пълен
	double* newArray = new double[capacity];
	
	//Копираме всички елементи на текущия масив в новия
	for (int i = 0; i < size; i++)
		newArray[i] = array[i];
	
	//В момента имаме следната картинка:
	//[ 1 | 2 | 3 | 4 ] <- array
	//[ 1 | 2 | 3 | 4 |  |  ] <- newArray
	
	//Освободваме паметта за текущия пълен масив
	delete[] array;
	//В момента имаме:
	//? <- array (array сочи към памет, към която нямаме достъп)
	//[ 1 | 2 | 3 | 4 |  |  ] <- newArray
	
	//Пренасочваме array да сочи към newArray
	array = newArray;
	//[ 1 | 2 | 3 | 4 |  |  ] <- newArray, array
}

bool DArray::full() const
{
	return size == capacity;
}

//Чрез get-ъри и set-ъри пожем да достъпваме и променяме private
//член данните извън класа
int DArray::getSize() const
{
	return size;
}

void DArray::pushBack(double newValue)
{
	//Ако масивът е пълен, го разширяваме
	if (full())
		resize();
	
	array[size++] = newValue;
}

void DArray::popBack()
{
	if (size > 0)
		size--;
}

void DArray::setValue(int index, double newValue)
{
	//Ако желаният индекс е по-голям от текущия максимален,
	//добавяме отзад достатъчно на брпй нули и
	//задаваме на позиция index новата стойност
	//Няма проблем ако масивът се напълни заради добавените нули,
	//тъй като pushBack ще извика resize, ако е необходимо
	if (index >= size)
		for (int i = size; i <= index; i++)
			pushBack(0);

	array[index] = newValue;
}

double DArray::getValue(int index) const
{
	if (index < size)
		return array[index];
	
	return 0;
}

void DArray::deleteValue(int index)
{
	if (index < size)
		for (int i = index; i < size - 1; i++)
			array[i] = array[i + 1];
		
	size--;
}

void DArray::print() const
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}