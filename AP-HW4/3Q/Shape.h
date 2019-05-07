#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Point.h"

class Shape
{
public:
	Shape();							//defualt constructor
	virtual double Area() const = 0;
	virtual double Volume() const = 0;
	virtual void Print() const = 0;
	friend std::ostream& operator<<(std::ostream& os, Shape& shape) {
		   shape.Print();
	return os;
	}

};

#endif