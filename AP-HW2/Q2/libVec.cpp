#include<iostream>
#include"libVec.h"
#include<vector>

long libVec::counter(int n){

	std::vector<long> vec{1};

	long sum{vec[0]};

	for(int i{1}; i < n; i++){

		vec.push_back(i+1);
		sum = sum + vec[i];
	}

return sum;
}