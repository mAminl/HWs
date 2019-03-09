#include <iostream>
#include "MAP.h"


int main(){

	int n; // size of map
	
	std::cout << "Please Enter size of map(n for n*n): " << std::endl;
	std::cin >> n;

	MAP a(n) ; // make an object

	a.showmap();
	a.AllRoutes();
	a.FindBest();
	a.showroute();
	
	return 0;
}
