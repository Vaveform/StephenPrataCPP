#include "cow.h"



Cow::Cow() : weight(0) {
	std::cout << "Working default constructor for " << (void*) this << std::endl;
	std::strcpy(this->name, "Unnamed cow");
	this->hobby = new char[20];
	std::strcpy(this->nobby, "No hobby");
}

Cow::Cow(const char* nm, const char* ho, double wt) : weight(wt)
{
	std::cout << "Working constructor with parametrs for " << (void*) this << std::endl;
	// copy nm to automatic array (static memory storage)
	int i = 0;
	const char* ptr = nm;
	while((i++) < 19 && *(ptr++) != '\0'){
		this->name[i] = *ptr;
	}
	this->name[i] = '\0';
	this->hobby = new char[std::strlen(ho) + 1];
	// copy ho to dynamic allocated array
	std::strcpy(this->hobby, ho);
}

Cow::Cow(const Cow& c) : weight(c.weight){
	std::cout << "Working copy constructor for " << (void*) this << std::endl;
	std::strcpy(this->name, c.name);
	this->hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(this->hobby, c.hobby);
}

Cow::~Cow(){
	std::cout << "Working destructor for " << (void*) this << std::endl;
	delete[] hobby;
	// name and weight automatic variables
}

Cow& Cow::operator=(const Cow& c){
	std::cout << "Working assignment operator for " << (void*) this << std::endl;
	// Check yourself assignment
	if(this == &c){
		return *this;
	}
	// Deleting old allocated memory for hobby
	// Attention! All constructors of this class
	// allocated memory for hobby field - it is a
	// good architecture - безобразно, но единообразно
	delete[] this->hobby;
	this->hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy[this->hobby, c.hobby];
	std::strcpy(this->name, c.name);
	//this->weight = c.weight;
	//int i = 0;
	//const char* ptr = c.name;
	//while((i++) < 19 && *(ptr++) != '\0'){
	//	this->name[i] = *ptr;
	//}
	//this->name[i] = '\0';
}

void Cow::ShowCow() const{
	std::cout << "Cow name: " << this->name << std::endl;
	std::cout << "Cow hobby: " << this->hobby << std::endl;
	std::cout << "Cow weight: " << this->weight << std::endl;
}
