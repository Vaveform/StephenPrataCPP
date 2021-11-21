#include <iostream>

long double light_years_to_units(double);


int main()
{
	using namespace std;
	double light_years;
	cout << "Enter the number of light years: ";
	cin >> light_years;
	cout << light_years << " light years = " 
		<< light_years_to_units(light_years) 
		<< " astronomical units." << endl;
	return 0;
}


long double light_years_to_units(double light_years)
{
	const unsigned long units_in_light_year = 63240;
	return light_years * units_in_light_year;
}
