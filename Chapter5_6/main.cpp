#include <iostream>
#include <ios>
#include <iomanip>
#include "months.h"

using namespace std;

const int YEARS = 3;


int main()
{
	int sales[YEARS][MONTHS_NUM] = {{0}}; // All zeros

	for(int i = 0; i < YEARS; ++i)
	{
		cout << "For year " << i + 1 << " enter sales: "<< endl;
		int j = 0;
		do{
			cout << "Enter number sales for " << months[j] << ": ";
			cin >> sales[i][j++];
		}while(cin && sales[i][j - 1] > 0 && j < MONTHS_NUM);
		if(!cin) cin.clear();
	}


	// Printing table
	cout << setw(10)  << " ";
	for(int i = 0; i < MONTHS_NUM; ++i)
		cout << setw(10) << left << months[i];
	cout << "\n";
	long sum_by_year = 0;
	long all_sum = 0;
	for(int i = 0; i < YEARS; ++i){
		cout << "Year #";
		cout << setw(4) << left << i + 1;
		for(int j = 0; j < MONTHS_NUM; ++j)
		{
			cout << setw(10) << left << sales[i][j];
			sum_by_year += sales[i][j];
		}
		cout << "Sum: " << sum_by_year << "\n";
		all_sum += sum_by_year;
		sum_by_year = 0;
	}
	cout << "All sum(by 3 years): " << all_sum << endl;
	return 0;
}
