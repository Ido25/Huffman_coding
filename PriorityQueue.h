#pragma once

#include <iostream>
#include "configs.h"
#include "Pair.h"
#include "TreeNode.h"

using namespace std;
//Priority Queue that is implemented  using a Minimum Heap
class PriorityQueue{
  private:
	TreeNode **arr;
	int heap_size;
	int max_size;
	bool allocated;
	static int getLeft(int node);
	static int getRight(int node);
	static int getParent(int node);
	void heapify(int node);
	void swap(TreeNode *&a, TreeNode *&b);
	
  public:
	PriorityQueue(int _max_size);
	PriorityQueue(TreeNode **_Array, int size);
	~PriorityQueue();
	
	void makeEmpty(){ heap_size = 0; };
	bool isEmpty(){ return heap_size == 0; };
	void insert(TreeNode *item);
	TreeNode *getMin();
	TreeNode *deleteMin();
	
	friend ostream &operator<<(ostream &os, const PriorityQueue &org){
		
		for(int i = 0; i < org.heap_size; i++)
			os << "(" << org.arr[i]->getValue() << ", " << org.arr[i]->getPriority() << ") ";
		
		return os;
	}
	
};