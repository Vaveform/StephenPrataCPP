#include <iostream>


void print_time(unsigned int, unsigned int);


int main()
{
	unsigned int hours, minutes;
	std::cout << "Enter the number of hours: ";
	std::cin >> hours;
	std::cout << "Enter the number of minutes: ";
	std::cin >> minutes;
	print_time(hours, minutes);
	return 0;
}


void print_time(unsigned int hours, unsigned int minutes)
{
	using namespace std;
	const unsigned short min_per_h = 60;
	cout << "Time: " << (hours + minutes / min_per_h) 
		<< ":" << minutes % min_per_h << endl;
}
