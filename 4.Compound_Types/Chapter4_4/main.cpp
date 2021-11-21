#include <iostream>
#include <string>


int main()
{
	using namespace std;
	string fname;
	string concatenated;

	cout << "Enter your first name: ";
	getline(cin, fname);
	cout << "Enter your last name: ";
	getline(cin, concatenated);
	concatenated += ", " + move(fname);
	cout << "Here's the information in a single string: " << concatenated << endl;
	return 0;
}
