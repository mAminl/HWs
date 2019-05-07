#ifndef CTEXT_H
#define CTEXT_H

#include <cstring>


class CText{
public:
	std::string text;
	CText(auto input){text = input;}			//Constructor
	std::string getText(){return text;}			//Return text
};

#endif