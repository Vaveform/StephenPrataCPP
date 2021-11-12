#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include "vect.h"


int main()
{
	using namespace std;
	using VECTOR::Vector;
	
	// Delete old file with data
	//ofstream output(file_name_res);
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int N = 1;
	cout << "Enter target distance (q to quit): ";
	while(cin >> target)
	{
		cout << "Enter step length: ";
		if(!(cin >> dstep))
			break;
		cout << "Enter number of samples(N): ";
		if(!(cin >> N))
			break;
		cout << "Target Distance: " << target << ", "
			<< "Step Size: " << dstep << ", Number of samples: " 
			<< N << endl;
		int delim = N;
		int min, max;
		double average = 0.0;
		while(N != 0){
			while(result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				cout << steps << ": " << result << endl;
				steps++;
			}
			cout << "After " << steps << " steps, the subject "
				<< "has the following location:\n";
			cout << result << endl;
			result.polar_mode();
			cout << " or\n" << result << endl;
			cout << "Average outward distance per step = "
				<< result.magval()/steps << endl;
			if(delim == N){
				max = max = steps;
			}
			else{
				if(steps > max) max = steps;
				if(steps < min) min = steps;
			}
			average += steps;
			steps = 0;
			result.reset(0.0, 0.0);
			--N;
		}
		average /= delim;
		// We can use formula (theoretical for checking): N = (D/s)*(D/s)
		// where N - average number of steps for D (distance) and s (step size)
		cout << "Max number of steps for distance " << target 
			<< " and step size " << dstep 
			<< " for " << delim  << " samples is " << max << endl; 
		cout << "Min number of steps for distance " << target 
			<< " and step size " << dstep 
			<< " for " << delim << " samples is " << min << endl; 
		cout << "Average number of steps for distance " << target 
			<< " and step size " << dstep 
			<< " for " << delim << " samples is " << average 
			<< "\nTheoretical average number of steps: " 
			<< ((double)target/dstep)*((double)target/dstep) << endl; 
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
		continue;
	return 0;
}
