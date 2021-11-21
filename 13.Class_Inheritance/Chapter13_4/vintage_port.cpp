#include "vintage_port.h"

VintagePort::VintagePort() : year(0) {
	nickname = new char[std::strlen("none") + 1];
	std::strcpy(nickname, "none");
}

VintagePort::VintagePort(const char* br, int b, 
		const char* nn, int y) : Port(br, "vintage", b), year(y)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp), year(vp.year)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
}

VintagePort::~VintagePort(){
	delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp){
	if(this == &vp){
		return *this;
	}
	// Calling base constructor overloading version of operator=
	// or Port::operator=(vp) - VintagePort& easily converted to Port&
	// we can select version of operator overloading(base, derived version)
	// by using dynamic_cast or c-style cast (if we have two version of operator
	// overloading one in base and other in derived)
	dynamic_cast<Port&>(*this) = vp; // assignment base part of vp to base part of this object
	// Assign to derived part;
	year = vp.year;
        delete[] nickname;	
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	return *this;

}

void VintagePort::Show() const
{
	// std::cout << "Recursion!!!" << std::endl;
	// const Port& ref = dynamic_cast<const Port&>(*this);
	// ref.Show(); // - calling virtual function after dynamic_cast to base - bad!!!
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp){
	os << (const Port&)vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}



