#include "TreeNode.h"

void TreeNode::preorder(){
	
	cout << this->data;
	
	if(this->left != nullptr)
		this->left->preorder();
	
	if(this->right != nullptr)
		this->right->preorder();
}
void TreeNode::inorder(){
	
	if(this->left != nullptr)
		this->left->inorder();
	
	cout << this->data;
	
	if(this->right != nullptr)
		this->right->inorder();
}
void TreeNode::postorder(){
	
	if(this->left != nullptr)
		this->left->postorder();
	
	if(this->right != nullptr)
		this->right->postorder();
	
	cout << this->data;
}
TreeNode &TreeNode::operator=(const TreeNode &org){
	
	if(this == &org)
		return *this;
	
	this->data = org.data;
	this->left = org.left;
	this->right = org.right;
}
