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
	TreeNode *huffman = buildHuffmanTree(sr);
	
	// TODO : convert huffman to Tree
	// TODO : get height from huffman tree and pass to print and weight
	
	// this function prints the huffman coding
	printHuffmanCoding(huffman);
	
	// compute file weight in bytes
	int depth = 0, sum_in_bytes = 0;
	getHuffmanWeight(huffman, depth, sum_in_bytes);
	
	// print the weight in bytes
	cout << endl << "Encoded file weight: " << sum_in_bytes << " bits" << endl;
	
	infile.close();
	
	if(sr != nullptr)
		delete sr;
	
	// delete huffman
	
	return 0;
}
