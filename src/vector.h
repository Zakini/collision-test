#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class Vector: public Point
{
public:
	Vector();
	Vector(signed char x, signed char y);
	// TODO Get some operator overloading going on
	Vector add(Vector toAdd);
};

#endif