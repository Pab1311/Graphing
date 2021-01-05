/*****************************************************************************
	*	File: midterm.cpp
	*  Class: COP 2001, 202005
	* Author: Paul Basso
	* Purpose: convert either two-point form or point-slope form into
				slope intercept-form, calculate the line's length, angle, and degrees,
				and graph the line.
*****************************************************************************/
#include <iostream> // input/output operations
#include <iomanip> // contains a method std::setprecision()
#include "opengl.h" // graphics library
#include "Point.h"
#include "Line.h"

//----------------------------------------------------------------------------
// Global space - constants, functions, data structures, etc.
//----------------------------------------------------------------------------

// graphing window details
const int WINDOW_WIDTH{ 600 };
const int WINDOW_HEIGHT{ 400 };
const char* WINDOW_TITLE = "Linear Graph\0";

enum Mode
{
	TWO_POINT = 1,
	POINT_SLOPE,
	EXIT
};

/**************************************************************
						FUNCTION PROTOTYPES
**************************************************************/
int getProblem();
Point getPoint();
void displayLine(Line* line);
void displayPointSlope(Line* line);
void display2Pt(Line* line);
void displaySlopeIntercept(Line* line);
Line get2Point();
Line getPointSlope();
void drawLine(Line* line);


int main()
{
	Line line = Line();
	bool userWantsToContinue = true;

	while (userWantsToContinue)
	{
		int userChoice = getProblem();
		if (userChoice == EXIT)
		{
			userWantsToContinue = false;
		} else if (userChoice == TWO_POINT)
		{
			Line twoPointLine = get2Point();
			twoPointLine.calculate();
			displayLine(&twoPointLine);
			display2Pt(&twoPointLine);
			displaySlopeIntercept(&twoPointLine);
			drawLine(&twoPointLine);

		} else if (userChoice == POINT_SLOPE)
		{
			Line pointSlopeLine = getPointSlope();
			pointSlopeLine.calculate();
			displayLine(&pointSlopeLine);
			displayPointSlope(&pointSlopeLine);
			displaySlopeIntercept(&pointSlopeLine);
			drawLine(&pointSlopeLine);
		}
	}

	return 0;
}

/**************************************************************
						FUNCTION DEFINITIONS
**************************************************************/

/***************************************
	Purpose: Displays the user menu, then inputs and returns the integer function 
	value of the problem number selected.
	@param:
	@return: integer function value of the problem number selected (1, 2, 3)
****************************************/
int getProblem()
{
	int form;

	while (true)
	{
		std::cout << "Select the form that you would like to convert to"
			" slope-intercept form:\n\t 1) Two-point form (you know the two points of the"
			" line)\n\t 2) Point-slope form (you know the line's slope and one point)\n\t"
			" 3) exit\n => ";
		std::cin >> form;
		if (form != TWO_POINT && form != POINT_SLOPE && form != EXIT) {
			std::cout << "Not a valid option. Please try again.\n";
		}
		else {
			break;
		}
	}
	return form;
}

/***************************************
	Purpose: Prompt user for a point on the line
	@param:
	@return: a Point structure containing the x and y coordinates
****************************************/
Point getPoint()
{
	Point point = Point();
	float x_coordinate;
	float y_coordinate;

	std::cout << "\nEnter X and Y coordinates separated by spaces: ";
	std::cin >> x_coordinate >> y_coordinate;

	point = Point(x_coordinate, y_coordinate);

	return point;
}

/***************************************
	Purpose: Takes a Line and displays the current value of its properties
	@param: Line structure
	@return: void
****************************************/
void displayLine(Line* line)
{
	std::cout << "\nLine: \n\t";
	std::cout << std::setprecision(3) << "Point-1  (" << line->getPointOne()->getX()<<
		", " << line->getPointOne()->getY() << ")" << "\n\t";
	std::cout << std::setprecision(3) << "Point-2  (" << line->getPointTwo()->getX() <<
		", " << line->getPointTwo()->getY() << ")" << "\n\t";
	std::cout << std::setprecision(3) << "Slope = " << line->getSlope() << "\n\t";
	std::cout << std::setprecision(3) << "Y-IntCpt = " << line->getYIntercept() << "\n\t";
	std::cout << std::setprecision(3) << "Length = " << line->getLength() << "\n\t";
	std::cout << std::setprecision(3) << "Angle = " << line->getAngle()<< "\n\t";
}

