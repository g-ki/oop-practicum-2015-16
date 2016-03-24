#ifndef D_ARRAY_H_
#define D_ARRAY_H_

class DArray
{
	double* array; //нашият масив
	int size;  //докъде е запълнен
	int capacity; //максимален размер

	void resize();
	bool full() const;
public:
	DArray();
	DArray(DArray const&);
	
	~DArray();
	
	void pushBack(double);
	void setValue(int, double);
	void popBack();
	void deleteValue(int);
	
	int getSize() const;
	double getValue(int) const;
	
	void print() const;
};

#endif