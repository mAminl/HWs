#include "MAP.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include<algorithm>


MAP::MAP(int n){

	// make map dynamic array:
	N = n;
	main_map = new int*[N];

	for(int i{} ; i < N ; i++){

		main_map[i] = new int[N];

		for(int j{} ; j < N ; j++){

			main_map[i][j] =  (std::rand()%100) + 1;
		}
	}

}



void MAP::showmap (){

	std::cout << "city map is: " << std::endl;
	for(int i{} ; i < N ; i++){

		for(int j{} ; j < N ; j++)

			std::cout << std::setw(4) << main_map[i][j];

		std::cout << std::endl;
	}

}



void MAP::AllRoutes(){

	long long  f; // # of states
	int x{}; // x component of map tabel

	f = factorial(2 * (N-1)) / (factorial(N-1) * factorial(N-1));

	all_route = new char*[f];

	for(long long i{} ; i<f ; i++)

		all_route[i] = new char[2*(N-1)];
	

	for(int j{} ; j < 2 * (N-1) ; j++){

			if(j < N-1)
			all_route[0][j] = 'r';

			else
			all_route[0][j] = 'd';
}


	std::sort(&all_route[0][0] , &all_route[0][2 * (N-1)]);


	do {
		for(int i{}; i< 2 * (N-1); i++){

			all_route[x][i] = all_route[0][i];
		}
		x++;

	} while (std::next_permutation(&all_route[0][0] , &all_route[0][2 * (N-1)]));

	

	// if you want to see all states run below codes!

	/*for(long long i{}; i < f ; i++){

		for(int j{} ; j < 2 * (N-1) ; j++)
	  		std::cout << std::setw(4) << all_route[i][j] ;

	 std::cout<<std::endl;

	 }*/

}

void MAP::FindBest(){

	long long f{}; // number of all states
	int x{}; // x component of map tabel
	int y{}; // y component of map tabel
	int Distance{};
	int min_Distance{};
	int route[2*N - 1];
	int Best_route[2*N - 1];

	//computing number of states:
	f = factorial(2*(N-1))/(factorial(N-1)*factorial(N-1));

	//initiakize route:
	route[0] = main_map[0][0];

	for(long long c{}; c < f ; c++){

		//route extracting
		for(int i{}; i < 2*(N-1) ; i++){

			if(all_route[c][i] == 'd'){
				
				route[i+1] = main_map[x+1][y];
				x++;
			}
			else{
				
				route[i+1] = main_map[x][y+1];
				y++;

			}
		}

		//computing route distance:
		for(int i{} ; i < (2 * (N-1)) ; i++)
			Distance = abs(route[i] - route[i + 1]) + Distance;

		//Find min distance:
		if(c == 0){
			min_Distance = Distance;

			for(int i{}; i < 2*N - 1 ; i++)
				Best_route[i] = route[i];
		}
		else {

			if(Distance < min_Distance){
				min_Distance = Distance;
				for(int i{}; i < 2*N - 1 ; i++)
					Best_route[i] = route[i];
			}
		}
	
	x = 0;
	y = 0;
	Distance = 0;

	}

	std::cout << "Best route for min distance is:" << std::endl;

	for(int a : Best_route)
		std::cout<< a << std::setw(4);

	std::cout<<std::endl;
	std::cout << "Min Distance is: " << min_Distance << std::endl;

	// Ready for showmap:
	main_map[0][0] = 101;
	for(int j{1}; j < 2*N - 2 ; j++){
		if(main_map[x+1][y] == Best_route[j]){
			main_map[x+1][y] = 101;
			x++;
		}
		else{
			main_map[x][y+1] = 101;
			y++;
		}

	}


}

long long MAP::factorial(int n){

	F = n;
	if (F == 1) return 1LL;
	return F* factorial(F - 1);
}

void MAP::showroute(){

	//make dynamic char array:
	char** routefind{new char*[N]};

	for(int i{} ; i < N ; i++)
		routefind[i] = new char[N];

	// determine min distance route:
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

	routefind[N-1][N-1] = '*';

	// cout route
	for(int i{} ; i < N ; i++){

		for(int j{} ; j < N ; j++)

			std::cout << std::setw(4) << routefind[i][j];

		std::cout << std::endl;
	}

	// remove dynamic arr:
	for(int i{} ; i < N ; i++)

		delete[] routefind[i];

	delete[] routefind;

}


MAP::~MAP(){

	for(int i{} ; i < N ; i++)

		delete[] main_map[i];

	delete[] main_map; 

	for(int i{} ; i < 2 * (N-1) ; i++)

		delete[] all_route[i];

	delete[] all_route; 

}