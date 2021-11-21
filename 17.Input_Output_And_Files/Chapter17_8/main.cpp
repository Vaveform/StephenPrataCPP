#include <iostream>
#include <ios>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <cstring>
#include "bplanetfile.h"


int main()
{
	using namespace std;
	BinaryPlanetFile file("Planets.dat");
	char symbol;
	while(true)
	{
		cout << "Enter: \n"
			<< "s - to show content\n"
			<< "a - to append record\n"
			<< "c - to change record\n"
			<< "d - to clear file\n"
			<< "q - to quit\n";
		cin >> symbol;
		if(!cin)
			continue;
		eat_line(cin);
		symbol = tolower(symbol);
		switch(symbol){
			case 's': file.CurrentContent();
				  break;
			case 'a': file.AppendRecord();
				  break;
			case 'c': cout << "Enter number of record: ";
				  size_t num;
				  cin >> num;
				  eat_line(cin);
				  file.ChangeRecord(num);
				  break;
			case 'd': file.ClearFile();
				  break;
			case 'q': return(EXIT_SUCCESS);
			default: continue;
		}
	}


	return 0;
}
