#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include "vect.h"

const char* file_name_res = "result.txt";

int main()
{
	using namespace std;
	using VECTOR::Vector;
	
	// Delete old file with data
	remove(file_name_res);
	ofstream output(file_name_res);
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while(cin >> target)
	{
		cout << "Enter step length: ";
		if(!(cin >> dstep))
			break;
		output << "Target Distance: " << target << ", "
			<< "Step Size: " << dstep << endl;
		while(result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			output << steps << ": " << result << endl;
			steps++;
		}
		output << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		output << result << endl;
		result.polar_mode();
		output << " or\n" << result << endl;
		output << "Average outward distance per step = "
			<< result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
		continue;
	return 0;
}
