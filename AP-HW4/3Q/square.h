#ifndef SQUARE_H
#define SQUARE_H

#include<iostream>
#include "TwoDimensionalShape.h"
#include "Point.h"

class Square : public TwoDimensionalShape {
public:
	double length{ 0 };										//Define length
	
	Square(auto l, auto x, auto y): TwoDimensionalShape(x, y) { this->length = l; };		//constructor
	Square(auto r):Square(r,0,0){};															//constructor override
	virtual double Area() const override{ return this->length*this->length; };;
	virtual double Volume() const override{return 0;};
	virtual void Print() const override
	{
		std::cout << "Square length = " << this->length << "\n";
		std::cout << "center-> (" << Position_x << ", " << Position_y << ")\n";
		std::cout << "area of " << 	this->Area() << std::endl;
	};

	//Define + operator
	Square operator+(const Point& p)
	{
	std::cout << "The cordinates of the center of the square was moved by "
		<< p.x_position << " along the x axis and " << p.y_position << " along the y axis" << std::endl;
	this->Position_x = this->Position_x + p.x_position;
	this->Position_y = this->Position_y + p.y_position;

	return *this;
	};
};

#endif // !SQUARE_H
//Define << operator
std::ostream& operator<<(std::ostream& os, Square& sqr){
	sqr.Print();
	return os;
};