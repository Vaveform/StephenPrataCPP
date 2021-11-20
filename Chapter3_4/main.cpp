#include <iostream>

using namespace std;

const unsigned int HOURS_PER_DAY = 24;
const unsigned int MINUTES_PER_HOUR = 60;
const unsigned int SECONDS_PER_MINUTE = 60;


int main()
{
	unsigned long long num_seconds;
	cout << "Enter the number of seconds: ";
	cin >> num_seconds;
	unsigned int days, hours, minutes, seconds;
	seconds = num_seconds % SECONDS_PER_MINUTE;
	minutes = num_seconds / SECONDS_PER_MINUTE;
	minutes %= MINUTES_PER_HOUR;
	hours = num_seconds / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR);
	hours %= HOURS_PER_DAY;
	days = num_seconds / (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

	cout << num_seconds << " seconds = " 
		<< days << " days " 
		<< hours << " hours " 
		<< minutes << " minutes " 
		<< seconds << " seconds" << endl;
	return 0;
}
