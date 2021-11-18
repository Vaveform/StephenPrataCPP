#include <iostream>
#include <cstring>
#include <ios>
#include <iomanip>
using namespace std;


int main()
{
	char selection;

	while(selection != 'q')
	{
		cout << "Please enter one of the following choices:\n";
		cout << setw(20) << left << "g) to say hello"; 
		cout << "l) to go to exam" << endl;
		cout << setw(20) << left << "p) to be positive"; 
		cout << "y) to be lord" << endl;
		cout << "q) to quit" << endl;
		cin >> selection;

		while(strchr("gplyq", selection) == NULL)
		{
			cout << "Please enter g, p, l, y or q to quit:";
			cin >> selection;
		}
		switch(selection)
		{
			case 'g': cout << "Hello!" << endl;
				  break;
			case 'p': cout << "It's a good day" << endl;
				  break;
			case 'l': cout << "Good luck" << endl;
				  break;
			case 'y': cout << "Greedings, Sir!" << endl;
				  break;
		}
	}
	cout << "Bye!\n";
	return 0;
}
