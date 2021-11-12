#include <iostream>
#include <fstream>
#include <ios>

int main(int argc, char*argv[])
{
	using namespace std;
	if(argc < 2)
	{
		cerr << "Filename not given" << endl;
		exit(EXIT_FAILURE);
	}
	ofstream to_write(argv[1], ios_base::app | ios_base::out);
	if(!to_write.is_open())
	{
		cerr << "Cannot to open file " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Enter text: ";
	char read_symbol;
	cin.get(read_symbol);
	while(cin.good() && read_symbol != '\n')
	{
		to_write << read_symbol;
		cin.get(read_symbol);
	}
	cin.clear();
	to_write.clear();
	return 0;
}
