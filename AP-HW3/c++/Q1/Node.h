#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node{
public:
  Node(size_t a) : value{a}{};		//constructor
  size_t value{0};		//node number
};
#endif