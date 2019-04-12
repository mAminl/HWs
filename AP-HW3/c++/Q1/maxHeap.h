#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Package.h"
#include <vector>
#include <iostream>
#include <array>
class maxHeap;
std::ostream& operator<<(std::ostream& os,maxHeap& Heap);   //define operator<<
class maxHeap
{
private:
  Package* pHead {};                               // First in the heap
  Package* pTail {};                               // Last in the heap
  Package* pCurrent {};
  Package* pTemp{};                           		 // Last retrieved from the heap
  size_t Height = 1;

public:
  maxHeap() = default;                           // Default constructor 
  maxHeap(SharedNode pNode)                        // Constructor 
  {  pHead = pTail = new Package{pNode}; }
  maxHeap(const std::vector<SharedNode>& Nodes);  // Constructor - vector of nodes
  maxHeap(maxHeap& Heap);
  maxHeap(int arr[],int size);
  ~maxHeap(); 				 					// Destructor: clean up the heap
  SharedNode getHead();                         // Get the first node
  SharedNode getParentNode();                          // Get the next node
  SharedNode getChild_l();                            //get the child_l pointer
  SharedNode getChild_r();                            //get the child_r pointer
  Package* Find(size_t i);
  void add(SharedNode pNode);                     // Add a new node
  void add(size_t value);
  void sort(Package* );
  bool remove();                  // Remove a node from the heap
  size_t getHeight(){return Height - 1;}
  size_t operator[](size_t);
  size_t totalPackage{0};
  size_t parent(size_t);          //get parent value's
  size_t Max(){return pHead->pNode->value;}   //get max value
  size_t RightChild(size_t);    //get child_r value's
  size_t LeftChild(size_t);
};

#endif