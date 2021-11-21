#include <iostream>
#include <cstring>
#include <string>
using namespace std;


void string_to_upper(string& str)
{
	for(size_t i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);
}


int main()
{
	string to_modif;
	cout << "Enter a string (q to quit): ";
	while(getline(cin, to_modif) && to_modif != "q")
	{

		string_to_upper(to_modif);
		cout << to_modif << endl;
		cout << "Enter a string (q to quit): ";
	}
	cout << "Bye." << endl;
	return 0;
}
