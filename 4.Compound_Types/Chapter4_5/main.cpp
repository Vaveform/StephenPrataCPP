#include <iostream>

struct CandyBar
{
	char name[20];
	double weight;
	int calories;
};

//string version of CandyBar structure
//struct CandyBar
//{
//	std::string name;
//	double weight;
//	int calories
//};


int main()
{
	using namespace std;
	// Old C++. It is work in C++11 ofcourse
	// CandyBar snack = {"Mocha Munch", 2.3, 350};
	// C++11
	CandyBar snack{"Mocha Munch", 2.3, 350};
	cout << "Snack elements: " << endl;
	// To get elements from snack you should use operator . (membership oeprator)
	cout << "name: " << snack.name << endl;
	cout << "weight: " << snack.weight << endl;
	cout << "calories: " << snack.calories << endl;
	return 0;
}
