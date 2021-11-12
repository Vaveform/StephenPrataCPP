#include <iostream>
#include <fstream>
#include <ios>

int main(int argc, char* argv[])
{
	using namespace std;
	if(argc < 3)
	{
		cerr << "Not enough number of parametrs" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream to_read(argv[1], ios_base::binary | ios_base::in);
	if(!to_read.is_open())
	{
		cerr << "Cannot to open coping file " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	ofstream  to_write(argv[2], ios_base::binary | ios_base::out | ios_base::trunc);
	if(!to_write.is_open())
	{
		cerr << "Cannot to open dest file " << argv[2] << endl;
		exit(EXIT_FAILURE);
	}
	char read_byte;
	to_read.get(read_byte);
	while(to_read.good())
	{
		to_write << read_byte;
		to_read.get(read_byte);
	}
	to_read.clear();
	to_read.close();
	to_write.clear();
	to_write.close();
	return 0;
}
