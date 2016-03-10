#include <iostream>
#include <cmath>

using namespace std;

struct Vector
{
	float x, y, z;

	float length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	Vector normalize()
	{
		float _length = length();
		Vector n;

		if (_length != 0)
		{
			n.x = x / _length;
			n.y = y / _length;
			n.z = z / _length;
		}

		return n;
	}

	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

void initVector(Vector& vector, float _x, float _y, float _z)
{
	vector.x = _x;
	vector.y = _y;
	vector.z = _z;
}

Vector sum(Vector const& first, Vector const& second)
{
	Vector sumOfVectors;

	sumOfVectors.x = first.x + second.x;
	sumOfVectors.y = first.y + second.y;
	sumOfVectors.z = first.z + second.z;

	return sumOfVectors;
}

float vectorDistance(Vector const& first, Vector const& second)
{
	float xSquared = pow(first.x - second.x, 2.0);
	float ySquared = pow(first.y - second.y, 2.0);
	float zSquared = pow(first.z - second.z, 2.0);

	return sqrt(xSquared + ySquared + zSquared);
}

struct Sphere
{
	Vector position;
	float size;

	void move(Vector const& vector)
	{
		position = sum(position, vector);
	}
};

void initSphere(Sphere& sphere, Vector const& _position, float _size)
{
	sphere.position = _position;
	sphere.size = _size;
}

bool collision(Sphere const& first, Sphere const& second)
{
	return vectorDistance(first.position, second.position) <= (first.size + second.size);
}

struct Cube
{
	Vector position;
	float edge;

	void move(Vector const& vector)
	{
		position = sum(position, vector);
	}
};

void initCube(Cube& cube, Vector const& _position, float _edge)
{
	cube.position = _position;
	cube.edge = _edge;
}

bool collision(Cube const& first, Cube const& second)
{
	float halfSumOfEdges = (first.edge + second.edge) / 2;

	float xDifference = abs(first.position.x - second.position.x);
	float yDifference = abs(first.position.y - second.position.y);
	float zDifference = abs(first.position.z - second.position.z);

	return xDifference <= halfSumOfEdges &&
		   yDifference <= halfSumOfEdges &&
		   zDifference <= halfSumOfEdges;
}

int main()
{
	Vector a, b;
	initVector(a, 1, 1, 1);
	initVector(b, 3, 3, 2);

	cout << vectorDistance(a, b) << endl;

	Vector sumOfAB = sum(a, b);
	sumOfAB.print();

	Vector n = sumOfAB.normalize();
	n.print();

	Sphere sOne, sTwo;
	initSphere(sOne, a, 2);
	initSphere(sTwo, b, 2);

	cout << collision(sOne, sTwo) << endl;

	sOne.move(b);
	sOne.move(b);
	cout << collision(sOne, sTwo) << endl;

	Cube cOne, cTwo;
	initCube(cOne, a, 2);
	initCube(cTwo, b, 2);

	cout << collision(cOne, cTwo) << endl;

	cOne.edge = 1;
	cTwo.edge = 1;
	cout << collision(cOne, cTwo) << endl;

	system("pause");
}
