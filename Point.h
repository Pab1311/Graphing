/*****************************************************************************
	*	File: Point.h
	*  Class: COP 2001, 202005
	* Author: Paul Basso
	* Purpose: Header file for a Point class
	* where the point properties are assigned.
*****************************************************************************/
#ifndef POINT_H
#define POINT_H

class Point
{
public:
	//------------------------------------------------------------
	// constructors
	//------------------------------------------------------------
	Point(); // default
	Point(float x, float y); // property constructor
	Point(Point* point); // copy constructor

	//------------------------------------------------------------
	// accessors (getters and setters)
	//------------------------------------------------------------
	float getX();
	void setX(float value);
	float getY();
	void setY(float value);


	//------------------------------------------------------------
	// member methods
	//------------------------------------------------------------
	bool isEmpty();

private:
	float x;
	float y;
};












#endif
