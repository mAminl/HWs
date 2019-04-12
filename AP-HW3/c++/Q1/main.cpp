// Using a linked list
#include <cstdlib>                     // For random number generation
#include <ctime>                       // For the std::time() function
#include <memory>
#include <iostream>
#include "maxHeap.h"

// Function to generate a random integer between 1 and count
inline unsigned random(size_t count)
{
  return 1 + static_cast<unsigned>(std::rand() / (RAND_MAX / count + 1));
}
// Function to generate a node with random value
inline SharedNode randomNode()
{
  const size_t dimLimit {99};          // Upper limit on mode value
  return std::make_shared<Node>(random(dimLimit));
}

int main()  
{

  // Initialize the random number generator
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  maxHeap Heap1;                     // Create an empty list
  
  // Add 11 random node objects to the heap
  const size_t nodeCount {11};
  for (size_t i {} ; i < nodeCount ; ++i){
  	SharedNode a = randomNode();
    Heap1.add(a);
	}

  // Find the largest node in the heap
  SharedNode largestNode{Heap1.getHead()};

  std::cout << "\nThe largest Node in the extra list is: " << largestNode->value << std::endl;
  std::cout << Heap1 << std::endl;
  std::cout << "Parent of Node 2 is: " << Heap1.parent(2) << std::endl; 
  std::cout << "LeftChild of Node 1 is: " << Heap1.LeftChild(1) << std::endl;  
  std::cout << "RightChild of Node 1 is: " << Heap1.RightChild(1) << std::endl;  

  // Remove max value and sort heap again
  Heap1.remove();

  largestNode = Heap1.getHead();
  std::cout << "The largest Node in the extra list after removing max value is: "
            << largestNode->value << std::endl;

  // make new heap
  maxHeap h1;
    h1.add(25);
    h1.add(32);
    h1.add(17);
    h1.add(23);
    h1.add(101);
  largestNode = h1.getHead();

  std::cout << "\nThe largest Node in the first list is: " << largestNode->value << std::endl;
  std::cout << h1 << std::endl;
  std::cout << "Parent of Node 2 is: " << h1.parent(2) << std::endl; 
  std::cout << "LeftChild of Node 1 is: " << h1.LeftChild(1) << std::endl;  
  std::cout << "RightChild of Node 1 is: " << h1.RightChild(1) << std::endl;  

  h1.remove();

  largestNode = h1.getHead();
  std::cout << "The largest Node in the first list after removing max value is: "
            << largestNode->value << std::endl;

  //make new heap by array
  int arr[7] {23, 1, 7, 52, 11, 10, 75};
  maxHeap h2(arr, 7);
  
  std::cout << "\nSecond Heap is: " << std::endl;   
  std::cout << h2 << std::endl;  
  std::cout << "The Height of Heap2 is: " << h2.getHeight() << std::endl;

  maxHeap h3{h2};
  
  largestNode = h3.getHead();
  std::cout << "The largest node in the third list is: " << largestNode->value << std::endl;
  h3.remove();
  largestNode = h3.getHead();
  std::cout << "The largest Node in the third list after removing max value is: " 
            << largestNode->value << std::endl;
}

