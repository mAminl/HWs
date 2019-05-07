// HW4-1.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<vector>
#include<algorithm>

int main()
{	
	//initialization Vector with random int numbers less than 50
	std::vector<int> a(50);
	std::generate(a.begin(), a.end(), []() {
		return rand() % 50;
	});

	std::vector<int> b(50);
	std::generate(b.begin(), b.end(), []() {
		return rand() % 50;
	});

	//Show b
	std::cout << "b is: " << std::endl;
	for (int element : b) 
		std::cout << element << ",";
	std::cout << std::endl;

	//erase repitative number from b
	sort( b.begin(), b.end() );
	b.erase( unique( b.begin(), b.end() ), b.end() );
	std::cout << "b after remove repitative elements: " << std::endl;
	for (int element : b)
		std::cout << element << ",";
	std::cout << std::endl;

	std::cout << "b  size after remove repitative elements is: " << b.size() << std::endl;

	//make c such that number between 0 - 50 is there with random position
	std::vector<int> c;
	for (size_t i = 0; i < 50; ++i)
		c.push_back(i + 1);
	std::random_shuffle(c.begin(), c.end());
	std::cout << "c is: " << std::endl;
	for (int element : c)
		std::cout << element << ",";
	std::cout << std::endl;

	//make c and a elemant power 2 
	std::transform(c.begin(), c.end(), c.begin(), [](auto& unit) {return unit * unit; });
	std::transform(a.begin(), a.end(), a.begin(), [](auto& unit) {return  unit * unit; });
	//show c
	std:: cout << "<c,c> is: " << std::endl;
	for (int element : c)
		std::cout << element << ",";
	std::cout << std::endl;

	//minus a and c
	std::transform(a.begin(), a.end(), c.begin(), a.begin(), std::minus<int>()); 
	std::cout << "<a,a> minus <c,c> is: " << std::endl;
	for (int element : a)
		std::cout << element << ",";
	std::cout << std::endl;

	
	return 0;
}