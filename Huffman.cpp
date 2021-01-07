#include "Huffman.h"
#include "PriorityQueue.h"

Pair *getBuckets(ifstream &in){
	
	Pair *buckets = allocate<Pair>(MAX_SIZE);
	
	for(int i = 0; i < MAX_SIZE; i++){
		buckets[i].setPriority(0);
		buckets[i].setvalue(i);
	}
	
	char ch, tmp;
	
	while(!in.eof()){
		if(!in.good())
			HandleError();
		
		tmp = in.get();
		++buckets[tmp];
	}
	
	return buckets;
}
SearchTree *buildSearchTreeFromBuckets(Pair *buckets){
	
	SearchTree *tree = new SearchTree();
	
	for(int i = 0; i < MAX_SIZE; i++){
		if(buckets[i].getPriority() > 0)
			tree->insert(buckets[i]); // problem here. tree as list
	}
	
	return tree;
}
TreeNode *buildHuffmanTree(SearchTree *sr){
	
	TreeNode **arr = sr->getTreeAsArr();
	PriorityQueue H(arr, sr->len());
	TreeNode *node;
	
	for(int i = 1; i < sr->len(); i++){
		TreeNode *a = H.deleteMin();
		TreeNode *b = H.deleteMin();
		Pair total(a->getPriority() + b->getPriority(), -1);
		node = new TreeNode(total, a, b);
		H.insert(node);
	}
	
	return H.deleteMin();
}
void printHuffmanCoding(TreeNode *huffman){
	
	// left is 0, right is 1.
	if(huffman == nullptr)
		return;
	
	int code[7];
	
	for(int i = 0; i < 7; i++)
		code[i] = 0;
	
	int i = 0;
	
	cout << "Character encoding:" << endl;
	
	if(huffman->leftChild() == nullptr && huffman->rightChild() == nullptr){
		cout << "'" << huffman->getValue() << "' - 1";
	}
	else huffmanHelper(huffman, code, i);
}
void huffmanHelper(TreeNode *huffman, int *arr, int &writeIndex){
	
	if(huffman == nullptr || arr == nullptr || writeIndex >= 7 || writeIndex < 0)
		return;
	
	if(huffman->leftChild() == nullptr && huffman->rightChild() == nullptr){
		cout << "'" << huffman->getValue() << "' - ";
		for(int j = 0; j < writeIndex; j++)
			cout << arr[j];
		cout << endl;
	}
	
	if(huffman->leftChild() != nullptr){
		arr[writeIndex++] = 0;
		huffmanHelper(huffman->leftChild(), arr, writeIndex);
		writeIndex--;
	}
	
	if(huffman->rightChild() != nullptr){
		arr[writeIndex++] = 1;
		huffmanHelper(huffman->rightChild(), arr, writeIndex);
		writeIndex--;
	}
}
void getHuffmanWeight(TreeNode *huffman, int &depth, int &sum){
	
	// this function compute the file size in bytes
	
	if(huffman == nullptr || depth >= 7 || depth < 0)
		return;
	
	if(huffman->leftChild() == nullptr && huffman->rightChild() == nullptr){
		if(depth == 0)
			sum += huffman->getPriority();
		else
			sum += huffman->getPriority() * depth;
	}
	
	if(huffman->leftChild() != nullptr){
		depth++;
		getHuffmanWeight(huffman->leftChild(), depth, sum);
		depth--;
	}
	
	if(huffman->rightChild() != nullptr){
		depth++;
		getHuffmanWeight(huffman->rightChild(), depth, sum);
		depth--;
	}
}
