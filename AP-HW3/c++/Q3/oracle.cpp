#include<iostream>
#include<string.h>
#include"human.h"
#include"oracle.h"

//consstructor
oracle::oracle(std::string name):human(name,name,0,0,0,0,0){
	family = new human*[1];
}
//destructor
oracle::~oracle(){
	delete[] family;
}
//marriage function
bool oracle::marry(human* p1,human* p2){
	if((p1->spouse == nullptr) && (p2->spouse == nullptr) && (p1->age > 17) && (p2->age > 17)){
		p1->spouse = p2;
		p2->spouse = p1;
		return true;
	}
	else return false;
}

//check near family
bool oracle::isFamily(human* p1,human* p2){
	if((p1->lastName == p2->lastName) || (p1->lastName == p2->spouse->lastName) ||
	 (p1->lastName == p2->spouse->father->lastName) || 
	 (p1->lastName == p2->spouse->mother->lastName) || (p1->lastName == p2->mother->lastName)
	 || (p1->mother->lastName == p2->lastName) || (p1->mother->lastName == p2->spouse->lastName) ||
	 (p1->mother->lastName == p2->spouse->father->lastName) || 
	 (p1->mother->lastName == p2->spouse->mother->lastName) || 
	 (p1->mother->lastName == p2->mother->lastName))
	return true;
	else return false;
}

//set child
void oracle::setChild(human* child,human* papa,human* mom){

	child->father = papa;
	child->mother = mom;
	child->father->numberOfChildren = child->father->numberOfChildren + 1;
	child->mother->numberOfChildren = child->mother->numberOfChildren + 1;
	human** temp;
    temp = new human*[child->father->numberOfChildren];
    for(size_t i{};i < child->father->numberOfChildren - 1;i++)
    	temp[i] = child->father->children[i];

    delete[] child->father->children;
    delete[] child->mother->children;
    children = new human*[child->father->numberOfChildren];
    temp[numberOfChildren - 1] = child;
    for(size_t i{};i < child->father->numberOfChildren;i++)
    	child->father->children[i] = temp[i];
    for(size_t i{};i < child->mother->numberOfChildren;i++)
    	child->mother->children[i] = temp[i];
}

//find and get family
human** oracle::getFamily(human* person){
	population = person->numberOfChildren + person->father->numberOfChildren + 1;   //for population
	delete[] family;
	family = new human*[population] ;
	size_t counter{0};
	for ( ;counter < person->numberOfChildren; counter++)
	{
		family[counter] = person->children[counter];
	}
	for (size_t i{0}; i < person->father->numberOfChildren -1 ; i++)
	{
		counter = counter + i;
		if(person->father->children[i]->firstName != person->firstName)
			family[counter] = person->father->children[i];
		else
			counter--;
	}
	if(person->spouse){
		
		for (size_t i{0}; i < person->spouse->father->numberOfChildren -1 ; i++)
		{
			counter = counter + i;
			if(person->spouse->father->children[i]->firstName != person->firstName)
				family[counter] = person->spouse->father->children[i];
			else
				counter--;
		}
	}
	family[population - 2] = person->father;
	family[population - 1] = person->mother;
	person->PopulationOfFamily = population;
	return family;
}

size_t oracle::getPopulationOfFamily(human* person){
	return person->PopulationOfFamily;
}

