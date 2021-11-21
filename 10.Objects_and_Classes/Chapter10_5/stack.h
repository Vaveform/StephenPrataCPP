#ifndef STACK_H_
#define STACK_H_

#include "customer.h"

typedef customer Item;

class Stack{
	private:
		enum {MAX = 10}; // 1 way to declare size of array (see Chapter10_4 - sales.h)
		Item items[MAX]; // array for saving elements of stack (LIFO)
		int top; // pointer to top of the stack
	public:
		Stack();
		bool isfull() const;
		bool isempty() const;
		// push return false if stack full, true if not
		bool push(const Item& item); // add element to top of the stack
		// pop return false  if stack empty, true if not
		bool pop(Item& item); // delete element from the top and safe in passing parametr
};

#endif
