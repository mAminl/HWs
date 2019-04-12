#include<iostream>
#include<iomanip>
#include"my_vector.h"

my_vector::my_vector(int n){
	size = 1;
	element = new int[size]{n};
	std::cout << "constructor is called!" << std::endl;
}

my_vector::my_vector(){
	my_vector(0);
}

my_vector::my_vector(const my_vector& vec){
	std::cout << "copy constructor is called!" << std::endl;
	size = vec.size;
	capacity = vec.capacity;
	element = new int[size]{0};
	for(size_t i{}; i < size; i++)		//copy element by element
		element[i] = vec.element[i];
}

my_vector::my_vector(my_vector&& vec){
	std::cout << "move constructor is called!" << std::endl;
	size = vec.size;
	capacity = vec.capacity;
	delete[] element;
	element = vec.element;
	vec.element = nullptr;		//move constructor
}

my_vector::~my_vector(){
	std::cout << "destructor is called!" << std::endl;
	delete[] element; 
}

void my_vector::push_back(int a){
	int* temp;
	capacity = size * 2;		//calculate capacity
	temp = new int[capacity];
	for(size_t i{}; i < size ; i++){		//copy element by element
		temp[i] = element[i];
	}
	delete[] element;
	temp[size] = a;
	size++;

	element = new int[capacity];
	for(size_t i{}; i < size ; i++){		//copy element by element
		element[i] = temp[i];
	}
	delete[] temp;
}

void my_vector::pop_back(){
	int* temp;
	capacity = (size - 1) * 2;		//calculate capacity
	temp = new int[capacity];
	for(size_t i{}; i < size ; i++){		//copy element by element
		temp[i] = element[i];
	}
	delete[] element;
	temp[size] = 0;
	size--;

	element = new int[capacity];
	for(size_t i{}; i < size ; i++){		//copy element by element
		element[i] = temp[i];
	}
	delete[] temp;

}

bool my_vector::operator<(const my_vector& vec) const {
	std::cout << "operator< is called" << std::endl;
	double mag1{};		//temporary objects to find longer
	double mag2{};

	for(size_t i{}; i < size;i++)
		mag1 = (element[i] * element[i]) + mag1;
	for (size_t i{}; i < vec.size; i++)
		mag2 = (vec.element[i] * vec.element[i]) + mag2;

	return mag1 < mag2 ;
}

bool my_vector::operator==(const my_vector& vec) const {
	std::cout << "operator== is called" << std::endl;
	double mag1{};		//temporary objects to find longer
	double mag2{};

	for(size_t i{}; i < size;i++)
		mag1 = (element[i] * element[i]) + mag1;
	for (size_t i{}; i < vec.size; i++)
		mag2 = (vec.element[i] * vec.element[i]) + mag2;

	return mag1 == mag2 ;
}

my_vector my_vector::operator+(const my_vector& vec){
	std::cout << "operator+ is called" << std::endl;
	size_t sum_size{};
	my_vector sum(element[0] + vec.element[0]);

	//find longest one and use it...
	if(size > vec.size){
		sum_size = size;
		for(size_t i{1}; i < vec.size; i++)
			sum.push_back (element[i] + vec.element[i]);
		for(size_t i{vec.size}; i < sum_size; i++)
			sum.push_back (element[i]);
	}
	else{
		sum_size = vec.size;
		for(size_t i{1}; i < size; i++)
			sum.push_back(element[i] + vec.element[i]);
		for(size_t i{size}; i < sum_size; i++)
			sum.push_back(vec.element[i]);
	}

	return sum;
}

my_vector& my_vector::operator=(const my_vector& vec){
	std::cout << "operator= is called" << std::endl;
	if(this == &vec)
		return *this;
	size = vec.size;
	capacity = vec.capacity;
	delete[] element;
	element = new int[size]{0};

	for(size_t i{}; i < size; i++)		//copy element by element
		element[i] = vec.element[i];

	return *this ;
}

my_vector& my_vector::operator=(my_vector&& vec){
	std::cout << "operator= move version is called" << std::endl;
	size = vec.size;
	capacity = vec.capacity;
	delete[] element;

	element = vec.element;
	vec.element = nullptr;		//move version

	return *this;
}

my_vector my_vector::operator*(const my_vector& vec){
	std::cout << "operator* is called" << std::endl;
	size_t ip_size{};
	my_vector ip(element[0] * vec.element[0]);

	//find longest
	if(size > vec.size){
		ip_size = size;
		for(size_t i{1}; i < vec.size; i++)
			ip.push_back (element[i] * vec.element[i]);
		for(size_t i{vec.size}; i < ip_size; i++)
			ip.push_back (0);
	}
	else{
		ip_size = vec.size;
		for(size_t i{1}; i < size; i++)
			ip.push_back(element[i] * vec.element[i]);
		for(size_t i{size}; i < ip_size; i++)
			ip.push_back(0);
	}

	return ip;
}

void my_vector::show(){
	for(size_t i{}; i < size ; i++)
		std::cout << std::setw(4) << element[i];
	std::cout << std::endl;
}
