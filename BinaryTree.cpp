#include "BinaryTree.h"

BinaryTree::~BinaryTree(){
	
	deleteSubTree(this->root->left);
	deleteSubTree(this->root->right);
	
	delete root;
}
void BinaryTree::deleteSubTree(TreeNode *treeNode){
	
	if(treeNode == nullptr)
		return;
	
	deleteSubTree(treeNode->left);
	deleteSubTree(treeNode->right);
	
	delete treeNode;
}
TreeNode *BinaryTree::find(unsigned int key){
	
	return findHelper(this->root, key);
}
TreeNode *BinaryTree::findHelper(TreeNode *_root, unsigned int key){
	
	if(_root == nullptr)
		return nullptr;
	
	if(_root->data.getPriority() == key)
		return _root;
	
	TreeNode *curr = findHelper(_root->left, key);
	if(curr != nullptr)
		return curr;
	
	return findHelper(_root->right, key);
}
void BinaryTree::insert(TreeNode *treeNode){
	
	TreeNode *curr = this->root;
	bool inserted = false;
	this->length++;
	
	while(!inserted && curr != nullptr){
		if(treeNode->data.getPriority() <= curr->data.getPriority()){
			if(curr->left == nullptr){
				curr->left = treeNode;
				inserted = true;
			}
			else
				curr = curr->left;
		}
		else{
			if(curr->right == nullptr){
				curr->right = treeNode;
				inserted = true;
			}
			else
				curr = curr->right;
		}
	}
}
TreeNode *BinaryTree::findParent(TreeNode *_root, unsigned int key){
	
	if(_root == nullptr)
		return nullptr;
	
	if(_root->left->data.getPriority() == key || _root->right->data.getPriority() == key)
		return _root;
	
	TreeNode *curr = findParent(_root->left, key);
	if(curr != nullptr)
		return curr;
	
	return findParent(_root->right, key);
}
void BinaryTree::Delete(unsigned int key){
	
	TreeNode *curr = find(key);
	
	if(curr->left == nullptr && curr->right == nullptr){
		delete curr;
		return;
	}
	
	TreeNode *parent = findParent(this->root, key);
	
	parent->left = curr->left;
	parent->right = curr->right;
	
	delete curr;
}
void BinaryTree::insert(Pair &p){
	
	this->insert(new TreeNode(p));
}
