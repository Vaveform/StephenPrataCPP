#include <iostream>
#include <string>
using namespace std;

struct car
{
	string manufacturer;
	int year;
};


int main()
{
	int collection_s = 0;
	cout << "Enter car collection size: ";
	cin >> collection_s;
	while(cin && cin.get() != '\n') continue;
	if(!cin) return EXIT_FAILURE;

	car* collection = new car[collection_s];

	int i = 0;

	do{
		cout << "Car #" << i + 1 << ":"  << endl;
		cout << "Enter manufacturer: ";
		getline(cin, collection[i].manufacturer);
		cout << "Enter year: ";
		cin >> collection[i++].year;
		while(cin && cin.get() != '\n') continue;
	}while(cin && i < collection_s);
	

	cout << "Your collection: " << endl;
	for(int j = 0; j < i; ++j)
		cout << collection[j].year << " " << collection[j].manufacturer << endl;
	delete[] collection;

	return 0;
}
