
#ifndef STACK2_H_
#define STACK2_H_
#include <iostream>
typedef unsigned long Item;

class Stack
{
	private:
		enum {MAX = 10};
		Item* pitems;
		int size;
		int top;
	public:
		Stack(int n = 10);
		Stack(const Stack& st);
		~Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item&);
		bool pop(Item&);
		Stack& operator=(const Stack&);
};

#endif
