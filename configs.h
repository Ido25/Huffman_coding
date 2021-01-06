#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

static constexpr int MAX_SIZE = 127;
static constexpr unsigned int OUT_OF_RANGE = -1;
static constexpr char ERR_MSG[] = "invalid input";

static inline void HandleError(){
	
	cout << endl << ERR_MSG << endl;
	exit(1);
}

template<class T>
T *allocate(int size){
	
	T *arr;
	
	try{
		arr = new T[size];
	}
	catch(bad_alloc &ex){
		HandleError();
	}
	
	return arr;
}