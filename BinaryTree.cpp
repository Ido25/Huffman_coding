#include "BinaryTree.h"

BinaryTree::~BinaryTree(){
	
	if(this-> root == nullptr)
		return;
	
	if(this->root->left != nullptr)
		deleteSubTree(this->root->left);
	if(this->root->right != nullptr)
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
	
	this->length++;
	if(this->root == nullptr){
		this->root = treeNode;
		return;
	}
	
	unsigned int key = treeNode->data.getPriority();
	
	TreeNode *curr = this->root;
	while(curr != nullptr){
		if(key < curr->data.getPriority()){
			if(curr->left == nullptr){
				curr->left = treeNode;
				return;
			}
			else
				curr = curr->left;
		}
		else{
			if(curr->right == nullptr){
				curr->right = treeNode;
				return;
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
	
	this->length--;
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
