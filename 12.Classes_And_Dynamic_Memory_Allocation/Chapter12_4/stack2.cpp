

#include "stack2.h"

Stack::Stack(int n) : size(n), top(0){
	pitems = new Item[n];
}
Stack::Stack(const Stack& st) : size(st.size), top(st.top)
{
	pitems = new Item[size];
	for(int i = 0; i < top; ++i){
		pitems[i] = st.pitems[i];
	}

}
Stack& Stack::operator=(const Stack& other)
{
	if(this == &other){
		return *this;
	}
	delete[] pitems;
	size = other.size;
	top = other.top;
	pitems = new Item[size];
	for(int i = 0; i < top; ++i){
		pitems[i] = other.pitems[i];
	}
	return *this;
}
bool Stack::isempty() const{
	return top == 0;
}
bool Stack::isfull() const{
	return top == size;
}
bool Stack::push(const Item& element){
	if(isfull()){
		return false;
	}
	pitems[top++] = element;
	return true;
}
bool Stack::pop(Item& ref_to_popped){
	if(isempty()){
		return false;
	}
	ref_to_popped = pitems[--top];
	return true;
}
Stack::~Stack(){
	delete [] pitems;
}
