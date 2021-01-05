#include "Pair.h"

DataPair &DataPair::operator=(DataPair &org){
	
	if(this->value == org.value)
		return *this;
	
	this->priority = org.priority;
	this->value = org.value;
	
	return *this;
}