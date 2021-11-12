#include <iostream>

using namespace std;


unsigned long long factorial(int n)
{
	if(n == 1)
		return n;
	return n * factorial(n - 1);
}


int main()
{
	cout << "Enter n, to calculate n!: ";
	int n;
	while(cin >> n)
	{
		while(cin.get() != '\n') continue;
		cout << n << "! = " << factorial(n) << endl;
		cout << "Enter n, to calculate n!: ";
	}
	return 0;
}
