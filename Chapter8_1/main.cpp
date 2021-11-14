#include <iostream>

using namespace std;

// Show passed string (const char*)
// if second parametr not use or passed 0 (default value)
// string show one time, else shows t time, where
// t - number of previous calls
void ShowStr(const char* str, int n = 0);


int main()
{
	const char* str = "Welcome\n";
	// Calls function with two params with second param equal
	// to 15 - before was 0 calls, so function will not print anything
	cout << "ShowStr(\"Welcome\\n\", 15):" << endl;
	ShowStr(str, 15);
	// Calls function with one parametr (second parametr equal
	// to 0). Shows str one time
	cout << "ShowStr(\"Welcome\\n\")" << endl;
	ShowStr(str);
	// Calls function with two parametrs, by passing explicitly
	// second parametr equal to 0 - show str one time
	cout << "ShowStr(\"Welcome\\n\", 0):" << endl;
	ShowStr(str, 0);
	// Calls function with two parametrs (n = 5)
	// Before this call was two calls, so function should 
	// print str two times;
	cout << "ShowStr(\"Welcome\\n\", 5):" << endl;
	ShowStr(str, 5);
	// Calls function with one parametr - shows str one time
	cout << "ShowStr(\"Welcome\\n\"):" << endl;
	ShowStr(str);
	// Calls function with two parametrs - second parametr n = 10
	// Before was 4 calls of ShowStr - four times printed str
	cout << "ShowStr(\"Welcome\\n\", 10):" << endl;
	ShowStr(str, 10);
	return 0;
}


void ShowStr(const char* str, int n)
{
	static int calls_number = 0;
	if(n == 0)
	{
		cout << str;
	}
	else
	{
		for(int i = 0; i < calls_number; ++i)
		{
			cout << str;
		}
	}
	calls_number++;
}
