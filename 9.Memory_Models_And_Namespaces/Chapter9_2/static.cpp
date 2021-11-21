// static.cpp -- использование статической локальной переменной
#include <iostream>
#include <string>

// Прототип функции
void strcount(const char *str);
int main()
{
	using namespace std;
	string input;
	cout << "Enter а line:\n";
	getline(cin, input);
	while(input != "")
	{
		strcount(input.c_str());
		cout << " Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}
void strcount(const char *str)
{
	using namespace std;
	// статиче ская локальная переменная
	static int total = 0;
	// автоматиче ская локальная переменная
	int count = 0;
	cout << "\"" << str << "\" contains " ;
	// переход к концу строки
	while(*str++)
		count++;
	total+= count;
	cout << count << " characters\n" ;
	cout << total << " characters total\n";
}
