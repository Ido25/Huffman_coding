#include "Heap.h"

using namespace std;

Heap::pair &Heap::pair::operator=(pair &org){
	
	this->priority = org.priority;
	this->val = org.val;
	
	return *this;
}
void Heap::buildHeap(int size){
	
	for(int i = size / 2; i >= 0; i--)
		this->fixHeap(i);
}
void Heap::fixHeap(int idx){
	
	while(idx < this->heap_size && (this->heap[idx].priority) > this->heap[2 * idx + 1].priority &&
		  this->heap[idx].priority > this->heap[2 * idx + 2].priority){
		pair tmp =
				this->heap[2 * idx + 1].priority < this->heap[2 * idx + 2].priority ? heap[2 * idx + 1] : heap[2 * idx +
																											   2];
		int tmp_idx =
				this->heap[2 * idx + 1].priority < this->heap[2 * idx + 2].priority ? (2 * idx + 1) : (2 * idx + 2);
		swap(this->heap[idx], tmp);
		idx = tmp_idx;
	}
}
void Heap::swap(pair &first, pair &second){
	
	pair tmp = first;
	first = second;
	second = tmp;
}
Heap::pair &Heap::deleteMin(){
	
	if(heap_size < 1)
		throw "Heap size smaller than 1";
	
	pair min = this->heap[0];
	heap_size--;
	this->heap[0] = this->heap[heap_size];
	fixHeap(0);
	return min;
}
void Heap::insert(Heap::pair item){
	
	if(heap_size == MAX_SIZE)
		throw "Reached max size";
	
	int idx = heap_size++;
	
	while(idx > 0 && (this->heap[(idx - 1) / 2].priority > item.priority)){
		this->heap[idx] = this->heap[(idx - 1) / 2];
		idx = (idx - 1) / 2;
	}
	this->heap[idx] = item;
}

