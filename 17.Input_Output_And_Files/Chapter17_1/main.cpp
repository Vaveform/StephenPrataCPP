#include <iostream>




int main()
{
	using std::cin;
	using std::cout;
	using std::cerr;
	using std::endl;
	size_t counter = 0;
	cout << "Enter delimetr symbol: ";
	char delim;
	cin.get(delim);
	while(cin.get() != '\n')
		continue;
	char read_symbol = '\0';
	cout << "Enter word flow: ";
	while(cin.good() && 
			read_symbol != '\n' 
			&& cin.peek() != delim)
	{
		cin.get(read_symbol);
		++counter;
	}
	if(cin.eof() || read_symbol == '\n'){
		cout << "Reached end of cin. Number of symbols: " 
			<< counter 
		       	<< endl;
		exit(EXIT_SUCCESS);
	}
	else if(cin.bad() || cin.fail())
	{
		cerr << "Error in reading of cin." << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Symbol" << delim 
			<< " found in cin. Number of symbols before " 
			<< delim << ": " << counter << endl;
	}
	cout << "Tail part of input: ";
	while(cin.good() && (read_symbol = cin.get()) != '\n')
		cout << read_symbol;
	cout << endl;
	return 0;
}
