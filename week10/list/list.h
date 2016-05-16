#ifndef _LIST_H
#define _LIST_H

#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class List
{
	Node<T>* _front;
	Node<T>* _back;
	size_t _size;
	
	void copy(List const&);
public:
	List();
	~List();
	List(List const&);
	List& operator=(List const&);
	
	bool empty() const;
	size_t size() const;
	T& front();
	T& back();
	
	void push_back(T const&);
	void push_front(T const&);
	
	void pop_back();
	void pop_front();
	
	void insert(int, T const&);
	void erase(int);
	void clear();
	
	void print() const;
};

template <typename T>
List<T>::List()
{
	_front = _back = NULL;
	_size = 0;
}

template <typename T>
void List<T>::copy(List const& rs)
{
	_front = _back = NULL;
	_size = 0;
	Node<T>* temp = rs._front;
	while (temp != NULL)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template <typename T>
List<T>::List(List const& rs)
{
	copy(rs);
}

template <typename T>
List<T>::~List()
{
	clear();
}

template <typename T>
List<T>& List<T>::operator=(List const& rs)
{
	if (this != &rs)
	{
		clear();
		copy(rs);
	}
	return *this;
}

template <typename T>
size_t List<T>::size() const
{
	return _size;
}

template <typename T>
T& List<T>::front()
{
	return _front;
}

template <typename T>
T& List<T>::back()
{
	return _back;
}

template <typename T>
bool List<T>::empty() const
{
	return _front == NULL;
} 

template <typename T>
void List<T>::push_back(T const& el)
{
	Node<T>* newElem = new Node<T>;
	newElem->data = el;
	newElem->next = NULL;
	
	if (empty())
		_front = _back = newElem;
	else
	{
		_back->next = newElem;
		_back = newElem;
	}
	
	_size++;
}

template <typename T>
void List<T>::push_front(T const& el)
{
	Node<T>* newElem = new Node<T>;
	newElem->data = el;
	newElem->next = _front;
	
	if (empty())
		_back = newElem;

	_front = newElem;
	_size++;
}

template <typename T>
void List<T>::pop_back()
{
	if (!empty())
	{
		if (_front == _back)
		{
			delete _back;
			_front = _back = NULL;
		}
		else
		{
			Node<T>* temp = _front;
			while (temp->next != _back)
				temp = temp->next;
			
			delete _back;
			_back = temp;
			temp->next = NULL;
		}
		_size--;
	}
}

template <typename T>
void List<T>::pop_front()
{
	if (!empty())
	{
		Node<T>* newFront = _front->next;
		delete _front;
		_front = newFront;

		if (_front == _back)
			_back = NULL;
		
		_size--;
	}
}

//Вмъкване след някоя позиция
template <typename T>
void List<T>::insert(int position, T const& el)
{
	if (position == 0)
		push_front(el);
	else if (position == _size)
		push_back(el);
	else
	{
		Node<T>* newElem = new Node<T>;
		newElem->data = el;

		Node<T>* temp = _front;
		for (int i = 0; i < position; i++)
			temp = temp->next;

		Node<T>* formerNext = temp->next;
		temp->next = newElem;
		newElem->next = formerNext;
		_size++;
	}
}

template <typename T>
void List<T>::erase(int position)
{
	if (position == 0)
		pop_front();
	else if (position == _size)
		pop_back();
	else
	{
		Node<T>* temp = _front;
		for (int i = 0; i < position - 1; i++)
			temp = temp->next;
		
		Node<T>* newNext = temp->next->next;
		delete temp->next;
		temp->next = newNext;
		_size--;
	}
}

template <typename T>
void List<T>::clear()
{
	while (!empty())
		pop_front();
}

template <typename T>
void List<T>::print() const
{
	Node<T>* temp = _front;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

#endif