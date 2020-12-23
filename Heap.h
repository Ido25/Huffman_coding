#pragma once

#include <iostream>

using namespace std;
#define MAX_SIZE 52
class Heap{
  private:
	class pair{
	  public:
		int priority;
		char val;
		pair(){};
		pair(int _key, char _val) : priority(_key), val(_val){};
		~pair(){};
		
		pair &operator=(pair &org);
	};
	pair heap[MAX_SIZE];
	int heap_size;
  
  public:
	Heap() : heap_size(0){};
	~Heap(){};
	
	void makeEmpty(){ heap_size = 0; };
	bool isEmpty(){ return heap_size == 0; };
	void insert(pair item);
	char min(){ return this->heap_size == 0 ? 0 : this->heap[0].val; }
	pair &deleteMin();
	void buildHeap(int size);
	void fixHeap(int idx);
	void swap(pair &first, pair &second);
};