#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree{
private:
  std::unique_ptr<TreeNode<T>> root;
public:
  void write(ostream& stream) const{
    root->write(stream);
  }
  
  TreeNode<T>* insert(T data){
    TreeNode<T>* insertNode = new TreeNode<T>(data); 

    if(!root){
      root.reset(insertNode);
      return root.get();
    } 
    
    TreeNode<T>* currentNode = root.get();
    
    while(true){
      if (currentNode->data < data){
	if(currentNode->rightChild){
	  currentNode = currentNode->rightChild.get();
	}
	else{
	currentNode->setRightChild(insertNode);
	insertNode->parent = currentNode;
	break;
	}
      }
      
      if (data < currentNode->data){
	if(currentNode->leftChild){
	  currentNode = currentNode->leftChild.get();
	}
	else{
	  currentNode->setLeftChild(insertNode);
	  insertNode->parent = currentNode;
	  break;
	}
      }
    }
    
   return insertNode;
  }
  
  TreeNode<T>* find(T data){ 
    TreeNode<T>* currentNode = root.get();
    
    if (data == root.get()->data){
      return root.get();
    }
    
    while(true){
      if (currentNode->data < data){
	if(currentNode->rightChild){
	  currentNode = currentNode->rightChild.get();
	  if(currentNode->data == data){
	    return currentNode;
	  }
	}
	else{
	return nullptr;
	break;
	}
      }
      
      if (data < currentNode->data){
	if(currentNode->leftChild){
	  currentNode = currentNode->leftChild.get();
	  if(currentNode->data == data){
	    return currentNode;
	  }
	}
	else{
	  return nullptr;
	  break;
	}
      }
    }
  }
  
};



// do not edit below this line

#endif