#include<iostream>
#include<iomanip>
#include<string>
#include <cstdlib> 
#include"human.h"

//constructor
human::human(std::string fN,std::string lN,int hC,int eC,int a,bool g
		,size_t numOfC){
	//std::cout << "constructor is called" << std::endl;
	firstName = fN;
	lastName = lN;
	hairColor = hC;
	eyeColor = eC;
	age = a;
	gender = g;
	numberOfChildren = numOfC;
	children = new human*[numberOfChildren];		//allocate dynamic memory

}

//destructor
human::~human(){
	//std::cout << "distructor is called" << std::endl;
	delete[] children;
}

std::string human::getFirstName(){
	return firstName;
}

std::string human::getLastName(){
	return lastName;
}

bool human::getGender(){
	if(gender)
		std::cout << "Gender is male" << std::endl;
	else
		std::cout << "Gender is female" << std::endl;
	return gender;
}

int human::getHairColor(){
	std::cout << "hairColor is: " << hairColor << std::endl;
	return hairColor;
}

int human::getEyeColor(){
	std::cout << "eyeColor is: " << eyeColor << std::endl;
	return eyeColor;

}

int human::getAge(){
	std::cout << "age is: " << age << std::endl;
	return age;
}

bool human::operator>(const human& person){
	return age > person.age;
}

human* human::operator+(human* person){
	
	spouse = person;				//set spouse
	person->spouse = this;
	human** temp;
    temp = new human*[numberOfChildren + 1];
    for(size_t i{};i < numberOfChildren;i++)
    	temp[i] = children[i];
   
    numberOfChildren++;
    person->numberOfChildren++;
    
    delete[] children;
    delete[] person->children;
    children = new human*[numberOfChildren];
   
   //make child
	std::srand((unsigned)time(0)); 
    int random_integer = rand();
    human* child{new human("baby",lastName,person->hairColor,eyeColor,0,gender,0)};
    if(gender){
    	if(random_integer % 2){
			child->firstName = person->firstName;
			child->hairColor = hairColor;
			child->eyeColor = person->eyeColor;
			child->gender = person->gender;
    	}
		
    }
    else{
    	if(random_integer % 2){
    		child->firstName = spouse->firstName;
			child->eyeColor = person->eyeColor;
		}
		else{
			child->firstName = person->firstName;
			child->hairColor = hairColor;
			child->eyeColor = person->eyeColor;
			child->gender = person->gender;
		}
    }

    child->father = this;
    child->mother = spouse;
    temp[numberOfChildren - 1] = child;
    
    for(size_t i{};i < numberOfChildren;i++)
    	children[i] = temp[i];
    for(size_t i{};i < spouse->numberOfChildren;i++)
    	spouse->children[i] = temp[i];
    
    delete[] temp;
    
    return child;
}

bool human::operator==(const human& person){
	//std::cout << "operator == is called " << std::endl;
	return (firstName == person.firstName) && (lastName == person.lastName) &&
	 (age = person.age) && (eyeColor == person.eyeColor);
}

void human::operator++(){
	//std::cout << "operator ++ is called " << std::endl;
	age++;
}

bool human::isChildOf(human* person){

	return (person->lastName == lastName) && (person->firstName == father->firstName);
	
}

bool human::isFatherOf(human* person){

	return (person->lastName == lastName) && (person->father->firstName == firstName);
}

bool human::isMotherOf(human* person){

	return (person->mother->firstName == mother->firstName) && 
		(spouse->firstName == person->father->firstName) && 
		(spouse->lastName == person->father->lastName);
}

void human::printChildren(){
	for(size_t i{};i < numberOfChildren ;i++)
		std::cout << children[i]->firstName << std::endl;
}
