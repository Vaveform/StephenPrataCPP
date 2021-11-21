#include <iostream>

using namespace std;

const double MILES_PER_KILOMETR = 0.6214;
const double GALONS_PER_LITER = 1 / 3.875;


int main()
{
	cout << "Enter fuel expenses (liters per 100 kilometrs): ";
	double european_expanse;
	cin >> european_expanse;
	european_expanse /= 100; // Giving liters per kilometr
	double us_expanse = 1 / european_expanse; // Giving kilometrs per liters
	us_expanse *= ( MILES_PER_KILOMETR / GALONS_PER_LITER);
	cout << "Miles per galon (USA notation): " << us_expanse << endl;
	return 0;
}
