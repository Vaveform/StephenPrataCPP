#include "port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b) : bottles(b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	int i = 0;
	const char* begin = st;
	while(*begin != '\0' && i < 19){
		style[i++] = *(begin++);
	}
	style[i] = '\0';

}

Port::Port(const Port& p) : bottles(p.bottles) {
	std::strcpy(style, p.style);
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);

}

Port::~Port(){
	delete [] brand;
}

Port& Port::operator=(const Port& p){
	if(this == &p)
		return *this;
	delete [] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b){
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b){
	if(b > bottles){
		return *this;
	}
	bottles -= b;
	return *this;
}

int Port::BottleCount() const{
	return bottles;
}

void Port::Show() const 
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << BottleCount() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", "<< p.style << ", " << p.BottleCount();
	return os;
}


