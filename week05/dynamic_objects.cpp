#include <iostream>
using namespace std;

class Object {
  int* data;
  int size;
  char id;
public:
  Object(int _size, char _id) {
    cout << "Constructing object " << _id << " with size = " << _size << endl;
    id = _id;
    size = _size;
    data = new int[size];
  }

  Object(const Object& o) {
    cout << "Copying object " << o.id << endl;
    id = o.id + 1;
    size = o.size;
    data = new int[size];
    for(int i = 0; i < size; ++i)
      data[i] = o.data[i];
  }

  ~Object() {
    cout << "Destructing object " << id << endl;
    delete[] data;
  }
};

int main() {

  Object a(40, 'a');
  Object b = a;


  Object* po = new Object(40, 'p');
  delete po;
}
