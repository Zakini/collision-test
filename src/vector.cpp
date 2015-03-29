#include "vector.h"

Vector::Vector() : Point() {}

Vector::Vector(signed char x, signed char y) : Point(x, y) {}

Vector Vector::add(Vector toAdd)
{
	return Vector(_x + toAdd.getX(), _y + toAdd.getY());
}