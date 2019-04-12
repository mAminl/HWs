#ifndef ORACLE_H
#define ORACLE_H

#include<iostream>
#include<string.h>
#include"human.h"


class oracle : public human
{
public:
	oracle(std::string name);		//constructor
	~oracle();						//destructor
	human** family;
	size_t population{0};
	bool marry(human*,human*);
	bool isFamily(human*,human*);
	void setChild(human*,human*,human*);
	human** getFamily(human*);
	size_t getPopulationOfFamily(human*);

};

#endif