#include <iostream>

using namespace std;

int main()
{
	long double accumulated = 0;
	double input_value;
	do{
		cout << "Enter value: ";
		cin >> input_value;
		cout << "Accumulated: " << (accumulated += input_value) << endl;
	}while(cin && input_value != 0);
	cout << "Bye!" << endl;
	return 0;
}
