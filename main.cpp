#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "SearchTree.h"
#include "Huffman.h"

int main(){
	
	char fname[MAX_SIZE];
	ifstream infile;
	
	cout << "Please enter the file's name: " << endl;
	cin >> fname;
	
	infile.open(fname);
	if(!infile)
		HandleError();
	
	// build search tree
	Pair *buckets = getBuckets(infile);
	SearchTree *sr = buildSearchTreeFromBuckets(buckets);
	
	// this function build huffman tree from search tree
	BinaryTree *huffman = buildHuffmanTree(sr);
	
	// this function prints the huffman coding
	int max_depth = huffman->getHeight();
	printHuffmanCoding(huffman, max_depth);
	
	// compute file weight in bytes
	int depth = 0, sum_in_bytes = 0;
	getHuffmanWeight(huffman->getRoot(), depth, sum_in_bytes, max_depth);
	
	// print the weight in bytes
	cout << endl << "Encoded file weight: " << sum_in_bytes << " bits" << endl;
	
	infile.close();
	
	if(sr != nullptr)
		delete sr;
	if(huffman != nullptr || huffman->len() > 0)
		delete huffman;
	
	return 0;
}
