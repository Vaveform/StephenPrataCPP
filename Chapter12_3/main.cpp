#include <iostream>
#include "stock.h"
const int STKS = 4;

int main()
{
	using namespace std;
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	std::cout << "Stock holdings:\n";
	int st;
	for(st = 0; st < STKS; st++)
		cout << stocks[st] << endl;
	const Stock * top = &stocks[0];
	for(st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	std::cout << "\nMost valuable holding:\n";
	cout << *top << endl;
	return 0;
}
