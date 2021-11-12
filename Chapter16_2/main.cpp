#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

bool Cleaner(const char& symbol)
{
	return strchr(" \t\n.,?';:+=-}]{[)(!", symbol) == NULL;
}

char LowerMaker(const char& symbol){
	return tolower(symbol);
}


bool IsPolindrome(const string& passed_string)
{
	string copy_str;
	copy_if(passed_string.begin(), passed_string.end(), back_inserter(copy_str), Cleaner);
	transform(copy_str.begin(), copy_str.end(), copy_str.begin(), LowerMaker);
	return copy_str.find(
			string(copy_str.rbegin() 
				+ int((double(copy_str.size()) / 2) + 0.5), 
				copy_str.rend()), 
			copy_str.size() / 2) == string::npos ? false : true;
}



//bool IsPolindrome(const string& passed_string)
//{
//	return passed_string.find(
//			string_view(passed_string.rbegin() 
//				+ int((double(passed_string.size()) / 2) + 0.5), 
//				passed_string.rend()), 
//			passed_string.size() / 2) == string::npos ? false : true;
//}


int main()
{
	string my_str;
	cout << "Enter string to check is this string a polindrome: ";
	getline(cin, my_str);
	cout << "Entered string is polindrome? " << (IsPolindrome(my_str) == true ? "Yes" : "No") << endl;

	return 0;
}
