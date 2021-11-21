#include <iostream>
#include "list.h"


void Print(Item& item){
	std::cout << item << std::endl;
}

void Increase(Item& item){
	++item;
}

int main(){
	List l;
	Item val;
	std::cout << "Input values to insert to list: " << std::endl;
	while(std::cin >> val && l.push(val)){};
	std::cout << "Before increasing all" << std::endl;
	l.VisitAll(Print);
	l.VisitAll(Increase);
	std::cout << "After insreasing all" << std::endl;
	l.VisitAll(Print);
	std::cout << "l is full? " << l.isFull() 
		<< " or is empty? " << l.isEmpty() << std::endl;
	List k;
	std::cout << "k is full? " << k.isFull() 
		<< " or is empty? " << k.isEmpty() << std::endl;
	return 0;
}
