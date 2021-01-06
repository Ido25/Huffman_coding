#include "Pair.h"

Pair &Pair::operator=(const Pair &org){
	
	if(this == &org)
		return *this;
	
	this->priority = org.priority;
	this->value = org.value;
	
	return *this;
}
Pair &Pair::operator++(){
	
	this->priority++;
	
	return *this;
}
