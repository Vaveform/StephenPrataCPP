#include <iostream>
#include "move.h"


Move::Move(double a, double b) : x(a), y(b) {
	std::cout << "Calling constructor with x = " << a << " and y = " << b << std::endl;
}

void Move::showmove() const {
	std::cout << "Move-object " << (void*)this 
		<< " have x = " << this->x 
		<< " have y = " << this->y << std::endl;
}

void Move::reset(double a, double b){
	x = a;
	y = b;
}

Move Move::add(const Move& m) const{
	// We have access to private section of object m, 
	// because we access to fields from Move namespace.
	// If we access to m object in other class - we have not access to private!
	Move ready_object;
	ready_object.reset(this->x + m.x, this->y + m.y);
	return ready_object;
}
