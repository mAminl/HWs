#include<iostream>
#include<array>
#include"libArr.h"

long libArr::counter(int n){

	int arr[n]{};

	long sum{};

	for(int i{}; i < n; i++){

		arr[i] = i + 1;
		sum = sum + arr[i];
	}

return sum;
}
