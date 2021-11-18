#include <iostream>

using namespace std;

const int LEN = 4;
const long tax_stages[LEN] = {5000, 10000, 20000, 35000};
const double tax_coeff[LEN] = {0.0, 0.1, 0.15, 0.2};

int main()
{
	long income = 0.0;
	long tmp_income = 0;
	double tax = 0.0;
	cout << "Enter your income (in twarps): ";
	while(cin >> income && income >= 0)
	{
		if(income - tax_stages[LEN - 1] > 0) tax += tax_coeff[LEN - 1] * (income - (tax_stages[LEN - 1]));
		tmp_income = income;
		for(int i = 0; i < LEN - 1 && tmp_income > 0; tmp_income -= tax_stages[i++])
		{
			if(tmp_income / tax_stages[i] == 0)
			{
				tax += tax_coeff[i] * (tmp_income % tax_stages[i]);
			}
			else
			{
				tax += tax_coeff[i] * tax_stages[i];
			}
		}
		cout << "You should pay tax: " << tax << endl;
		tax = 0.0;
		cout << "Enter your income (in twarps): ";
	}
	cout << "Bye!" << endl;
	return 0;
}
