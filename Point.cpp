/*****************************************************************************
	*	File: Point.cpp
	*  Class: COP 2001, 202005
	* Author: Paul Basso
	* Purpose: Implementation file for a Point class
	* where the point properties are assigned.
*****************************************************************************/
#include "Point.h"

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

/********************************************************************************
property constructor
********************************************************************************/
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

/********************************************************************************
copy constructor
********************************************************************************/
Point::Point(Point* point)
{
	x = point->x;
	y = point->y;
}

//-------------------------------------------------------------------------------
// accessors (getters and setters)
//-------------------------------------------------------------------------------
float Point::getX() { return x; }
void Point::setX(float value) { x = value; }
float Point::getY() { return y; }
void Point::setY(float value) { y = value; }

//-------------------------------------------------------------------------------
// member methods
//-------------------------------------------------------------------------------

/***************************************
	Purpose: Checks if point exists and returns true if both coordinates are default at 0.
	@param: Point
	@return: bool - true if no x or y coordinate exists on point
****************************************/
bool Point::isEmpty()
{
	if (!(x || y))
	{
		return true;
	}
	else
	{
		return false;
	}

}