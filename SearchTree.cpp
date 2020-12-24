#include "SearchTree.h"

Tree::TreeNode *SearchTree::find(char key){
	
	TreeNode *curr = this->root;
	
	while(curr != nullptr){
		if(curr->value == key)
			return curr;
		else if(key < curr->value)
			curr = curr->left;
		else
			curr = curr->right;
	}
	
	return curr;
}
void SearchTree::Delete(char key){
	
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
		TreeNode *max = findMax(curr->left), *maxParent = findParent(max->value);
		maxParent->right = max->left;
		max->right = curr->right;
		max->left = curr->left;
		parent->right = max;
	}
	
	delete curr;
}
Tree::TreeNode *SearchTree::findParent(char key){
	
	TreeNode *curr = this->root;
	
	while(curr != nullptr){
		if(key < curr->value)
			if(curr->left == nullptr)
				break;
			else{
				if(curr->left->value == key)
					break;
				curr = curr->left;
			}
		else if(curr->right == nullptr)
			break;
		else{
			if(curr->right->value == key)
				break;
			curr = curr->right;
		}
	}
	
	return curr;
}
Tree::TreeNode *SearchTree::findMax(Tree::TreeNode *treeNode){
	
	TreeNode *curr = treeNode;
	while(curr->right != nullptr){
		curr = curr->right;
	}
	
	return curr;
}
void SearchTree::insert(Tree::TreeNode *treeNode){
	
	TreeNode *curr = this->root;
	bool inserted = false;
	
	while(!inserted && curr != nullptr){
		if(curr->value == treeNode->value){
			return;
		}
		if(treeNode->value < curr->value){
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

