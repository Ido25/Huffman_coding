#include "SearchTree.h"
//TODO: change to priority instead of value?
Tree::TreeNode *SearchTree::find(char key){
	
	TreeNode *curr = this->root;
	
	while(curr != nullptr){
		if(curr->data.getValue() == key)
			return curr;
		else if(key < curr->data.getValue())
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
		TreeNode *max = findMax(curr->left), *maxParent = findParent(max->data.getValue());
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
		if(key < curr->data.getValue())
			if(curr->left == nullptr)
				break;
			else{
				if(curr->left->data.getValue() == key)
					break;
				curr = curr->left;
			}
		else if(curr->right == nullptr)
			break;
		else{
			if(curr->right->data.getValue() == key)
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
		if(treeNode->data.getPriority() =< curr->data.getPriority()){
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
SearchTree *SearchTree::buildTree(DataPair *arr){
	
	SearchTree *tree = new SearchTree;
	
	for(int i = 0; i < MAX_SIZE; i++)
		if(arr[i].getPriority() > 0)
			tree->insert(new TreeNode(arr[i]));
	
	return tree;
}

