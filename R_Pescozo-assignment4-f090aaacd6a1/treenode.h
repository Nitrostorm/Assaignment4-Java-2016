#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode {
  
  
public:
  T  data;
  unique_ptr<TreeNode<T>> leftChild;
  unique_ptr<TreeNode<T>> rightChild;
  TreeNode<T> * parent;
  
  TreeNode(T info)
    : data(info)	{
    parent = nullptr;
  }
  
  void setLeftChild(TreeNode* child){
  child->parent = this;
  leftChild.reset(child);
}

  void setRightChild(TreeNode* child){
    child->parent = this;
    rightChild.reset(child);
  }
  
  void write(ostream& os) const{
    if (leftChild != nullptr){
      leftChild->write(os); 
    } 
   os << " ";
   os << data;
   os << " ";
   if (rightChild != nullptr){
      rightChild->write(os);
    } 
  }
  
};




// do not edit below this line

#endif