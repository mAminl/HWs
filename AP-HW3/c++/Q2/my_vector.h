#ifndef MY_VECTOR_H
#define MY_VECTOR_H


class my_vector{

public:
	int* element;  //pointer for dynamic memmory allocation
	size_t capacity{};
	size_t size; // length of vector

	my_vector(int n); //constructor
	my_vector();		//constructor
	my_vector(const my_vector&);		//copy constructor
	my_vector(my_vector&&);		//move constructor
	~my_vector();		//destructor
	void push_back(int a);		//add to vector
	void pop_back();		//remove from end of the list
	void show();		//print vector elements
	bool operator<(const my_vector&) const ;
	bool operator==(const my_vector&) const ;
	my_vector operator+(const my_vector&);
	my_vector& operator=(const my_vector&);
	my_vector& operator=(my_vector&&);		//move version
	my_vector operator*(const my_vector&);		//inner product
};


#endif