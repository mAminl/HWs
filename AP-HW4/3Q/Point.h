#ifndef POINT_H
#define POINT_H


class Point
{
public:
	Point(auto x, auto y, auto z){x_position = x,y_position = y,z_position = z;};   //Constructor
	Point(auto x, auto y):Point(x,y,0){};											//Constructor override
	Point():Point(0,0,0){};															//Constructor override
	double x_position;
	double y_position;
	double z_position;
};

#endif