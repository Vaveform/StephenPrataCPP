#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2) 
	{
		cerr << "You are not passed file name" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile.is_open())
	{
		cerr << "File was didn't open" << endl;
		exit(EXIT_FAILURE);
	}
	long long symbols_c = 0;
	while(inFile && inFile.get() != EOF) ++symbols_c;
	cout << "In passed file: " << symbols_c << " symbols" << endl;
	return 0;
}
