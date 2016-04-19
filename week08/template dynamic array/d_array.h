#ifndef D_ARRAY_H_
#define D_ARRAY_H_

#include <iostream>

template <typename T>
class DArray
{
	T* array;
	int size;
	int capacity;

	void resize();
	void copy(DArray<T> const&);
	bool full() const;
public:
	DArray();
	DArray(DArray const&);
	
	~DArray();
	
	void pushBack(T const&);
	void setValue(int, T const&);
	void popBack();
	void deleteValue(int);
	
	int getSize() const;
	T getValue(int) const;

	friend std::ostream& operator<<(std::ostream& os, DArray<T> const& da)
	{
		for (int i = 0; i < da.size; i++)
		os << da.array[i] << " ";
		return os << std::endl;
	}
	
	DArray& operator=(DArray const&);
	T& operator[](int);
};

template <typename T>
DArray<T>::DArray()
{
	capacity = 10;
	array = new T[capacity];
	size = 0;
}

template <typename T>
void DArray<T>::copy(DArray<T> const& da)
{
	size = da.size;
	capacity = da.capacity;
	array = new T[capacity];
	
	for (int i = 0; i < size; i++)
		array[i] = da.array[i];
}

template <typename T>
DArray<T>::DArray(DArray const& rhs)
{
	copy(rhs);
}

template <typename T>
DArray<T>::~DArray()
{
	delete[] array;
}

template <typename T>
void DArray<T>::resize()
{
	capacity *= 1.5;
	T* newArray = new T[capacity];

	for (int i = 0; i < size; i++)
		newArray[i] = array[i];

	delete[] array;
	array = newArray;
}

template <typename T>
bool DArray<T>::full() const
{
	return size == capacity;
}

template <typename T>
int DArray<T>::getSize() const
{
	return size;
}

template <typename T>
void DArray<T>::pushBack(T const& newValue)
{
	if (full())
		resize();
	
	array[size++] = newValue;
}

template <typename T>
void DArray<T>::popBack()
{
	if (size > 0)
		size--;
}

template <typename T>
void DArray<T>::setValue(int index, T const& newValue)
{
	if (index >= size)
		for (int i = size; i <= index; i++)
			pushBack(0);

	array[index] = newValue;
}

template <typename T>
T DArray<T>::getValue(int index) const
{
	if (index < size)
		return array[index];
	
	return 0;
}

template <typename T>
void DArray<T>::deleteValue(int index)
{
	if (index < size)
		for (int i = index; i < size - 1; i++)
			array[i] = array[i + 1];
		
	size--;
}

template <typename T>
DArray<T>& DArray<T>::operator=(DArray<T> const& da)
{
	if (this != &da)
	{
		delete[] array;
		copy(da);
	}
	return *this;
}

template <typename T>
T& DArray<T>::operator[](int index)
{
	if (index >= 0 && index < size)
		return array[index];
	return array[0];
}

#endif