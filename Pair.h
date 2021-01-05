#include <iostream>

#define MAX_SIZE 128

using namespace std;

class DataPair{
  private:
	int priority;
	char value;
  
  public:
	DataPair(){};
	DataPair(int _key, char _val) : priority(_key), value(_val){};
	~DataPair(){};
	
	char getValue(){ return this->value; }
	int getPriority(){ return this->priority; }
	bool setPriority(int pr){ return this->priority = pr; };
	bool setvalue(char val){ return this->value = val; };
	
	DataPair &operator=(DataPair &org);
	DataPair &operator++(){ this->priority++; };
};