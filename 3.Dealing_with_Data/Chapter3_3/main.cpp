#include <iostream>

using namespace std;

const int SEC_PER_MIN = 60;
const int MIN_PER_DEGREE = 60;


int main()
{
	cout << "ENTER a latitude in degrees, minutes and seconds:" << endl;
	unsigned int degrees, minutes, seconds;
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;
	// C++ cast (like function call)
	double result = degrees + double(minutes) / MIN_PER_DEGREE + double(seconds) / (MIN_PER_DEGREE * SEC_PER_MIN);
	minutes += seconds / SEC_PER_MIN;
	seconds %= SEC_PER_MIN;
	degrees += minutes / MIN_PER_DEGREE;
	minutes %= MIN_PER_DEGREE;
	cout << degrees << " degrees " 
		<< minutes << " minutes " 
		<< seconds << " seconds = " << result << " degrees" << endl;
	return 0;
}
