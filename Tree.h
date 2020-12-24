#pragma once

class Tree{
  protected:
	class TreeNode{
	  public:
		char value;
		TreeNode *left, *right;
		TreeNode() : left(nullptr), right(nullptr){};
		TreeNode(char _value, TreeNode *_left = nullptr, TreeNode *_right = nullptr) : value(_value), left(_left),
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