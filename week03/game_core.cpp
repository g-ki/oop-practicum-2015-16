#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
  float x, y,z;

  void init(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  float length() const {
    return sqrt(x*x + y*y + z*z);
  }

  Vector normalize() const {
    Vector tmp;
    float len = length();
    tmp.x = x / len;
    tmp.y = y / len;
    tmp.z = z / len;

    return tmp;
  }

  void print() const {
    cout << "(" << x << ", " << y << ", " << z << ")";
  }
};

Vector sum(const Vector& v1, const Vector& v2) {
  Vector tmp;
  tmp.x = v1.x + v2.x;
  tmp.y = v1.y + v2.y;
  tmp.z = v1.z + v2.z;

  return tmp;
}

float distance(const Vector& v1, const Vector& v2) {
  return sqrt(
              (v1.x - v2.x)*(v1.x - v2.x) +
              (v1.y - v2.y)*(v1.y - v2.y) +
              (v1.z - v2.z)*(v1.z - v2.z)
            );
}

struct Cube {
  Vector position;
  float size;

  void init(const Vector& v, float _size) {
    position = v;
    size = _size;
  }

  void print() const {
    cout << "Cube<";
    position.print();
    cout << ", " << size << ">";
  }

  Vector move(const Vector& v) {
    position = sum(position, v);
    return position;
  }

  bool collide(const Cube& c) const {
    float d = size + c.size;
    return (abs(position.x - c.position.x) <= d) &&
            (abs(position.y - c.position.y) <= d) &&
            (abs(position.z - c.position.z) <= d);
  }
};

struct Sphere {
  Vector position;
  float size;

  void init(const Vector& v, float _size) {
    position = v;
    size = _size;
  }

  void print() const {
    cout << "Sphere<";
    position.print();
    cout << ", " << size << ">";
  }

  Vector move(const Vector& v) {
    position = sum(position, v);
    return position;
  }

  bool collide(const Sphere& s) const {
    return distance(position, s.position) <= size + s.size;
  }
};

int main() {

  Vector a, b;
  a.init(1,1,1);
  b.init(3,3,1);

  a.normalize().print();
  cout << " len: " << a.normalize().length() << endl;
  b.normalize().print();
  cout << " len: " << b.normalize().length() << endl;

  Cube ca, cb;
  ca.init(a, 1);
  cb.init(b, 0.5);

  ca.print();
  cout << endl;
  cb.print();
  cout << endl;

  cout << "ca collide cb: " << ca.collide(cb) << endl; // false
  cb.size = 1.5;
  cout << "ca collide cb: " << ca.collide(cb) << endl; // true

  // .....

  return 0;
}
