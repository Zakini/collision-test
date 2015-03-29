#ifndef POINT_H
#define POINT_H

class Point {
protected:
	signed char _x;
	signed char _y;

public:
	Point();
	Point(signed char x, signed char y);
	signed char getX();
	signed char getY();
	void setX(signed char x);
	void setY(signed char y);
};

#endif