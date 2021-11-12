#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct SeasonsExpenses
{
	enum {expenses_s = Seasons};
	double expenses[expenses_s];
};


void fill(SeasonsExpenses* pa);


// No copy, passing by const pointer
void show(const SeasonsExpenses* da);


// Copy version - struct with automatic array copy
void show(SeasonsExpenses da);


//void fill(double pa[], int size);

//void show(const double da[], int size);




int main()
{	SeasonsExpenses exp;
	fill(&exp);
	show(&exp);
	//double expenses[Seasons];
	//fill(expenses, Seasons);
	//show(expenses, Seasons);
	return 0;
}

void fill(SeasonsExpenses* pa)
{
	using namespace std;
	for(int i = 0; i < SeasonsExpenses::expenses_s; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->expenses[i];
	}

}


void show(const SeasonsExpenses* da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i = 0; i < SeasonsExpenses::expenses_s; ++i)
	{
		cout << Snames[i] << ": $" << da->expenses[i] << endl;
		total += da->expenses[i];
	}
	cout << "Total Expenses: $" << total << endl;
}


void show(SeasonsExpenses da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i = 0; i < SeasonsExpenses::expenses_s; ++i)
	{
		cout << Snames[i] << ": $" << da.expenses[i] << endl;
		total += da.expenses[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

//void fill(double pa[], int size)
//{
//	using namespace std;
//	for(int i = 0; i < size; i++)
//	{
//		cout << "Enter " << Snames[i] << " expenses: ";
//		cin >> pa[i];
//	}
//}

//void show(const double da[], int size)
//{
//	using namespace std;
//	double total = 0.0;
//	cout << "\nEXPENSES\n";
//	for(int i = 0; i < size; ++i)
//	{
//		cout << Snames[i] << ": $" << da[i] << endl;
//		total += da[i];
//	}
//	cout << "Total Expenses: $" << total << endl;
//}
