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


const int box_size = 3;

int main()
{
	using namespace std;

	// New init of array of structures
	CandyBar* candies = new CandyBar[box_size]{
		{"Sweets", 1.5, 167},
		{"Bonch", 3.567, 567},
		{"Pop", 1.234, 123}
	};
	for(int i = 0; i < box_size; ++i){
		// To get elements from snack you should use operator . (membership oeprator)
		cout << "name: " << candies[i].name << endl;
		cout << "weight: " << candies[i].weight << endl;
		cout << "calories: " << candies[i].calories << endl;
	}

	delete[] candies;
	return 0;
}
