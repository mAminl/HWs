#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"


class TwoDimensionalShape : public Shape{
public:

	//Define position of shape
	double Position_x{0};
	double Position_y{0};

	TwoDimensionalShape(auto x, auto y){Position_x = x,Position_y = y;}; 		//constructor
	TwoDimensionalShape():TwoDimensionalShape(0,0){};

	virtual double Area() const = 0;
	virtual double Volume() const = 0;
	virtual void Print() const = 0;

};
#endif