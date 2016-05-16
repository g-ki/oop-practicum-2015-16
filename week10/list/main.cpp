#include <iostream>

#include "list.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
	List<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_front(2);
	l.push_front(5);
	l.pop_front();
	l.pop_back();
	l.print();
	
	List<int> copy = l;
	copy.push_back(111);
	copy.print();
	l.print();
	
	copy = l;
	copy.print();

	copy.erase(2);
	copy.print();
	copy.erase(1);
	copy.print();

	copy.insert(0, 32);
	copy.print();
	copy.insert(1, 22);
	copy.insert(1, 62);
	copy.print();
	
	copy.clear();
	copy.push_front(2);
	copy.print();

	Stack<int> s;
	for (int i = 0; i < 4; i++)
		s.push(i);
	s.print();
	s.pop();
	s.print();

	Queue<int> q;
	for (int i = 0; i < 4; i++)
		q.enqueue(i);
	q.print();
	q.dequeue();
	q.print();

	return 0;
}