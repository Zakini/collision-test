#include "rectangle.h"

Rectangle::Rectangle()
{
	_topEdge = 0;
	_bottomEdge = 0;
	_leftEdge = 0;
	_rightEdge = 0;
}

signed char Rectangle::getTopEdge()
{
	return _topEdge;
}

signed char Rectangle::getBottomEdge()
{
	return _bottomEdge;
}

signed char Rectangle::getLeftEdge()
{
	return _leftEdge;
}

signed char Rectangle::getRightEdge()
{
	return _rightEdge;
}

Point Rectangle::getSize()
{
	return Point(_rightEdge - _leftEdge + 1, _bottomEdge - _topEdge + 1);
}

void Rectangle::setTopEdge(signed char topEdge)
{
	_topEdge = topEdge;
}

void Rectangle::setBottomEdge(signed char bottomEdge)
{
	_bottomEdge = bottomEdge;
}

void Rectangle::setLeftEdge(signed char leftEdge)
{
	_leftEdge = leftEdge;
}

void Rectangle::setRightEdge(signed char rightEdge)
{
	_rightEdge = rightEdge;
}

Point Rectangle::getCentrePoint()
{
	return Point((_rightEdge - _leftEdge) / 2, (_bottomEdge - _topEdge) / 2);
}

Vector Rectangle::getShortestOverlapVector(Rectangle rect)
{
	Point rootCentre = getCentrePoint();
	Point targetCentre = rect.getCentrePoint();
	signed char diffX = targetCentre.getX() - rootCentre.getX();
	signed char diffY = targetCentre.getY() - rootCentre.getY();
	Vector overlapVector;

	if(diffX < diffY)
	{
		overlapVector.setX(diffX);
	}
	else
	{
		overlapVector.setY(diffY);
	}

	return overlapVector;
}