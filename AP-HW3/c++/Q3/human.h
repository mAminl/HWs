#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class human
{
public:

	std::string	firstName;
	std::string lastName;
	int hairColor;
	int eyeColor;
	int age;
	bool gender;
	size_t numberOfChildren;
	size_t PopulationOfFamily{0};
	human* father = nullptr;
	human* mother = nullptr;
	human** children;
	human* spouse = nullptr;
	human* temp_child;


public:

	human(std::string firstName,std::string lastName,int hairColor,int eyeColor,int age,
		  bool gender,size_t numberOfChildren);		//costructor
	~human();		//destructor
	//get functions
	std::string getFirstName();
	std::string getLastName();
	bool getGender();
	int getHairColor();
	int getEyeColor();
	int getAge();
	//operators
	bool operator>(const human&);
	bool operator==(const human&);
	human* operator+(human*);
	void operator++();
	//check functions
	bool isChildOf(human*);
	bool isFatherOf(human*);
	bool isMotherOf(human*);
	void printChildren();
	
};


#endif