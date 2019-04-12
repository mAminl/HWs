#include<iostream>
#include<string>
#include"human.h"
#include"oracle.h"

int main() {
    //create object
    human p1("ALI","BAHADORI", 4, 3, 25, 0, 0);
    human p2("BAHAR", "SHAMS", 1, 2, 22, 1, 0);
    oracle o1("SHERVIN");

    //married couple
    o1.marry(&p1, &p2);

    //creating new person
   	human* p3 = p1 + &p2;

    //setting the firstname of newborn
    if(p3->getGender())
        p3->firstName = "MAHSHID";
    else
        p3->firstName = "FARSHID";
    //increasing the age of newborn
    ++*p3;
    // creat new object
    human p4("SHAHIN", "REZAEE", 0, 5, 58, 1, 1);
    human p5("FARHAD", "BAHADORI", 0, 6, 63, 0, 1);

    //set child
    o1.setChild(&p1, &p4, &p5);
    if(o1.isFamily(p3, &p5)) {
        human** f1{o1.getFamily(p3)};
        std::cout << "the population of family is: " << o1.getPopulationOfFamily(p3) 
        		  << std::endl;
        std::cout << "the name of each member of family: " ;
        for(size_t i{0}; i < o1.getPopulationOfFamily(p3); i++) {
            std::cout << f1[i]->getFirstName() << ", ";
        }
        std::cout << std::endl;
    }


    return 0;
}