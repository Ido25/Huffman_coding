#include "SearchTree.h"


TreeNode *SearchTree::find(unsigned int key){
	
	TreeNode *curr = this->root;
	
	while(curr != nullptr){
		if(curr->data.getPriority() == key)
			return curr;
		else if(key < curr->data.getPriority())
			curr = curr->left;
		else
			curr = curr->right;
	}
	
	return curr;
}
void SearchTree::Delete(unsigned int key){
	
	TreeNode *parent = findParent(key), *curr = find(key);
	
	if(parent == nullptr || curr == nullptr)
		return;
	
	if(curr->left == nullptr || curr->right == nullptr){
		if(curr == parent->left){
			parent->left = curr->left;
		}
		else
			parent->right = curr->right;
	}
	else{
		TreeNode *max = findMax(curr->left), *maxParent = findParent(max->data.getPriority());
		maxParent->right = max->left;
		max->right = curr->right;
		max->left = curr->left;
		parent->right = max;
	}
	
	delete curr;
}
TreeNode *SearchTree::findParent(unsigned int key){
	
	TreeNode *curr = this->root;
	
	while(curr != nullptr){
		if(key < curr->data.getPriority())
			if(curr->left == nullptr)
				break;
			else{
				if(curr->left->data.getPriority() == key)
					break;
				curr = curr->left;
			}
		else if(curr->right == nullptr)
			break;
		else{
			if(curr->right->data.getPriority() == key)
				break;
			curr = curr->right;
		}
	}
	
	return curr;
}
TreeNode *SearchTree::findMax(TreeNode *treeNode){
	
	TreeNode *curr = treeNode;
	while(curr->right != nullptr){
		curr = curr->right;
	}
	
	return curr;
}
TreeNode * SearchTree::getTreeAsArr(){
	
	TreeNode *arr = allocate<TreeNode>(this->length);
	
	int i = 0;
	this->getTreeAsArr(arr, this->root, this->length, i);
	
	return arr;
}
void SearchTree::getTreeAsArr(TreeNode *arr, TreeNode *curr, int size, int &i){
	
	if(curr == nullptr || arr == nullptr || i > size)
		return;
	
	this->getTreeAsArr(arr, curr->leftChild(), size, i);
	
	arr[i++].data = curr->data;
	
	this->getTreeAsArr(arr, curr->rightChild(), size, i);
}
