#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	double dafna_investment = 100;
	double dafna_balance = dafna_investment;
	double kleo_investment = 100;
	double kleo_balance = kleo_investment;

	while(kleo_balance <= dafna_balance)
	{
		dafna_balance +=  0.1 * dafna_investment;
		kleo_balance += 0.05 * kleo_balance;
		cout << "On the end of year #" << (++year) << ": " << endl;
		cout << "Dafna has balance: " << dafna_balance << endl;
		cout << "Kleo has balance: " << kleo_balance << endl;
	}

	return 0;
}
