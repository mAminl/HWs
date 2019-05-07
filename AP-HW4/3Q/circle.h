#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include "TwoDimensionalShape.h"
#include "Point.h"


class Circle : public TwoDimensionalShape {
public:
	double radious{ 0 };				// Define Radious of circle

	Circle(auto r, auto x, auto y): TwoDimensionalShape(x, y) { this->radious = r; };		//Constructor
	Circle(auto r):Circle(r,0,0){};															//Constructor Override
	virtual double Area() const override{ return 3.14*this->radious*this->radious; };		//calculate Area
	virtual double Volume() const override{return 0;};										//Volume od tow dimentional object is zero
	virtual void Print() const override{std::cout << "Circle radius = " << this->radious << "\n";
										std::cout << "center-> (" << Position_x << ", " << Position_y << ")\n";
										std::cout << "area of " << 	this->Area() << std::endl;};

	Circle operator+(const Point& p)			//Define + Operatgor
{
	std::cout << "The cordinates of the center of the cirlce was moved by "
		<< p.x_position << " along the x axis and " << p.y_position<< " along the y axis\n";
	this->Position_x = this->Position_x + p.x_position;
	this->Position_y = this->Position_y + p.y_position;

	return *this;
};


};
#endif

//Define << Operator
std::ostream& operator<<(std::ostream& os, Circle& circ){
	circ.Print();
	return os;
};
