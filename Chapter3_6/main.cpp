#include <iostream>

using namespace std;

int main()
{
	cout << "Enter distance in kilometrs: ";
	double dist;
	cin >> dist;
	cout << "Enter volume of fuel in liters: ";
	double volume;
	cin >> volume;
	cout << "Expenses of fuel (on 100 kilometrs): " << 100 * (volume/dist) << endl;
	return 0;
}
