#pragma once

#include <iostream>
#include "configs.h"
#include "Pair.h"
#include "TreeNode.h"

using namespace std;

class MinimumHeap{
  private:
	TreeNode *arr;
	int heap_size;
	int max_size;
	bool allocated;
	static int getLeft(int node);
	static int getRight(int node);
	static int getParent(int node);
	void heapify(int node);
	void swap(TreeNode &a, TreeNode &b);
	
  public:
	MinimumHeap(int _max_size);
	MinimumHeap(TreeNode *_Array, int size);
	~MinimumHeap();
	
	void makeEmpty(){ heap_size = 0; };
	bool isEmpty(){ return heap_size == 0; };
	void insert(TreeNode &item);
	TreeNode &getMin();
	TreeNode deleteMin();
};