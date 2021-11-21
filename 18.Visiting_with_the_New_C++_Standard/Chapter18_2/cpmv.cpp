#include "cpmv.h"
#include <utility>

Cpmv::Cpmv()
{
	std::cout << "Called default constructor Cpmv" << std::endl;
	// Calling default (compiler generated constructor) of Info
	// which call default of object std::string qcode and zcode
	// with 0 symbols
	pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
{
	std::cout << "Called constructor Cpmv with parametrs:\n";
	std::cout << "q: " << q << " and z: " << z << std::endl;
	// Calling move constructor for strings objects
	// in Info structure - q and z copied to this constructor
	// and after copied objects not need - we can simply moved from copies
	pi = new Info{std::move(q), std::move(z)};
	std::cout << "q after move: " << q << std::endl;
	std::cout << "z after move: " << z << std::endl;
}

Cpmv::Cpmv(const Cpmv& cp)
{	
	std::cout << "Called copy constructor of Cpmv" << std::endl;
	// Copying strings
	pi = new Info{cp.pi->qcode, cp.pi->zcode};
}


Cpmv::Cpmv(Cpmv&& mv)
{
	std::cout << "Called move constructor of Cpmv" << std::endl;
	//pi = mv.pi;
	//mv.pi = nullptr;
	pi = new Info{std::move(mv.pi->qcode), std::move(mv.pi->zcode)};
}

Cpmv::~Cpmv()
{
	std::cout << "Called destructor of Cpmv" << std::endl;
	delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	std::cout << "Called copy assignment operator" << std::endl;
	if(this == &cp)
		return *this;
	delete pi;
	pi = new Info{cp.pi->qcode, cp.pi->zcode};
	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	std::cout << "Called move assignemnt operator" << std::endl;
	// rvalue reference has the same syntax
	// of operators as a lvalue ref
	if(this == &mv)
	{
		return *this;
	}
	// We have swap pointers, but i symply delete
	// pi of current object
	//delete pi;
	//pi = mv.pi;
	//mv.pi = nullptr; // nullptr pointer works with delete without exceptions and errors
	pi = new Info{std::move(mv.pi->qcode), std::move(mv.pi->zcode)};
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	std::cout << "Cpmv::operator+" << std::endl;
	Cpmv tmp(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
	return tmp;
}

void Cpmv::Display() const
{
	// We can use pi = new Info{std::move(mv.pi->qcode), std::move(mv.pi->zcode)};
	// and we will no need to use if else, because qcode and zcode moved and has 0 symbols
	// and symply can printed as empty string
	//if(pi == nullptr)
	//	std::cout << "Empty pi of object " << this << std::endl;
	//else
	//{
	//	std::cout << "Object: " << this << std::endl;
	//	std::cout << "pi->qcode: " << pi->qcode << std::endl;
	//	std::cout << "pi->zcode: " << pi->zcode << std::endl;
	//}
	std::cout << "Object: " << this << std::endl;
	std::cout << "pi->qcode: " << pi->qcode << std::endl;
	std::cout << "pi->zcode: " << pi->zcode << std::endl;
}

