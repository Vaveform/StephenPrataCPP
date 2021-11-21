#include "golffunc.h"

void eat_line()
{
	using std::cin;
	while(cin && cin.get() != '\n') continue;
}


size_t read_golf_results(int _golf_results[], size_t size)
{
	using namespace std;
	if(size <= 0) return size;
	size_t counter = 0;
	do
	{
		cout << "Enter golf result for " << counter + 1 
			<< " element (0 to end):";
		cin >> _golf_results[counter]; // cin do not eating \n and space symbols - stay in input buffer
		eat_line();
	}
	while(cin && _golf_results[counter] > 0 && ++counter < size);
	return counter;
}

double mean_of_results(int _golf_results[], size_t size)
{
	if(size <= 0) return 0.0;
	double out = 0.0;
	for(size_t i = 0; i < size; ++i)
	{
		out += _golf_results[i];
	}
	return out / size;
}

void print_results(int _golf_results[], size_t size, double mean)
{
	using namespace std;
	cout << "Golf results: ";
	for(size_t i = 0; i < size; ++i)
		cout << _golf_results[i] << " ";
	cout << "Mean: " << mean << endl;
}
