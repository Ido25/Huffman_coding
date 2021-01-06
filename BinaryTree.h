#pragma once

#include "TreeNode.h"
#include "Pair.h"

class BinaryTree{
  protected:
	TreeNode *root;
	void deleteSubTree(TreeNode *treeNode);
	TreeNode *findHelper(TreeNode *_root, unsigned int key);
	TreeNode *findParent(TreeNode *_root, unsigned int key);
	void insert(TreeNode *treeNode);
	int length;
  
  public:
	BinaryTree() : root(nullptr), length(0){};
	BinaryTree(TreeNode *_root) : root(_root), length(0){};
	~BinaryTree();
	virtual TreeNode *find(unsigned int key);
	void insert(Pair &p);
	virtual void Delete(unsigned int key);
	int len(){ return this->length; }
	
	// operator=
	// copy ctor
};