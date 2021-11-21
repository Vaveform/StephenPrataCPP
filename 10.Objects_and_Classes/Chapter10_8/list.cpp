#include <iostream>

#include "list.h"



List::Node::Node(const Item& val, Node* next){
	std::cout << "Calling constructor of node with parametrs" << std::endl;
	this->value = val;
	this->_next = next;
}

List::Node::Node(){
	std::cout << "Calling default constructor of node" << std::endl;
	this->_next = nullptr;
}

List::Node::~Node(){
	std::cout << "Destructed node " << (void*)this << std::endl;
}


List::List(){
	this->size = 0;
	ptr_to_begin = ptr_to_last = nullptr;
}

bool List::isEmpty() const {
	return this->size == 0;
}

bool List::isFull() const {
	return this->size == MAX;
}

bool List::push(const Item& val){
	if(this->isEmpty()){
		this->ptr_to_begin = this->ptr_to_last = new Node(val);
		this->size++;
		return true;
	}
	else if(this->isFull()){
		std::cout << "list is full - can not add new node" << std::endl;
		return false;
	}
	this->ptr_to_last->_next = new Node(val);
	this->ptr_to_last = this->ptr_to_last->_next;
	this->size++;
	return true;
}

void List::VisitAll(void(*functor)(Item& val)){
	Node* begin = this->ptr_to_begin;
	while(begin != nullptr){
		functor(begin->value);
		begin = begin->_next;
	}
}

List::~List(){
	std::cout << "Deconstructed list with " << this->size << " nodes: " << std::endl;
	Node* ptr_to_delete = nullptr;
	while(this->ptr_to_begin != nullptr){
		ptr_to_delete = this->ptr_to_begin;
		this->ptr_to_begin = this->ptr_to_begin->_next;
		delete ptr_to_delete;

	}
	

}


