#include "Tree.h"

Tree::~Tree(){
	
	deleteSubTree(this->root->left);
	deleteSubTree(this->root->right);
	
	delete root;
}
void Tree::deleteSubTree(TreeNode *treeNode){
	
	if(treeNode == nullptr)
		return;
	
	deleteSubTree(treeNode->left);
	deleteSubTree(treeNode->right);
	
	delete treeNode;
}
