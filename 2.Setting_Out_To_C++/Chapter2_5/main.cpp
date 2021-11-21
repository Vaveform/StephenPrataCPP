#include <iostream>

double celsius_to_fahr(double);


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double entered_celsius;
	cout << "Please enter a Celsius value: ";
	cin >> entered_celsius;
	cout << entered_celsius 
		<< " degrees Celsius is " << celsius_to_fahr(entered_celsius) 
		<< " degrees Fahrenheit" << endl;
	return 0;
}


double celsius_to_fahr(double celsius)
{
	return 1.8 * celsius + 32;
}
