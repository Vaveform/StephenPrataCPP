#include <iostream>

using namespace std;


int main()
{
	cout << "Enter two integers to get sum of values between: ";
	int left = 0, sum = 0, right = 0;
	cin >> left >> right;
	if(!cin) return EXIT_FAILURE;
	while(left <= right) sum += left++;
	cout << "Sum values between entered values: " << sum << endl; 
	return 0;
}
