#pragma once
#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "configs.h"
#include "SearchTree.h"

Pair *getBuckets(ifstream &in);
SearchTree *buildSearchTreeFromBuckets(Pair *buckets);
BinaryTree *buildHuffmanTree(SearchTree *sr);
void printHuffmanCoding(BinaryTree *huffman, int max_depth);
void huffmanHelper(TreeNode *huffman, int *arr, int &writeIndex, int max_depth);
void getHuffmanWeight(TreeNode *huffman, int &depth, int &sum, int max_depth);
inline void normalizeOutput(char *res, char ch){
	
	if(ch == '\n'){
		res[0] = '\\';
		res[1] = 'n';
		res[2] = '\0';
	}
	else if(ch == '\t'){
		res[0] = '\\';
		res[1] = 't';
		res[2] = '\0';
	}
	else
		res[0] = ch;
}