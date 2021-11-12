#include <iostream>
#include <cmath>
#include "exceptions_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x,y,z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			double gmean_res = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean_res << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch(mean_error& me)
		{
			me.mesg();
			//cout << "Values used: " << hg.v1 << ", "
			//	<< hg.v2 << endl;
			cout << "Sorry, you don't to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if(a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
