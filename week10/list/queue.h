#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.h"

template <typename T>
class Queue : List<T>
{
public:
	Queue();
	~Queue();
	Queue(Queue const&);
	Queue& operator=(Queue const&);
	
	void enqueue(T const&);
	void dequeue();
	
	size_t size() const;
	bool empty() const;
	T& front();
	
	void print() const;
};

template <typename T>
Queue<T>::Queue() : List<T>()
{
}

template <typename T>
Queue<T>::~Queue()
{
	while (!empty())
		dequeue();
}

template <typename T>
Queue<T>::Queue(Queue const& rs) : List<T>(rs)
{
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue const& rs)
{
	return List<T>::operator=(rs);
}

template <typename T>
void Queue<T>::enqueue(T const& el)
{
	List<T>::push_back(el);
}

template <typename T>
void Queue<T>::dequeue()
{
	List<T>::pop_front();
}

template <typename T>
T& Queue<T>::front()
{
	return List<T>::front();
}

template <typename T>
size_t Queue<T>::size() const
{
	return List<T>::size();
}

template <typename T>
bool Queue<T>::empty() const
{
	return List<T>::empty();
}

template <typename T>
void Queue<T>::print() const
{
	List<T>::print();
}

#endif