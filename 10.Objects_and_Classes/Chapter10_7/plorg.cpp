#include <iostream>

#include "plorg.h"



Plorg::Plorg(const char* _name, int CI){
	this->contentment_index = CI;
	const char* insert_it = _name;
	int i = 0;
	while(i < Len - 1 && *insert_it != '\0'){
		this->name[i++] = *(insert_it++);
	}
	this->name[i] = '\0';
}


void Plorg::Info() const {
	std::cout << "Plorg has name " << this->name 
		<< " and contentment index " << this->contentment_index << std::endl;
}


void Plorg::ChangeCI(int CI){
	this->contentment_index = CI;
}
