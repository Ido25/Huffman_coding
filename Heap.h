#pragma once

#include <iostream>
#include "Pair.h"

using namespace std;

class Heap{
  private:
	DataPair *heap;
	int heap_size;
  
  public:
	Heap() : heap_size(0){};
	~Heap(){};
	
	void makeEmpty(){ heap_size = 0; };
	bool isEmpty(){ return heap_size == 0; };
	void insert(DataPair item);
	char min(){ return this->heap_size == 0 ? 0 : this->heap[0].getValue(); }
	DataPair &deleteMin();
	void buildHeap(DataPair *arr, int size);
	void fixHeap(int idx);
	void swap(DataPair &first, DataPair &second);
};