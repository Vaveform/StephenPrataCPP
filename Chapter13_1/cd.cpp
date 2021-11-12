#include "cd.h"
#include <iostream>

Cd::Cd(const char* s1, const char* s2, int n, double x) : selections(n), playtime(x)
{
	const char* ptr = s1;
	int i = 0;
	while(*ptr != '\0' && i < 49){
		performers[i++] = *(ptr++); 
	}
	performers[i] = '\0';
	i = 0;
	ptr = s2;
	while(*ptr != '\0' && i < 19){
		label[i++] = *(ptr++); 
	}
	label[i] = '\0';

}

Cd::~Cd(){
	std::cout << "Working Cd destructor" << std::endl;
}

void Cd::Report() const {
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}
