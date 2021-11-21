#include <iostream>
#include <array>
#include <ios>
#include <iomanip>
using namespace std;

const int numberFactorials = 101;

int main()
{
	array<long double, numberFactorials> results;
	results[0] = results[1] = 1;
	for(int i = 2; i < results.max_size(); ++i)
		results[i] = i * results[i - 1];
	cout << "Calculated factorials:" << endl;
	for(int i = 0; i < results.max_size(); ++i)
		cout << i << "! = " << fixed << setprecision(0) << results[i] << endl;
	return 0;
}
