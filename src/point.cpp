#include "point.h"

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(signed char x, signed char y)
{
	_x = x;
	_y = y;
}

signed char Point::getX()
{
	return _x;
}

signed char Point::getY()
{
	return _y;
}

void Point::setX(signed char x)
{
	_x = x;
}

void Point::setY(signed char y)
{
	_y = y;
}