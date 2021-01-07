#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(int _max_size){
	
	this->arr = allocate<TreeNode *>(_max_size);
	
	this->max_size = _max_size;
	this->heap_size = 0;
	this->allocated = true;
}
PriorityQueue::PriorityQueue(TreeNode **_Array, int size){
	
	this->arr = _Array;
	this->heap_size = this->max_size = size;
	this->allocated = false;
	
	// Build heap by floyd algorithm
	for(int i = (size / 2) - 1; i >= 0; i--)
		this->heapify(i);
}
PriorityQueue::~PriorityQueue(){
	
	if(this->allocated)
		delete[] this->arr;
	
	this->arr = nullptr;
}
void PriorityQueue::heapify(int node){
	
	// This function fix the heap that has node as root
	
	if(node >= this->heap_size)
		return;
	
	int min = node, left, right;
	
	do{
		left = this->getLeft(min);
		right = this->getRight(min);
		
		if(left < this->heap_size && this->arr[left]->getPriority() < this->arr[node]->getPriority())
			min = left;
		else
			min = node;
		
		if(right < this->heap_size && this->arr[right]->getPriority() < this->arr[min]->getPriority())
			min = right;
		
		if(min != node){
			swap(this->arr[node], this->arr[min]);
			int temp = node;
			node = min;
			min = temp;
		}
		
	} while(min != node);
}
TreeNode *PriorityQueue::deleteMin(){
	
	if(heap_size < 1)
		HandleError();
	
	auto min = this->arr[0];
	heap_size--;
	this->arr[0] = this->arr[heap_size];
	this->heapify(0);
	
	return min;
}
void PriorityQueue::insert(TreeNode *item){
	
	if(this->heap_size == this->max_size)
		HandleError();
	
	int idx = this->heap_size++;
	
	while(idx > 0 && (item->getPriority() < this->arr[this->getParent(idx)]->getPriority())){
		this->arr[idx] = this->arr[this->getParent(idx)];
		idx = this->getParent(idx);
	}
	
	this->arr[idx] = item;
}
int PriorityQueue::getLeft(int node){
	
	return node * 2 + 1;
}
int PriorityQueue::getRight(int node){
	
	return node * 2 + 2;
}
int PriorityQueue::getParent(int node){
	
	return (node - 1) / 2;
}
void PriorityQueue::swap(TreeNode *&a, TreeNode *&b){
	
	auto tmp = a;
	a = b;
	b = tmp;
}
TreeNode *PriorityQueue::getMin(){
	
	return this->arr[0];
}
