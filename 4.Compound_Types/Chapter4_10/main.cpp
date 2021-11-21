#include <iostream>
#include <array>

int main()
{
	using namespace std;
	// For template array class non type second argument should be constant int
	// but for in-built array in modern compilers size may be non-constant
	// templates more safely works with non type parametrs
	const int runs_size = 3;
	array<double, runs_size> results = {{0}};
	long double sum = 0.0;
	int entered = 0;
	for(double& value : results)
	{
		cout << "Enter result #" << entered + 1 << ": ";
		cin >> value;
		if(!cin) break;
		while(cin && cin.get() != '\n') continue;
		sum += value;
		entered++;
	}
	if(!entered) 
	{
		cout << "No results provided" << endl; 
		exit(EXIT_FAILURE);
	}
	cout << "Entered results: ";
	for(const double& c_val : results) cout << c_val << " ";
	cout << endl;
	cout << "Avarage value of results: " << sum / entered << endl;
	return 0;
}
