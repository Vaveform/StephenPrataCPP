#include <iostream>
#include <ios>
#include <iomanip>
#include <cstring>
using namespace std;

const int strsize = 20;
const int community_s = 4;


struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;   // 0 - fullname, 1 - title, 2 - bopname
};

int main()
{
	bop community[community_s] = {
		{"Alex", "CEO", "Hunter", 0}, 
		{"Sasha", "Senior Programmer", "Coder", 2}, 
		{"Kolya", "Director", "Head", 1},
		{"John", "Software Engineer", "Gen", 1}
	};

	char selection = 'A';

	while(cin && (selection != 'q' && selection != 'Q'))
	{
		cout << "Please enter one of the following choices:\n";
		cout << setw(30) << left << "a. display by name"; 
		cout << "b. display by title" << endl;
		cout << setw(30) << left << "c. display by bopname"; 
		cout << "d. display by preference" << endl;
		cout << "q. to quit" << endl;
		cin >> selection;
		while(cin && cin.get() != '\n') continue;

		while(cin && strchr("ABCDQabcdq", selection) == NULL)
		{
			cout << "Please enter a, b, c, d or q to quit:";
			cin >> selection;
			while(cin && cin.get() != '\n') continue;
		}
		switch(selection)
		{
			case 'A':
			case 'a': for(int i = 0; i < community_s; ++i) cout << community[i].fullname << endl;
				  break;
			case 'B':
			case 'b': for(int i = 0; i < community_s; ++i) cout << community[i].title << endl;
				  break;
			case 'C':
			case 'c': for(int i = 0; i < community_s; ++i) cout << community[i].bopname << endl;
				  break;
			case 'D':
			case 'd': for(int i = 0; i < community_s; ++i)
				  {
					  switch(community[i].preference)
					  {
						  case 0: cout << community[i].fullname << endl;
							  break;
						  case 1: cout << community[i].title << endl;
							  break;
						  case 2: cout << community[i].bopname << endl;
							  break;
					  }
				  }
				  break;
		}
	}
	cout << "Bye!\n";

	return 0;
}
