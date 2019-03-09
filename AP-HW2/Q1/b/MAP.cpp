#include "MAP.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>


MAP::MAP(int n){

	// make  map dynamic array:	
	N = n;
	main_map = new int*[N];

	for(int i{} ; i < N ; i++){

		main_map[i] = new int[N];

		for(int j{} ; j < N ; j++){

			main_map[i][j] =  (std::rand()%100) + 1;
		}
	}

}



void MAP::showmap ()
	{

	std::cout << "city map is: " << std::endl;
	for(int i{} ; i < N ; i++){

		for(int j{} ; j < N ; j++)

			std::cout << std::setw(4) << main_map[i][j];

		std::cout << std::endl;
	}

}



void MAP::findroute(){

	int x{}; // x component of map tabel
	int y{}; // y component of map tabel
	int Distance{};
	int s = N - 1; // maximum step toward one side
	std::vector<int> route;

	route.push_back(main_map[0][0]);
		
	for(int i{1} ; i < (2*(N - 1) + 1) ; i++){

		if((x<s) & (y<s)){

			if((abs(main_map[x+1][y] - main_map[x][y]) < abs(main_map[x][y+1] - main_map[x][y])) & (abs(main_map[x+1][y] - main_map[x][y]) < abs(main_map[x+1][y+1] - main_map[x][y])))
			{

				route.push_back(main_map[x+1][y]);
				main_map[x][y] = 101;
				x++;
			}

			else if((abs(main_map[x][y+1] - main_map[x][y]) < abs(main_map[x+1][y] - main_map[x][y])) & (abs(main_map[x][y+1] - main_map[x][y]) < abs(main_map[x+1][y+1] - main_map[x][y])))
			{
				route.push_back(main_map[x][y+1]);
				main_map[x][y] = 101;
				y++;

			}

			else{

				route.push_back(main_map[x+1][y+1]);
				main_map[x][y] = 101;
				x++;
				y++;
			}

		}

		else if((x<s) & (y>=s)){

			route[i] = main_map[x+1][y];
			main_map[x][y] = 101;
			x++;
		}

		else if((y<s) & (x>=s)){

			route[i] = main_map[x][y+1];
			main_map[x][y] = 101;
			y++;
		}
	}

	std::cout << "your route is: " << std::endl;
	for(int a : route)
		std::cout << a << std::setw(4);

	std::cout << std::endl;
	
	for(size_t i{} ; i < (route.size() - 1) ; i++)
		Distance = abs(route[i] - route[i+1]) + Distance;

	main_map[N - 1][N - 1] = 101;

	std::cout << "Distance: " << Distance << std::endl;

}


void MAP::showroute(){

	// make an char dynamic array:
	char** routefind{new char*[N]};

	for(int i{} ; i < N ; i++)
		routefind[i] = new char[N];

	
	for(int i{} ; i < N ; i++){

		for(int j{} ; j < N ; j++){

			if(main_map[i][j] == 101){

				routefind[i][j] = '*';
			}
				
			else{

				routefind[i][j] = '-';

			}
		}
	}

	for(int i{} ; i<N ; i++){

		for(int j{} ; j<N ; j++)

			std::cout << std::setw(4) << routefind[i][j];

		std::cout << std::endl;
	}

	// remove dynamic arr:
	for(int i{} ; i < N ; i++)

		delete[] routefind[i];

	delete[] routefind;

}


MAP::~MAP(){

	for(int i{} ; i<N ; i++)

		delete[] main_map[i];

	delete[] main_map; 

}