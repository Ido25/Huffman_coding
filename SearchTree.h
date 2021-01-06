#pragma once

#include "BinaryTree.h"
#include "configs.h"

class SearchTree : public BinaryTree{
  private:
	TreeNode *findParent(unsigned int key);
	TreeNode *findMax(TreeNode *treeNode);
	void getTreeAsArr(TreeNode *arr, TreeNode *curr, int size, int &i);
	
  public:
	SearchTree() : BinaryTree(){};
	virtual ~SearchTree(){};
	
	virtual TreeNode *find(unsigned int key);
	virtual void Delete(unsigned int key);
	
	TreeNode * getTreeAsArr();
};