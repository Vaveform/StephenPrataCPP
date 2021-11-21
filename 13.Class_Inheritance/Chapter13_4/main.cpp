#include "vintage_port.h"

int main(){
	Port first("Ficachi", "tawny", 12);
	first.Show();
	std::cout << first << std::endl;
	first += 5;
	first.Show();
	std::cout << first << std::endl;
	first -= 2;
	first.Show();
	std::cout << first << std::endl;
	first -= 100;
	first.Show();
	std::cout << first << std::endl;
	VintagePort second("Ferrari", 10, "Alex", 1923);
	second.Show();
	std::cout << second << std::endl;
	// Calling += and -= operator (they are overloaded in Port)
	second += 2;
	second.Show();
	std::cout << second << std::endl;
	second -= 4;
	second.Show();
	std::cout << second << std::endl;
	// Copy constructor
	VintagePort third = second;
	third.Show();
	std::cout << third << std::endl;
	VintagePort forth;
	forth = third;
	forth.Show();
	std::cout << forth << std::endl;
	// Polimorphism
	Port* p_ptr = &forth;
	p_ptr->Show();
	return 0;
}
