#include <iostream>


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Enter your age: ";
	int ages = 0;
	cin >> ages;
	cout << "Your age in months is " << ages * 12 << "." << endl;
	return 0;
}
