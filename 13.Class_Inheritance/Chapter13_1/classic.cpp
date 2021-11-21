#include "classic.h"
#include <iostream>



//class Classic : public Cd
//{
//	private:
//		char main_composition[50];
//	public:
//		Classic(const char* s1, 
//				const char* s2, 
//				const char* s3,
//				int n, 
//				double x);
//		Classic(const char* s3, const Cd& other);
//		virtual ~Classic();
//		virtual void Report() const;
//}


Classic::Classic(const char* s1, const char* s2, 
		const char* s3, int n, double x) : Cd::Cd(s1, s2, n, x)
{
	const char* ptr = s3;
	int i = 0;
	while(*ptr != '\0' && i < 49){
		main_composition[i++] = *(ptr++); 
	}
	main_composition[i] = '\0';
}

Classic::Classic(const char* s3, const Cd& other) : Cd::Cd(other)
{
	const char* ptr = s3;
	int i = 0;
	while(*ptr != '\0' && i < 49){
		main_composition[i++] = *(ptr++); 
	}
	main_composition[i] = '\0';
}

Classic::~Classic(){
	std::cout << "Working destructor of Classic" << std::endl;
}

void Classic::Report() const{
	Cd::Report();
	std::cout << "Main composition: " << main_composition << std::endl;
}
