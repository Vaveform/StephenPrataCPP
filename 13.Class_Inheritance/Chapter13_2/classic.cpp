#include "classic.h"
#include <iostream>


//class Classic : public Cd
//{
//	private:
//		char* main_composition;
//	public:
//		Classic(const char* s1 = "No performers", 
//				const char* s2 = "No label", 
//				const char* s3 = "No composition",
//				int n = 0, 
//				double x = 0);
//		Classic(const char* s3, const Cd& other);
//		Classic(const Classic& other);
//		Classic& operator=(const Classic& other);
//		virtual ~Classic();
//		virtual void Report() const;
//};

Classic::Classic(const char* s1, const char* s2, 
		const char* s3, int n, double x) : Cd::Cd(s1, s2, n, x)
{
	main_composition = new char[std::strlen(s3) + 1];
	std::strcpy(main_composition, s3);
}

Classic::Classic(const char* s3, const Cd& other) : Cd::Cd(other)
{
	main_composition = new char[std::strlen(s3) + 1];
	std::strcpy(main_composition, s3);
}

Classic::Classic(const Classic& other) : Cd(other) {
	
	main_composition = new char[std::strlen(other.main_composition) + 1];
	std::strcpy(main_composition, other.main_composition);
}

Classic& Classic::operator=(const Classic& other){
	if(this == &other)
		return *this;
	Cd::operator=(other);
	delete[] main_composition;
	main_composition = new char[std::strlen(other.main_composition) + 1];
	std::strcpy(main_composition, other.main_composition);

}

Classic::~Classic(){
	std::cout << "Working destructor of Classic" << std::endl;
	delete[] main_composition;
}

void Classic::Report() const{
	Cd::Report();
	std::cout << "Main composition: " << main_composition << std::endl;
}
