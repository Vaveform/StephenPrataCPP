#include <iostream>

using namespace std;


const int INCHES_PER_FEET = 12;

int main()
{
	unsigned short input_field_width = 5;
	unsigned int entered_height;
	cout << "Enter your height (in inches):";
	for(int i = 0; i < input_field_width; ++i)
		cout.put('_');
	for(int i = 0; i < input_field_width; ++i)
		cout.put('\b');
	cin >> entered_height;
	while(cin && cin.get() != '\n') continue;
	unsigned int feets = entered_height / INCHES_PER_FEET;
	unsigned int inches = entered_height % INCHES_PER_FEET;
	cout << "Your height is " << feets << " feets and " << inches << " inches" << endl;
	return 0;
}
