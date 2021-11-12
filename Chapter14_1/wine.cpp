#include "wine.h"
#include <iomanip>

Wine::Wine() : label("Null") {
	// For Pair<std::valarray<int>, std::valarray<int>> - simply call
	// default constructor
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) : label(l), years_bottles(y, yr, bot)
{
	//// first - array of years
	//years_bottles.first = ArrayInt(yr, y);
	//// second - array of number of bottles
	//years_bottles.second = ArrayInt(bot, y);
}


Wine::Wine(const char *l, int y) : label(l), years_bottles(y)
{
	//// After default constructor of valarray
	//years_bottles.first.resize(y);
	//years_bottles.second.resize(y);
}

Wine::~Wine(){}

const std::string& Wine::Label() const
{
	return label;
}

int Wine::sum() const {
	return years_bottles.second.sum();
}

void Wine::GetBottles(){
	using std::cout;
	using std::cin;
	using std::endl;
	size_t s = years_bottles.first.size();
	cout << "Enter " << label << " data for " 
		<< s << " year(s):" << endl;
	for(int i = 0; i < s; ++i)
	{
		cout << "Enter year: ";
		cin >> years_bottles.first[i];
		cout << "Enter bottles for that year: ";
		cin >> years_bottles.second[i];
	}
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << label << endl;
	cout << std::right << std::setw(12) << "Year" << "    " 
		<< std::left << std::setw(32) << "Bottles" << endl;
	
	size_t s = years_bottles.first.size();
	for(int i = 0; i < s; ++i)
	{
		cout << std::right << std::setw(12) << years_bottles.first[i] << "    " 
			<< std::left << std::setw(32) << years_bottles.second[i] << endl;
	}

}



