#pragma once
#include <iostream>

#include "configs.h"
#include "Pair.h"

class TreeNode{
  private:
	Pair data;
	TreeNode *left, *right;
  
  public:
	friend class BinaryTree;
	friend class SearchTree;
	TreeNode() : left(nullptr), right(nullptr){};
	TreeNode(Pair _data, TreeNode *_left = nullptr, TreeNode *_right = nullptr) : data(_data), left(_left),
																				  right(_right){};
	~TreeNode() = default;
	Pair &getData(){ return this->data; }
	void preorder();
	void inorder();
	void postorder();
	TreeNode *leftChild(){ return this->left; }
	TreeNode *rightChild(){ return this->right; }
	
	int getPriority(){ return this->data.getPriority(); }
	char getValue(){ return this->data.getValue(); }
	
	TreeNode &operator=(const TreeNode &org);
	
	// copy ctor, operator =
};

