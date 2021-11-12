#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person{
	private:
		static const int LIMIT = 25;
		std::string lname;
		char fname[LIMIT];
	public:
		Person();
		Person(const std::string& ln, const char* fn = "Heyyou");

		void Show() const; // First Name Last Name
		void FormalShow() const; // Last Name, First Name
};

#endif
