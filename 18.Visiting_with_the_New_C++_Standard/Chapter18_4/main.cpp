#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	
	auto outint = [](const int& n) {std::cout << n << " "; };

	
	TooBig<int> f100(100);
	int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	// In C++11 we can use initializer_list:
	// list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	// list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](const int& val){ return val > 100; });

	etcetera.remove_if([](const int& val){ return val > 200; });

	cout << "Trimmed lists:\n";

	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}
