#include <iostream>
#include <ios>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void ShowStr(const std::string& str)
{
	std::cout << str << '\n';
}


class Store
{
	private:
		std::ostream& output_stream;
	public:
		Store(std::ostream& os = std::cout) : output_stream(os){}
		void operator()(const std::string& str)
		{
			if(output_stream.good())
			{
				size_t len = str.length();
				output_stream.write((char*)&len, sizeof(std::size_t));
				output_stream.write(str.data(), len);
				//std::cout << "Store to fout: " << len << " and " << str << std::endl;
			}
		}
};


std::string GetOneStr(std::istream& is)
{
	size_t readed_len;
	is.read((char*)&readed_len, sizeof(std::size_t));
	std::string insertion_string;
	insertion_string.reserve(readed_len);
	size_t i = 0;
	char readed_byte;
	while(i++ < readed_len){
		is.read((char*)&readed_byte, sizeof(char));
		insertion_string += readed_byte;
	}
	return insertion_string;
}



void GetStrs(std::istream& is, std::vector<std::string>& to_insert)
{
	while(is.good() && is.peek() != EOF)
	{
		to_insert.push_back(GetOneStr(is));
	}
	if(is.peek() == EOF)
		is.get();
}



int main(int argc, char* argv[])
{
	using namespace std;
	vector<string> vostr;
	string temp;

	cout << "Enter strings (empty line to quit):\n";
	while(getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	//fstream file("strings.dat", ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close(); // very important to close file!!!
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	fin.close();
	return 0;
}
