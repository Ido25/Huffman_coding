#include "Heap.h"

using namespace std;

void Heap::buildHeap(DataPair *arr, int size){
	
	for(int i = size / 2; i >= 0; i--)
		this->fixHeap(i);
}
void Heap::fixHeap(int idx){
	
	while(idx < this->heap_size && (this->heap[idx].getPriority()) > this->heap[2 * idx + 1].getPriority() &&
		  this->heap[idx].getPriority() > this->heap[2 * idx + 2].getPriority()){
		DataPair tmp =
				this->heap[2 * idx + 1].getPriority() < this->heap[2 * idx + 2].getPriority() ? heap[2 * idx + 1]
																							  : heap[2 * idx +
																									 2];
		int tmp_idx =
				this->heap[2 * idx + 1].getPriority() < this->heap[2 * idx + 2].getPriority() ? (2 * idx + 1) : (
						2 * idx + 2);
		swap(this->heap[idx], tmp);
		idx = tmp_idx;
	}
}
void Heap::swap(DataPair &first, DataPair &second){
	
	DataPair tmp = first;
	first = second;
	second = tmp;
}
DataPair &Heap::deleteMin(){
	
	if(heap_size < 1)
		throw "Heap size smaller than 1";
	
	DataPair min = this->heap[0];
	heap_size--;
	this->heap[0] = this->heap[heap_size];
	fixHeap(0);
	return min;
}
void Heap::insert(DataPair item){
	
	if(heap_size == MAX_SIZE)
		throw "Reached max size";
	
	int idx = heap_size++;
	
	while(idx > 0 && (this->heap[(idx - 1) / 2].getPriority() > item.getPriority())){
		this->heap[idx] = this->heap[(idx - 1) / 2];
		idx = (idx - 1) / 2;
	}
	this->heap[idx] = item;
}

