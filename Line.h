/*****************************************************************************
	*	File: Line.h
	*  Class: COP 2001, 202005
	* Author: Paul Basso
	* Purpose: Header file for a Line class
	* where the line properties are calculated for either 2-Point or
	* Point-Slope form.
*****************************************************************************/
#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line
{
public:
	//------------------------------------------------------------
	// constructors
	//------------------------------------------------------------
	Line(); // default
	Line(Point* pointOne, Point* pointTwo); // property constructor
	Line(Point* point, float slope); // property constructor

	//------------------------------------------------------------
	// accessors (getters and setters)
	//------------------------------------------------------------
	float getSlope();
	void setSlope(float value);
	float getYIntercept();
	void setYIntercept(float value);
	float getLength();
	void setLength(float value);
	float getAngle();
	void setAngle(float value);
	Point* getPointOne();
	Point* getPointTwo();

	//------------------------------------------------------------
	// member methods
	//------------------------------------------------------------
	void slopeFrom2Point();
	void slopeIntercept();
	void lineLength();
	void lineAngle();
	void calculate();

private:
	Point pointOne;
	Point pointTwo;

	float slope;
	float yIntercept;
	float length;
	float angle;
};












#endif

