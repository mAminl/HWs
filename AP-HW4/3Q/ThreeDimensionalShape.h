#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"


class ThreeDimensionalShape : public Shape{
public:
	//Define center position elements
	double Position_x{0};
	double Position_y{0};
	double Position_z{0};

	ThreeDimensionalShape(auto x, auto y, auto z){Position_x = x,Position_y = y,Position_z = z;};	//Constructor
	ThreeDimensionalShape():ThreeDimensionalShape(0,0,0){};											//Constructor Override

	virtual double Area() const = 0;
	virtual double Volume() const = 0;
	virtual void Print() const = 0;

};
#endif