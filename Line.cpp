/*****************************************************************************
	*	File: Line.cpp
	*  Class: COP 2001, 202005
	* Author: Paul Basso
	* Purpose:  Implementation file for a Line class
	* where the line properties are calculated.
*****************************************************************************/
#include <iostream> // input/output operations
#include <math.h> // contains functions std::pow(), std::sqrt(), and std::atan2() 
#include "Line.h" // don't need to include Point.h since line.h already includes it


//----------------------------------------------------------------------------
// Global space - constants, functions, data structures, etc.
//----------------------------------------------------------------------------
// PI constant
const float PI{ 3.14159265 };

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
Line::Line()
{
	pointOne = Point(0, 0);
	pointTwo = Point(0, 0);

	slope = 0.0f;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;
}

/********************************************************************************
property constructor
********************************************************************************/
Line::Line(Point* pointOne, Point* pointTwo)
{
	this->pointOne = pointOne;
	this->pointTwo = pointTwo;

	slope = 0.0f;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;
}

/********************************************************************************
property constructor
********************************************************************************/
Line::Line(Point* point, float slope)
{
	pointOne = Point(point);
	pointTwo = Point(0, 0);

	this->slope = slope;
	yIntercept = 0.0f;
	length = 0.0f;
	angle = 0.0f;
}

//-------------------------------------------------------------------------------
// accessors (getters and setters)
//-------------------------------------------------------------------------------
float Line::getSlope() { return slope; }
void Line::setSlope(float value) { slope = value; }
float Line::getYIntercept() { return yIntercept; }
void Line::setYIntercept(float value) { yIntercept = value; }
float Line::getLength() { return length; }
void Line::setLength(float value) { length = value; }
float Line::getAngle() { return angle; }
void Line::setAngle(float value) { angle = value; }
Point* Line::getPointOne() { return &pointOne; }
Point* Line::getPointTwo() { return &pointTwo; }


//-------------------------------------------------------------------------------
// member methods
//-------------------------------------------------------------------------------
/***************************************
	Purpose: sets the slope property
	@param:
	@return: void
****************************************/
void Line::slopeFrom2Point()
{
	slope = (pointTwo.getY() - pointOne.getY()) / ((pointTwo.getX()) - (pointOne.getX()));
}

/***************************************
	Purpose: sets the yIntercept property
	@param: 
	@return: void
****************************************/
void Line::slopeIntercept()
{
	yIntercept = pointOne.getY() - (getSlope() * pointOne.getX());
}

/***************************************
	Purpose: calculates and sets the length property
	@param: 
	@return: void
****************************************/
void Line::lineLength()
{
	length = std::sqrt((std::pow((pointTwo.getX() - pointOne.getX()), 2)) + (std::pow((pointTwo.getY() - pointOne.getY()), 2)));
}


/***************************************
	Purpose: sets the angle property
	@param:
	@return: void
****************************************/
void Line::lineAngle()
{
	float theta = std::atan2((pointTwo.getY() - pointOne.getY()), (pointTwo.getX() - pointOne.getX()));
	angle = std::fmod((90.0 - double(theta * 180.0 / PI)), 360);
}

/***************************************
	Purpose: calls all other member methods and sets property values
	@param:
	@return: void
****************************************/
void Line::calculate()
{
	if (pointTwo.isEmpty()) // POINT SLOPE
	{
		std::cout << "True";
		slopeIntercept();
		pointTwo.setY(yIntercept);
		lineLength();
		lineAngle();
	}
	else // 2 POINT
	{
		slopeFrom2Point();
		slopeIntercept();
		lineLength();
		lineAngle();
	}

}