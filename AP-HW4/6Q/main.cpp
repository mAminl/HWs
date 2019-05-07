// HW4-1.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<set>

int main()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5, 4, 3, 2, 1};			//initialization
	std::cout << "The Original Vector is:" << std::endl;
	for (int element : vec)
		std::cout << element << ",";
	std::cout << std::endl;

	std::set<int> my_set;										//define  a set
	for (int element : vec)
		my_set.insert(element);

	//Remove element by remove()
	std::remove(begin(vec), end(vec), 2);
	std::cout << "The Vector after use remove function by value 2:" << std::endl;
	for (int element : vec)
		std::cout << element << ",";
	std::cout << std::endl;

	//Remove element in right way
	auto first_to_erase{ std::remove_if(begin(vec), end(vec), [&](int vec) { return vec == 2; }) };
	vec.erase(first_to_erase, end(vec));
	std::cout << "The Vector after use remove_if function by value 2:" << std::endl;
	for (int element : vec)
		std::cout << element << ",";
	std::cout << std::endl;
	
	//multiple elements by 2
	std::vector<int> x2(vec.size());
	std::transform(vec.begin(), vec.end(), x2.begin(), [](auto& c) {return c * 2; });
	std::cout << "The Vector after multipel its value by 2:" << std::endl;
	for (int element : x2)
		std::cout << element << ",";
	std::cout << std::endl;

	//calculate average
	float average = std::accumulate(vec.begin(), vec.end(), 0.0 / vec.size())/ vec.size();
	//std::cout << average << std::endl;
	std::sort(vec.begin(), vec.end(),std::less<>()); //important
	std::sort(vec.begin(), vec.end(),
			 [&average](int& x, int& y) {return abs(x - average) < abs(y - average); });

	//sort by distance to mean
	std::cout << "The Vector after sort its value by distance to average:" << std::endl;
	for (int element : vec)
		std::cout << element << ",";
	std::cout << std::endl;

	//delete repititive elements
	sort( vec.begin(), vec.end() );
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
	std::cout << "Repetitive values are cleared:" << std::endl;
	for (int element : vec)
		std::cout << element << ",";
	std::cout << std::endl;

	//put vector elements to set
	std::cout << "Desired Set is:" << std::endl;
	for (int element : my_set)
		std::cout << element << ",";
	std::cout << std::endl;

	//erase undesired elements form set
	my_set.erase(std::find(my_set.begin(), my_set.end(),3), my_set.end());
	std::cout << "Valuse wich are bigger than 3 are removed:" << std::endl;
	for (int element : my_set)
		std::cout << element << ",";
	std::cout << std::endl;

	return 0;
}