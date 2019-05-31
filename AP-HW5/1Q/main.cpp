#include<iostream>
#include<vector>
#include <numeric>
#include<algorithm>
#include <iterator>


int main(){
	
	//Making Vec1
	std::vector<int> vec1( 100 );
	std::iota( std::begin( vec1 ), std::end( vec1 ), 1 );
	std::cout << "Vec1 is:" << std::endl;
	for(int x:vec1){
		std::cout << x << " ";;
	}
	std::cout << std::endl;

	//making vec2
	std::vector<int> vec2( 10 );
	std::iota( std::begin( vec2 ), std::end( vec2 ), 1 );
	std::cout << "Vec2 is:" << std::endl;
	for(int x:vec2){
		std::cout << x << " ";;
	}
	std::cout << std::endl;

	//add vec1 to vec2
	vec2.insert(vec2.end(), vec1.begin(), vec1.end());
	std::cout << "Vec1 is added to vec2:" << std::endl;
	for(int x:vec2){
		std::cout << x << " ";;
	}
	std::cout << std::endl;

	//remove even number
	std::vector<int> odd_vec(200);
	auto it = std::copy_if (vec1.begin(), vec1.end(), odd_vec.begin(), [](int i){return i%2==1;} );
  	odd_vec.resize(std::distance(odd_vec.begin(),it));
  	std::cout << "odd_vec is:" << std::endl;
	for(int x:odd_vec){
		std::cout << x << " ";;
	}

	//reversing
	std::cout << std::endl;
  	std::vector<int> reverse_vec(100);
  	std::copy(vec1.rbegin(),vec1.rend(),reverse_vec.begin());
  	std::cout << "Reverse vector is:"<<std::endl;
	for(int x:reverse_vec){
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::cout << "Print vec1 without using for:" << std::endl;
	std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}