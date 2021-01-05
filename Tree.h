#pragma once

#include "Pair.h"

class Tree{
  protected:
	class TreeNode{
	  public:
		DataPair data;
		TreeNode *left, *right;
		TreeNode() : left(nullptr), right(nullptr){};
		TreeNode(DataPair _data, TreeNode *_left = nullptr, TreeNode *_right = nullptr) : data(_data), left(_left),
																						  right(_right){};
		~TreeNode(){};
	};
	TreeNode *root;
	void deleteSubTree(TreeNode *treeNode);
  
  public:
	Tree() : root(nullptr){};
	Tree(TreeNode *_root) : root(_root){};
	~Tree();
	virtual TreeNode *find(char key);
	virtual void insert(TreeNode *treeNode);
	virtual void Delete(char key);
};