#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPolindrome(const string& passed_string)
{
	// C++17 provide string_view class (reference type to string)
	// C++20 provide constructor, based on iterators
	// string_view class has reverse iterators
	return passed_string.find(
			string(passed_string.rbegin() 
				+ int((double(passed_string.size()) / 2) + 0.5), 
				passed_string.rend()), 
			passed_string.size() / 2) == string::npos ? false : true;
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
