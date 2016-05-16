#ifndef _STACK_H
#define _STACK_H

#include "list.h"

//Наследяването е удачно да е private, тъй като не искаме
//потребителят на стека да може да използва цялата функционалност на списъка,
//например не искаме да може да добавя и изважда елементи на произволни позиции
//поради свойствата на стека.
template <typename T>
class Stack : List<T>
{
public:
	Stack();
	~Stack();
	Stack(Stack const&);
	Stack& operator=(Stack const&);
	
	void push(T const&);
	void pop();
	
	size_t size() const;
	bool empty() const;
	T& top();
	
	void print() const;
};

template <typename T>
Stack<T>::Stack() : List<T>()
{
}

template <typename T>
Stack<T>::~Stack()
{
	while (!empty())
		pop();
}

template <typename T>
Stack<T>::Stack(Stack const& rs) : List<T>(rs)
{
}

//Някои функции са идентични с тези на списъка
//Телата им са просто извикване на съответната функция в листа
template <typename T>
Stack<T>& Stack<T>::operator=(Stack const& rs)
{
	if (this != &rs)
		List<T>::operator=(rs);
	return *this;
}

template <typename T>
void Stack<T>::push(T const& el)
{
	List<T>::push_back(el);
}

template <typename T>
void Stack<T>::pop()
{
	List<T>::pop_back();
}

template <typename T>
T& Stack<T>::top()
{
	return List<T>::back();
}

template <typename T>
size_t Stack<T>::size() const
{
	return List<T>::size();
}

template <typename T>
bool Stack<T>::empty() const
{
	return List<T>::empty();
}

template <typename T>
void Stack<T>::print() const
{
	List<T>::print();
}

#endif