#include<iostream>

using namespace std;

struct Sequece {
  int size;
  int arr[256];
};

void init_sequence(Sequece& s, int* a, int size){
  s.size = size;
  for(int i=0; i < size; ++i)
    s.arr[i] = a[i];
}

int sum(const Sequece& s) {
  int sum = 0;
  for(int i=0; i < s.size; ++i)
    sum += s.arr[i];

  return sum;
}


int diff_null(const Sequece& s) {
	int count = 0;
  for(int i=0; i < s.size; ++i)
    if(s.arr[i] != 0)
    	++count;

  return count;
}

int first_diff_null(const Sequece& s) {

  for(int i=0; i < s.size; ++i)
    if(s.arr[i] != 0)
    	return s.arr[i];

  return 0;
}


bool cmp(const Sequece& a, const Sequece& b){

  if(a.size != b.size)
    return false;

  for(int i=0; i < a.size; ++i)
    if(a.arr[i] != b.arr[i])
    	return false;

  return true;
}

int main() {

  Sequece a, b;
  int arr1[] = {1,2,3,4};
  int arr2[] = {5,1,5,3};

  init_sequence(a, arr1, 4);
  init_sequence(b, arr2, 4);

  cout <<"SUM a = " << sum(a) << endl;

  //.....

	return 0;
}
