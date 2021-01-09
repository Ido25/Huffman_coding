#pragma once

#include "TreeNode.h"
#include "Pair.h"

class BinaryTree{
  protected:
	TreeNode *root;
	void deleteSubTree(TreeNode *treeNode);
	TreeNode *findHelper(TreeNode *_root, unsigned int key);
	TreeNode *findParent(TreeNode *_root, unsigned int key);
	int getDepthHelper(TreeNode *node, int depth);
	void insert(TreeNode *treeNode);
	int length;
  
  public:
	BinaryTree() : root(nullptr), length(0){};
	BinaryTree(BinaryTree &org){ *this = org; };
	BinaryTree(TreeNode *_root);
	~BinaryTree();
	virtual TreeNode *find(unsigned int key);
	void insert(Pair &p);
	virtual void Delete(unsigned int key);
	int len(){ return this->length; }
	int getHeight();
	TreeNode *getRoot(){ return this->root; }
	BinaryTree &operator=(BinaryTree &org);
};