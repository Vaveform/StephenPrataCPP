#ifndef PLANET_H_
#define PLANET_H_

#include <iostream>
#include <iomanip>
#include <ios>


void eat_line(std::istream& is, char delim = '\n');

class Planet
{
	private:
		static const size_t LIM = 20;
		static bool is_interface;
		char name[LIM];
		size_t population;
		double g;
	public:
		static void SetUserFriendly();
		static void UnsetUserFriendly();
		Planet();
		std::ostream& BinaryOut(std::ostream& os) const;
		std::istream& BinaryIn(std::istream& is);
		std::ostream& TextOut(std::ostream& os) const;
		std::istream& TextIn(std::istream& is);
};

#endif
