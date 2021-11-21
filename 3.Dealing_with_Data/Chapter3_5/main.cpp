#include <iostream>

using namespace std;

int main()
{
	unsigned long long world_population, rus_population;
	cout << "Enter the world's population: ";
	cin >> world_population;
	cout << "Enter the population of the Russia: ";
	cin >> rus_population;
	long double percentage = 100 * (double(rus_population) / world_population);
	cout << "The population of the Russia is " << percentage << "% of the world population." << endl; 
	return 0;
}
