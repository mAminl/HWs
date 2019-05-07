#ifndef SPHERE_H
#define SPHERE_H

#include<iostream>
#include "ThreeDimensionalShape.h"
#include "Point.h"


class Sphere : public ThreeDimensionalShape {
public:
	double radious{ 0 };									//Define sphere radious
	
	Sphere(auto r, auto x, auto y,auto z) : ThreeDimensionalShape(x, y, z){this->radious = r;};		//Constructor
	Sphere(auto r,auto x, auto y):Sphere{r,x,y,0}{};												//Constructor Override
	Sphere(auto r):Sphere{r,0,0,0}{};																//Constructor Override
	virtual double Area() const override { return 4*this->radious*this->radious; };
	virtual double Volume() const override { return 4/3*3.14*this->radious*this->radious*this->radious; };
	virtual void Print() const 
	{
	std::cout << "Sphere radious length = " << this->radious << "\n";
	std::cout << "center-> (" << this->Position_x << ", " << this->Position_y << ", " << this->Position_z << ")\n";
	std::cout << "area of " << this->Area() << " & volume of " << this->Volume() << std::endl;
	}

	//Define + Operator
	Sphere operator+(const Point& p)
	{
	std::cout << "The cordinates of the center of the sphere was moved by "
		<< p.x_position << " along the x axis and " << p.y_position << " along the y axis and "
		<< p.z_position << " along the z axis" << std::endl;
	this->Position_x += p.x_position;
	this->Position_y += p.y_position;
	this->Position_z += p.z_position;

	return *this;
	};
};

#endif

//Define << operator
std::ostream& operator<<(std::ostream& os, Sphere& sphr)
{
	sphr.Print();
	return os;
};