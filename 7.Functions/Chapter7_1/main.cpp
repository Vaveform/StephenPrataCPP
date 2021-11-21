#include <iostream>

using namespace std;


double harmonic_mean(double x, double y)
{
	return 2.0 * x * x / (x + y);
}


void eat_line()
{
	while(cin.get() != '\n') continue;
}

int main()
{
	double x = 0.0, y = 0.0;
	cout << "Enter x and y numbers to get his harmonuc mean: ";
	while((cin >> x) && x > 0 && (cin >> y) && y > 0)
	{
		cout << "harmonic_mean of " 
			<< x << " and " 
			<< y << " is " 
			<< harmonic_mean(x, y) << endl;
		cout << "Enter next x and y (0 to quit):";
	}
	cout << "Bye\n";
	return 0;
}
