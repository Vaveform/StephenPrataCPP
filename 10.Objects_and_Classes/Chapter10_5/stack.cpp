#include "stack.h"


Stack::Stack(){
	this->top = 0; // setting pointer to top on the begin of stack
}

bool Stack::isfull() const {
	return this->top == MAX;
}

bool Stack::isempty() const{
	return this->top == 0;
}

bool Stack::push(const Item& item){
	if(this->top < MAX){
		// using postfix increment (making copy of last value of top, 
		// increasing this->top original and return copy) and working 
		// default assignment operator for element with index which 
		// has value of copy (this->top - 1)
		this->items[this->top++] = item;
		return true;
	}
	else{
		return false;
	}
}


bool Stack::pop(Item& item){
	if(this->top > 0){
		// using prefix decrement - original value this->top decreased by one
		// and returning this value. Than for item calling compiler 
		// assignment operator by reference and all fields of top item of items 
		// (field by field) copy to item, which passed by reference
		item = this->items[--this->top];
		return true;
	}
	else{
		return false;
	}
}
