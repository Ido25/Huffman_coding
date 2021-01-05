#pragma once

#include "Tree.h"

class SearchTree : public Tree{
  private:
	TreeNode *findParent(char key);
	TreeNode *findMax(TreeNode *treeNode);
  public:
	SearchTree(){};
	~SearchTree(){};
	
	virtual TreeNode *find(char key);
	virtual void insert(TreeNode *treeNode);
	virtual void Delete(char key);
	SearchTree *buildTree(DataPair *arr);
};