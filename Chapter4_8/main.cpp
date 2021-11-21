#include <iostream>

const int company_name_len = 30;


struct Pizza
{
	enum{ LEN = company_name_len };
	char company_name[LEN];
	double diametr;
	double weight;
};


int main()
{
	using namespace std;
	// Using heap memory segment to create structure variable
	Pizza* pizza = new Pizza;
	cout << "Enter pizza diametr: ";
	cin >> pizza->diametr;
	cin.clear();
	while(cin && cin.get() != '\n') continue;
	cout << "Enter name of manufacturer company: ";
	cin.getline(pizza->company_name, Pizza::LEN); // operator -> equal to (*ptr). 
	if(cin.fail())
	{
		cout << "Entered name too long" << endl;
		cin.clear();
		while(cin.get() != '\n') continue;
	}
	cout << "Enter pizza weight: ";
	cin >> pizza->weight;
	cin.clear();
	while(cin && cin.get() != '\n') continue;

	cout << "Pizza manufacturer: " << pizza->company_name << endl;
	cout << "Pizza diametr: " << pizza->diametr << endl;
	cout << "Pizza weight: " << pizza->weight << endl;

	delete pizza;
	return 0;
}
