#include <iostream>
#include <fstream>
#include "Heap.h"
#include "SearchTree.h"

int main(){
	
	DataPair buckets[MAX_SIZE];
	SearchTree *tr;
	char fname[MAX_SIZE], tmp;
	ifstream infile;
	
	for(int i = 0; i < MAX_SIZE; i++){
		buckets[i].setPriority(0);
		buckets[i].setvalue(i);
	}
	
	cout << "Please enter the file's name: " << endl;
	cin >> fname;
	
	infile.open(fname);
	if(!infile){
		cout << "Error with file opening" << endl;
		exit(1);
	}
	
	infile >> tmp;
	++buckets[tmp];
	while(!infile.eof()){
		if(!infile.good()){
			cout << "Error with file reading" << endl;
			exit(1);
		}
		
		infile >> tmp;
		++buckets[tmp];
	}
	
	tr->buildTree(buckets);
	
	infile.close();
	return 0;
}
