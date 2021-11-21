#include "wine.h"
#include <iomanip>

Wine::Wine() : std::string("Null") {
	// For Pair<std::valarray<int>, std::valarray<int>> - simply call
	// default constructor
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : std::string(l), PairArray(y, yr, bot)
{
	//// first - array of years
	//years_bottles.first = ArrayInt(yr, y);
	//// second - array of number of bottles
	//years_bottles.second = ArrayInt(bot, y);
}


Wine::Wine(const char *l, int y) : std::string(l), PairArray(y)
{
	//// After default constructor of valarray
	//years_bottles.first.resize(y);
	//years_bottles.second.resize(y);
}

Wine::~Wine(){}

const std::string& Wine::Label() const
{
	return (const std::string&)(*this);
}

//int Wine::sum() const {
//	return this->second.sum();
//}

void Wine::GetBottles(){
	using std::cout;
	using std::cin;
	using std::endl;
	size_t s = Size();
	cout << "Enter " << (const std::string&)(*this) << " data for " 
		<< s << " year(s):" << endl;
	PairArray tmp(s);
	for(int i = 0; i < s; ++i)
	{
		cout << "Enter year: ";
		cin >> tmp.first[i];
		cout << "Enter bottles for that year: ";
		cin >> tmp.second[i];
	}
	this->PairArray::operator=(tmp);
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << (const std::string&)(*this) << endl;
	cout << std::right << std::setw(12) << "Year" << "    " 
		<< std::left << std::setw(32) << "Bottles" << endl;
	
	size_t s = Size();
	for(int i = 0; i < s; ++i)
	{
		cout << std::right << std::setw(12) << this->first[i] << "    " 
			<< std::left << std::setw(32) << this->second[i] << endl;
	}

}



