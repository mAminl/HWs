#include<iostream>
#include"libArr.h"
#include"libVec.h"
#include <ctime>

template<typename T> long double runTime(T a,int n); // function wich works with object

template<typename T> long double runtime2(T a,int n); // function wich works with pointer


int main(){

	// object definition
	libArr a;
	libVec b;

	// output of runtime
	std::cout << "runtime is running ..." << std::endl <<std::endl;

	for(int i{1}; i < 1e7 ; i=i*10){

	std::cout << "Number of sequence is: "<< i << std::endl;

	std::cout << "runTime of libArr counter is: "<< runTime(a,i) << "mS" << std::endl;

	std::cout << "runTime of libVec counter is: "<< runTime(b,i) << "mS" << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	}

	// output of runtime2
	std::cout << "runtime2 is running ..." << std::endl <<std::endl;

	for(int i{1}; i < 1e7 ; i=i*10){

	std::cout << "Number of sequence is: "<< i << std::endl;

	std::cout << "runTime of libArr counter is: "<< runtime2(a,i) << "mS" << std::endl;

	std::cout << "runTime of libVec counter is: "<< runtime2(b,i) << "mS" << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	}


	return 0;
}

template <typename T>
long double runTime(T a,int n)
{
	long double time;
    time = std::clock();

 		a.counter(n);
 
    time = std::clock() - time;

return 100*(time)/CLOCKS_PER_SEC;
}

template <typename T>
long double runtime2(T a,int n)
{
	long (T::* ptr) (int) = &T::counter;
	long double time;
    time = std::clock();

 		(a.*ptr)(n);
 
    time = std::clock() - time;

return 1000*(time)/CLOCKS_PER_SEC;
}