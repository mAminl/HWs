#include<iostream>
#include"my_vector.h"
#include<utility>

using namespace std::rel_ops;


int main(){

	//creat vectores
	my_vector a(7);
	my_vector b(5);
	my_vector f(6);
	my_vector g(0);
	my_vector h();

	//using push_back
	for(size_t i{}; i < 20 ; i++){
		a.push_back(i);
	}
	for(size_t i{}; i < 10 ; i++){
		b.push_back(i);
	}

	//show vectors
	a.show();
	b.show();

	//inner product and show
	my_vector c( a * b );
	c.show();

	//use copy constructor
	my_vector d(a);
	d.show();

	//useing operators
	f = d + c;
	f.show();

	//using equal operator
	g = a ;
	g.show();

	//compare
	if(a < b)
		std::cout << "a is smaller" << std::endl;
	
	//show pop_back
	a.pop_back();
	a.show();

	return 0;
}