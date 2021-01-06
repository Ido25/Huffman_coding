#pragma once

#include <iostream>
#include "configs.h"

using namespace std;

class Pair{
  private:
	unsigned int priority;
	char value;
  
  public:
	Pair(){};
	Pair(unsigned int _key , char _val) : priority(_key), value(_val){};
	~Pair(){};
	
	char getValue(){ return this->value; }
	int getPriority(){ return this->priority; }
	bool setPriority(int pr){ return this->priority = pr; };
	bool setvalue(char val){ return this->value = val; };
	
	Pair &operator=(const Pair &org);
	Pair &operator++();
	
	friend ostream &operator<<(ostream &os, const Pair &org){
		
		os << "Priority: " << org.priority << ", Value: " << org.value << endl;
		
		return os;
	}
};