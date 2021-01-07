#pragma once
#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "configs.h"
#include "SearchTree.h"

Pair *getBuckets(ifstream &in);
SearchTree *buildSearchTreeFromBuckets(Pair *buckets);
TreeNode *buildHuffmanTree(SearchTree *sr);
void printHuffmanCoding(TreeNode *huffman);
void huffmanHelper(TreeNode *huffman, int *arr, int &writeIndex);
void getHuffmanWeight(TreeNode *huffman, int &depth, int &sum);

