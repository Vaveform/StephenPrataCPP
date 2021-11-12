#include <iostream>
#include "person.h"


Person::Person(){
	lname = "";
	fname[0] = '\0';
};


Person::Person(const std::string& ln, const char* fn){
	this->lname = ln;
	int i = 0;
	const char* it = fn;
	while(i < LIMIT - 1 && *it != '\0'){
		this->fname[i++] = *(it++); 
	}
	this->fname[i] = '\0';
}

void Person::Show() const {
	std::cout << this->fname << " " << this->lname << std::endl;
}

void Person::FormalShow() const{
	std::cout << this->lname << ", " << this->fname << std::endl;
}
