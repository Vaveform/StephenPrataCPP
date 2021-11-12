#include "stonewt.h"

int main()
{
	using namespace std;
	// Default constructor
	Stonewt first;
	// Constructor with one parametr
	Stonewt second = Stonewt(12.1);
	// Constructor with three parametrs
	Stonewt third = Stonewt(150, 5.1);
	// Sum of two objects;
	first = second + third;
	cout << second  << " + "<< third << " = " << first << endl;
	// Diff if two objects;
	cout << third << " - " << second << " = "  << third - second << endl;
	// Bad diff
	cout << second << " - " << third << " = "  << second - third << endl;
	// Multiply of objects
	cout << second << " * " << third << " = " << second * third << endl;
	// Multiply with n
	double n = 1.5;
	cout << second << " * " << n << " = " << second * n << endl;
	// Multiply n on second
	cout << n << " * " << second << " = " << n * second << endl;
	cout << "First: " << first << endl;
	cout << "Second: " << second << endl;
	cout << "Third: " << third << endl;
	first.Stone_mode();
	cout  << "First in stone mode: " << first << endl;
	first.Int_lbs();
	cout << "First in int lbs mode: " << first << endl;
	first.Double_lbs();
	cout << "First in double lbs mode: " << first << endl;
	return 0;
}
