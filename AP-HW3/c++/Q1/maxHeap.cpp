#include<iostream>
#include<algorithm>
#include<cmath>
#include"maxHeap.h"
#include<array>

// Constructors
maxHeap::maxHeap(const std::vector<SharedNode>& Nodes)
{
  for (const auto& pNode : Nodes)
  {
    add(pNode);
  }
}
maxHeap::maxHeap(int arr[],int size){
	for (int i{0} ; i < size ; ++i)
	{
		add(std::make_shared<Node>(arr[i]));
	}
}

maxHeap::maxHeap(maxHeap& Heap){
	for(size_t i{1}; i <= Heap.totalPackage ; i++){
		add(Heap.Find(i)->pNode);
	}
}
maxHeap::~maxHeap(){
	delete pHead;
}

// Get the first node
SharedNode maxHeap::getHead()
{
  // Return pHead's node (or nullptr if the heap is empty)
  pCurrent = pHead;
  return pCurrent? pCurrent->getNode() : nullptr;     
}

// Get the next node
SharedNode maxHeap::getParentNode()    
{
  if (!pCurrent)                                     // If there's no current...
    return getHead();                                // ...return the 1st node

  pCurrent = pCurrent->getParent();                  // Move to the next package
  
  return pCurrent? pCurrent->getNode() : nullptr;    // Return its node (or nullptr...).
}



// Add a node to the list
void maxHeap::add(SharedNode pNode)
{
	totalPackage++;	

  auto pPackage = new Package{pNode};       // Create a new Package
  	pPackage->packageNumber = totalPackage;
  	size_t a = pow(2,Height);
  	if(pPackage->packageNumber == a){
  		Height++;
  	}
  	if(pPackage->packageNumber == 1){				//initialize node #1
  		pPackage->pHeight = Height;
  		pTail = pHead = pPackage;
  		pPackage->setParent(nullptr);
  	}
  	
    else if(pPackage->packageNumber == 2){              //initialize node #2                  
    	pPackage->setParent(pHead);
    	pHead->setChild_l(pPackage);
    	pPackage->pHeight = Height;
    	pCurrent = pPackage;
    	}
	
    else if(pPackage->packageNumber == 3){                 //initialize node #3
    	pPackage->setParent(pHead);
    	pHead->setChild_r(pPackage);
    	pPackage->pHeight = Height;
    	}
	
  	else {													//add other nodes
  		if(pPackage->packageNumber == a){
  			pPackage->pHeight = Height;
  			pCurrent->setChild_l(pPackage);
  			pPackage->setParent(pCurrent);
  			pCurrent = pPackage;
  		}
  		else if(!(pPackage->packageNumber % 2)){
  			pTail->pParent->pParent->pChild_r->setChild_l(pPackage);
  			pPackage->setParent(pTail->pParent->pParent->pChild_r);
  			pPackage->pHeight = Height;
  		}
  		else {                              
    		pTail->pParent->setChild_r(pPackage);                     
    		pPackage->setParent(pTail->pParent);
    		pPackage->pHeight = Height;
     	}
}
	sort(pPackage);					//sort heap
	pTail = pPackage;				// Store its address as pTail
}

void maxHeap::add(size_t value){
	add(std::make_shared<Node>(value));
}

void maxHeap::sort(Package* p1){
	Package* temp1 = nullptr;
	Package* temp2 = nullptr;
	temp1 = p1;
	temp2 = p1->pParent;
	while(temp2){										//compare with parent and sort
		if(temp1->pNode->value > temp2->pNode->value){
			size_t temp = temp2->pNode->value;
			temp2->pNode->value = temp1->pNode->value;
			temp1->pNode->value = temp;
		}
		else
			break;
		temp1 = temp2;
		temp2 = temp2->pParent;
    }

}
// Find the Package containing pnode and delete it from the list
bool maxHeap::remove()
{
  pHead->pNode->value = pTail->pNode->value;
  pTail = nullptr;
  delete pTail;
  Package* pTemp;
  pTemp = pHead;
  size_t temp{0};
  bool state = false;

  while((pTemp->pChild_r)&&(pTemp->pChild_l)){
  	if((pTemp->pNode->value < pTemp->pChild_r->pNode->value)&&
  		(pTemp->pChild_r->pNode->value >= pTemp->pChild_l->pNode->value)) {
  			temp = pTemp->pNode->value;
			pTemp->pNode->value = pTemp->pChild_r->pNode->value;
			pTemp->pChild_r->pNode->value = temp;
			pTemp = pTemp->pChild_r;
			state = true;
  	}
  	else if(pTemp->pNode->value < pTemp->pChild_l->pNode->value){
  			temp = pTemp->pNode->value;
			pTemp->pNode->value = pTemp->pChild_l->pNode->value;
			pTemp->pChild_l->pNode->value = temp;
			pTemp = pTemp->pChild_l;
			state = true;
  	}
  	else{
  		break;
  	}
  	totalPackage--;
}
	//pTail = Find(totalPackage);
  return state;                                // Return false: nodeToRemove was not found
}

size_t maxHeap::operator[](size_t index){
	pCurrent = Find(index);
	return pCurrent->pNode->value;
}

size_t maxHeap::parent(size_t index){
	pCurrent = Find(index);
	return pCurrent->pParent->pNode->value;
}

size_t maxHeap::RightChild(size_t index){
	pCurrent = Find(index);
	return pCurrent->pChild_r->pNode->value;
}

size_t maxHeap::LeftChild(size_t index){
	pCurrent = Find(index);
	return pCurrent->pChild_l->pNode->value;
}

std::ostream& operator<<(std::ostream& os,maxHeap& Heap){
	size_t a{1};
	for(size_t i{1}; i <= Heap.totalPackage ;i++){
		if(i == std::pow(2,a)){
			a++;
			std::cout<<std::endl;
		}
		os << Heap[i] << ",";
	}
	return os;
}

Package* maxHeap::Find(size_t index){		//an algorithm to find specific node
	size_t count{0};
	size_t iHeight{0};
	while(index >= std::pow(2,count)){
		count++;
		iHeight++;
	}
	if(index == 1)
		pCurrent = pHead;

	else if(index < totalPackage){
		if(std::fmod(index,pow(2,iHeight - 1)) < (pow(2,iHeight - 1)/2)){
			pCurrent = pHead->pChild_l;
			for(size_t i{2};i <= iHeight - 1;i++){
				if(std::fmod(index , pow(2,iHeight - i)) < (pow(2,iHeight - i)/2)){
					pCurrent = pCurrent->pChild_l;
				}
				else{
					pCurrent = pCurrent->pChild_r;	
				}
			}
		}
		else{
			pCurrent = pHead->pChild_r;
			for(size_t i{2};i <= iHeight - 1;i++){
				if(std::fmod(index , pow(2,iHeight - i)) < (pow(2,iHeight -i)/2)){
					pCurrent = pCurrent->pChild_l;
				}
				else{
					pCurrent = pCurrent->pChild_r;
				}	
			}
		}

	}
	else if(index == totalPackage)
		pCurrent = pTail;
	return pCurrent;
}