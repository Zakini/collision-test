#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "vector.h"
#include "point.h"

class Rectangle {
private:
	signed char _topEdge;
	signed char _bottomEdge;
	signed char _leftEdge;
	signed char _rightEdge;

public:
	Rectangle();
	signed char getTopEdge();
	signed char getBottomEdge();
	signed char getLeftEdge();
	signed char getRightEdge();
	Point getSize();
	void setTopEdge(signed char topEdge);
	void setBottomEdge(signed char bottomEdge);
	void setLeftEdge(signed char leftEdge);
	void setRightEdge(signed char rightEdge);
	Point getCentrePoint();
	Vector getShortestOverlapVector(Rectangle rect);

};

#endif