/***************************************
	Purpose: Takes a Line and displays the point-slope form of the line
	@param: Line structure
	@return: void
****************************************/
void displayPointSlope(Line* line)
{
	std::cout << std::setprecision(3) << "\nPoint-slope form: \n\t" << "y - " <<
		line->getPointOne()->getY() << " = " << line->getSlope() << "(x - " << line->getPointOne()->getX() <<
		")" << "\n\t";
}

/***************************************
	Purpose: Takes a Line and displays the two-point form of the line
	@param: Line structure
	@return: void
****************************************/
void display2Pt(Line* line)
{
	std::cout << std::setprecision(3) << "\nTwo-point form: \n\t\t(" << line->getPointTwo()->getY() << " - " <<
		line->getPointOne()->getY() << ")\n\t" << "m = -------------------\n\t\t" << "(" <<
		line->getPointTwo()->getX() << " - " << line->getPointOne()->getX() << ")\n";

}

/***************************************
	Purpose: Takes a Line and displays the slope-intercept form of the line
	@param: Line structure
	@return: void
****************************************/
void displaySlopeIntercept(Line* line)
{
	std::cout << std::setprecision(3) << "\nSlope-intercept form:\n\t" << "y = " <<
		line->getSlope() << "x + " << line->getYIntercept()<< "\n\n";

}

/***************************************
	Purpose: Prompts the user to enter two points that define a line and call functions to
	calculate the slope of the line and the y-intercept, calculate the line’s 
	length, angle, and degrees, and return the line
	@param: 
	@return: Line structure containing pointOne and pointTwo
****************************************/
Line get2Point()
{
	Line twoPointLine = Line();

	std::cout << "\nEnter the first point:\n";
	Point pointOne = getPoint();
	std::cout << "\nEnter the second point:\n";
	Point pointTwo = getPoint();

	twoPointLine = Line(&pointOne, &pointTwo);

	return twoPointLine;
}

/***************************************
	Purpose:  one point and the slope that define a line, set the second point to 
	the y-intercept.
	@param:
	@return: Line structure containing pointOne
****************************************/
Line getPointSlope()
{
	Line pointSlopeLine = Line();
	float slope;

	std::cout << "\nEnter a point for the line";
	Point pointOne = getPoint();
	std::cout << "\nEnter the slope of the line: ";
	std::cin >> slope;
	pointSlopeLine = Line(&pointOne, slope);

	return pointSlopeLine;
}

/***************************************
	Purpose: Takes a line and graphs the line on an OpenGL window
	@param: Line structure
	@return: void
****************************************/
void drawLine(Line* line)
{
	OpenGL window = OpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	float xAxisPosition[2] = { 0, WINDOW_HEIGHT / 2 };
	float xAxisSize[2] = { WINDOW_WIDTH, 1 };
	float yAxisPosition[2] = { WINDOW_WIDTH / 2, 0 };
	float yAxisSize[2] = { 1, WINDOW_HEIGHT };
	unsigned char axisColor[4] = { 0, 0, 0, 0 };

	float linePosition[2] = { (WINDOW_WIDTH / 2.0f) + line->getPointOne()->getX() ,
		(WINDOW_HEIGHT / 2.0f) - line->getPointOne()->getY() };
	float lineSize[2] = { 1, line->getLength() };
	unsigned char lineColor[4] = { 0, 255, 0, 0 };

	while (!window.isClosing())
	{
		window.clearWindow(); // background color
		window.DrawSprite(xAxisPosition, xAxisSize, axisColor, 0); // x-axis
		window.DrawSprite(yAxisPosition, yAxisSize, axisColor, 0); // y-axis
		window.DrawSprite(linePosition, lineSize, lineColor, line->getAngle() - 180.0f, false); // line
		window.paintWindow();
		window.pollEvents();
	}


}
