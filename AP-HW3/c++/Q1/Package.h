#ifndef PACKAGE_H
#define PACKAGE_H
#include <memory>
#include<cmath>
#include "Node.h"

using SharedNode = std::shared_ptr<Node>;




class Package
{
public:
  SharedNode pNode;             // Pointer to the node object contained in this Package
  Package* pParent;             // Pointer to the parent Package in the list
  Package* pChild_r;            // Pointer to the chil_r Package in the list
  Package* pChild_l;
  size_t pHeight{0};
	size_t packageNumber{0};
	// Constructor
  Package(SharedNode pn) : pNode{pn}, pParent{nullptr},pChild_r{nullptr},pChild_l{nullptr} {
  }     
  ~Package() { 
  	delete pChild_l;
  	delete pChild_r; 
  }                            // Destructor

  // Retrieve the node pointer
  SharedNode getNode() const { return pNode; } 
  
  // Retrieve or update the node to the next Package 
  Package* getParent() { return pParent; }
  Package* getChild_l() { return pChild_l; }
  Package* getChild_r() { return pChild_r; }
  void setParent(Package* pPackage) { pParent = pPackage; }
  void setChild_r(Package* pPackage) { pChild_r = pPackage; }
  void setChild_l(Package* pPackage) { pChild_l = pPackage; }
};
#endif