#include <iostream>
#include <cctype>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <functional>
#include <ios>
#include <sstream>
using namespace std;

bool Delete_Ends_Digits(const char& symbol, istream& input)
{
	if(strchr("@\n", symbol) != NULL){
		input.clear(ios_base::eofbit); 
		return false;
	}
	if(isdigit(symbol)){return false;}
	return true;
}

char UpperLower(const char& symbol)
{
	char out_symbol = symbol;
	if(isalpha(symbol)) isupper(symbol) ? out_symbol = tolower(symbol) : out_symbol = toupper(symbol);
	return out_symbol;
}




int main()
{
	// School solution
	//char read_symbol;
	//cout << "Enter input: ";
	//while(cin.get(read_symbol) && strchr("@\n", read_symbol) == NULL)
	//{
	//	if(isalpha(read_symbol))
	//	{
	//		if(isupper(read_symbol)) read_symbol = tolower(read_symbol);
	//		else
	//			read_symbol = toupper(read_symbol);
	//	}

	//	if(!isdigit(read_symbol)) cout.put(read_symbol);
	//}

	// STL solution C++11
	cout << "Enter input: ";
	istream& input = (cin >> noskipws);
	stringstream streamss;
	auto WithoutDigits = bind(Delete_Ends_Digits, placeholders::_1, ref(input));
	copy_if(istream_iterator<char>(input), istream_iterator<char>(), ostream_iterator<char>(streamss), WithoutDigits);
	streamss >> noskipws;
	cin >> skipws;
	transform(istream_iterator<char>(streamss), istream_iterator<char>(), ostream_iterator<char>(cout), UpperLower);

	cout << "\nBye\n";
	return 0;
}
