#include <iostream>
#include <fstream>
#include <ios>

void Write_line_to_outputFile(std::istream& input, std::ostream& output)
{
	char byte_symbol;
	input.get(byte_symbol);
	while(input.good() && byte_symbol != '\n'){
		output << byte_symbol;
		input.get(byte_symbol);
	}
}



int main(int argc, char* argv[])
{
	using namespace std;
	if(argc < 4)
	{
		cerr << "Not enough parametrs for concatination files" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream first_input(argv[1], ios_base::in);
	if(!first_input.is_open())
	{
		cerr << "Cannot to open first file" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream second_input(argv[2], ios_base::in);
	if(!second_input.is_open())
	{
		cerr << "Cannot to open second file" << endl;
		exit(EXIT_FAILURE);
	}
	ofstream concat_output(argv[3], ios_base::out | ios_base::trunc);
	if(!concat_output.is_open())
	{
		cerr << "Cannot to open file for writting" << endl;
		exit(EXIT_FAILURE);
	}
	char EOF_check_first;
	char EOF_check_second;
	while(first_input.good() || second_input.good())
	{
		EOF_check_second = second_input.peek();
		EOF_check_first = first_input.peek();
		if(EOF_check_first == EOF && EOF_check_second != EOF)
		{
			Write_line_to_outputFile(second_input, concat_output);
			concat_output << '\n';
		}
		else if(EOF_check_first != EOF && EOF_check_second != EOF)
		{
			Write_line_to_outputFile(first_input, concat_output);
			concat_output << " ";
			Write_line_to_outputFile(second_input, concat_output);
			concat_output << '\n';
		}
		else if(EOF_check_first == EOF && EOF_check_second == EOF)
			break;
		else{
			Write_line_to_outputFile(first_input, concat_output);
			concat_output << '\n';
		}
	}
	

	return 0;
}
