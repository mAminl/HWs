#include <iostream>
#include <string>
#include <memory>
#include <vector>

template<typename T>
void show(std::vector<std::unique_ptr<T>>&);

int main()
{
	std::vector<std::unique_ptr<std::string>> vec(1000);

	//initialation
	for (size_t i{ 0 }; i < 1000; i++) {
		vec.push_back(std::make_unique<std::string>("Str " + std::to_string(i)));
		show(vec);
	}

	vec.reserve(1000);			//use reserve;
	std::cout << " *** Result by using reserve() ***" << std::endl;
	for (size_t i{ 0 }; i < 1000; i++) {
		vec.push_back(std::make_unique<std::string>("Str " + std::to_string(i)));
		show(vec);
	}


	return 0;
}
//Show function to print capacity and size
template<typename T>
void show(std::vector<std::unique_ptr<T>>& v) {
	std::cout << "Size is: " << v.size() << "  ***  ";
	std::cout << "Capacity is: " << v.capacity() << std::endl;
}