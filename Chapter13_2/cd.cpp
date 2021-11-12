#include "cd.h"
#include <iostream>


Cd::Cd(const char* s1, const char* s2, int n, double x) : selections(n), playtime(x)
{
	performers = new char[std::strlen(s1) + 1];
	std::strcpy(performers, s1);
	label = new char[std::strlen(s2) + 1];
	std::strcpy(label, s2);
}

Cd::Cd(const Cd& other) : selections(other.selections), playtime(other.playtime)
{
	performers = new char[std::strlen(other.performers) + 1];
	std::strcpy(performers, other.performers);
	label = new char[std::strlen(other.label) + 1];
	std::strcpy(label, other.label);
}

Cd::~Cd(){
	std::cout << "Working Cd destructor" << std::endl;
	delete[] performers;
	delete[] label;
}

Cd& Cd::operator=(const Cd& other){
	if(this == &other)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[std::strlen(other.performers) + 1];
	std::strcpy(performers, other.performers);
	label = new char[std::strlen(other.label) + 1];
	std::strcpy(label, other.label);
	selections = other.selections;
	playtime = other.playtime;
	return *this;

}

void Cd::Report() const {
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}
