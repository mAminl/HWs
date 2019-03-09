#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include"information.h"


int main(){

	std::string date{}; // for data in db.txt
	int product_ID{};	// for #product in db.txt
	int costumer_ID{};	// for #costumer in db.txt
	int c{}; // argoman of alldates
	bool rep_found{false}; // A boolean for fin repeats
	std::string del{}; // An string for temporary values in db.txt
	std::vector<information> allData{}; // for storing data in object of class
	std::vector<std::string> alldates{}; // for saving diffrent dates
	std::vector<int> allcostumer{}; // for saving diffrent #costumers
	std::vector<int> allproduct; // for saving diffrent #products

	// Reading text file:
	std::ifstream input{"db.txt"};
		while (!input.eof())
		{
        	std::getline(input, del, '[');
       		std::getline(input, date, ' ');
        	std::getline(input, del, ' ');
			input >> product_ID;
        	input >> costumer_ID;
        	information a(date, product_ID, costumer_ID);
        	allData.push_back(a);
		}
    input.close();
    	
    //initializing list:
    alldates.push_back(allData[0].date);
    allcostumer.push_back(allData[0].costumer_ID);
    allproduct.push_back(allData[0].product_ID);

    //opening output text file:
    std::ofstream output{};
	output.open("dbnew.txt", std::ofstream::app);


	//for finding new values and writing them in text file:
    for(size_t i{1}; i < size(allData) ; i++){

    	if (alldates[c] != allData[i].date){

    		output << alldates[c] << " ";
    		output << size(allproduct) << " " << size(allcostumer) << std::endl;

    		alldates.clear();
    		allcostumer.clear();
    		allproduct.clear();

			alldates.push_back(allData[i].date);
			allcostumer.push_back(allData[i].costumer_ID);
			allproduct.push_back(allData[i].product_ID);

		}

		else{
			for(size_t j{0}; j < size(allcostumer) ; j++)
				if(allcostumer[j] == allData[i].costumer_ID)
					rep_found = true;

			if(!rep_found){
				allcostumer.push_back(allData[i].costumer_ID);
				rep_found = false;
			}

			rep_found = false;
			
			for(size_t j{0}; j < size(allproduct) ; j++)
				if(allproduct[j] == allData[i].product_ID)
					rep_found = true;
			if(!rep_found){
				allproduct.push_back(allData[i].product_ID);	
				rep_found = false;
			}	
		}
    }

    // writing last new values
    output << alldates[c] << " ";
    output << size(allproduct) << " " << size(allcostumer) << std::endl;
    output.close();

return 0;
}
