#include "Huffman.h"
#include "PriorityQueue.h"

Pair *getBuckets(ifstream &in){
	
	Pair *buckets = allocate<Pair>(MAX_SIZE);
	//read text from file and sum each char's amount
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
			tree->insert(buckets[i]);
	}
	
	return tree;
}
BinaryTree *buildHuffmanTree(SearchTree *sr){
	
	TreeNode **arr = sr->getTreeAsArr();
	PriorityQueue H(arr, sr->len());
	TreeNode *node;
	
	for(int i = 1; i < sr->len(); i++){
		TreeNode *a = H.deleteMin();
		TreeNode *b = H.deleteMin();
		Pair total(a->getPriority() + b->getPriority(), -1);
		
		try{
			node = new TreeNode(total, a, b);
		}
		catch(bad_alloc &ex){
			HandleError();
		}
		
		H.insert(node);
	}
	
	BinaryTree *res;
	
	try{
		res = new BinaryTree(H.deleteMin());
	}
	catch(bad_alloc &ex){
		HandleError();
	}
	
	return res;
}
void printHuffmanCoding(BinaryTree *huffman, int max_depth){
	
	// left is 0, right is 1.
	if(huffman == nullptr)
		return;
	
	int *code = allocate<int>(max_depth);
	for(int i = 0; i < max_depth; i++)
		code[i] = 0;
	
	int i = 0;
	
	cout << "Character encoding:" << endl;
	
	if(huffman->getRoot()->leftChild() == nullptr && huffman->getRoot()->rightChild() == nullptr){
		cout << "'" << huffman->getRoot()->getValue() << "' - 1";
	}
	else huffmanHelper(huffman->getRoot(), code, i, max_depth);
	
	delete[] code;
}
void huffmanHelper(TreeNode *huffman, int *arr, int &writeIndex, int max_depth){
	
	if(huffman == nullptr || arr == nullptr || writeIndex > max_depth || writeIndex < 0)
		return;
	
	if(huffman->leftChild() == nullptr && huffman->rightChild() == nullptr){
		char text[3] = " ";
		
		// normalize the output to print '\n' or '\t' in case needed.
		normalizeOutput(text, huffman->getValue());
		cout << "'" << text << "' - ";
		
		for(int j = 0; j < writeIndex; j++)
			cout << arr[j];
		cout << endl;
	}
	
	if(huffman->leftChild() != nullptr){
		arr[writeIndex++] = 0;
		huffmanHelper(huffman->leftChild(), arr, writeIndex, max_depth);
		writeIndex--;
	}
	
	if(huffman->rightChild() != nullptr){
		arr[writeIndex++] = 1;
		huffmanHelper(huffman->rightChild(), arr, writeIndex, max_depth);
		writeIndex--;
	}
}
void getHuffmanWeight(TreeNode *huffman, int &depth, int &sum, int max_depth){
	
	// this function computes the file size in bytes
	
	if(huffman == nullptr || depth > max_depth || depth < 0)
		return;
	
	if(huffman->leftChild() == nullptr && huffman->rightChild() == nullptr){
		if(depth == 0)
			sum += huffman->getPriority();
		else
			sum += huffman->getPriority() * depth;
	}
	
	if(huffman->leftChild() != nullptr){
		depth++;
		getHuffmanWeight(huffman->leftChild(), depth, sum, max_depth);
		depth--;
	}
	
	if(huffman->rightChild() != nullptr){
		depth++;
		getHuffmanWeight(huffman->rightChild(), depth, sum, max_depth);
		depth--;
	}
}
