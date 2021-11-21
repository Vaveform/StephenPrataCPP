#include <iostream>
#include "months.h"
using namespace std;



int main()
{
	int sales[LEN] = {0}; // All zeros
	long sum_of_sales = 0;
	int i = 0;
	do{
		cout << "Enter number sales for " << months[i] << ": ";
		cin >> sales[i++];
	}while(cin && sales[i - 1] > 0 && i < LEN);

	for(int j = 0; j < i; ++j)
		sum_of_sales += sales[j];
	cout << "Sum of sales: " << sum_of_sales << endl;
	return 0;
}
