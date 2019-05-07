#ifndef CUBE_H
#define CUBE_H

#include<iostream>
#include "ThreeDimensionalShape.h"
#include "Point.h"

class Cube : public ThreeDimensionalShape {
public:
	double length{ 0 };					//Length of cube
	
	Cube(auto l, auto x, auto y,auto z) : ThreeDimensionalShape(x, y, z){this->length = l;};     //Cube constructor
	Cube(auto l):Cube{l,0,0,0}{};																 //Cube constructor override
	virtual double Area() const override { return 6*this->length*this->length; };
	virtual double Volume() const override { return this->length*this->length*this->length; };
	virtual void Print() const {
	std::cout << "Cube side length = " << this->length << "\n";
	std::cout << "center-> (" << this->Position_x << ", " << this->Position_y << ", " << this->Position_z << ")\n";
	std::cout << "area of " << this->Area() << " & volume of " << this->Volume() << std::endl;
};

	Cube operator+(const Point& p)										//Define + Operator
{
	std::cout << "The cordinates of the center of the cube was moved by "
		<< p.x_position << " along the x axis and " << p.y_position << " along the y axis and "
		<< p.z_position << " along the z axis\n";
	this->Position_x += p.x_position;
	this->Position_y += p.y_position;
	this->Position_z += p.z_position;

	return *this;
};

};
#endif

//Define << Operator
std::ostream& operator<<(std::ostream& os, Cube& cub){
	cub.Print();
	return os;
}
