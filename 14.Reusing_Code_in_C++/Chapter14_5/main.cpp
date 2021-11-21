#include <iostream>
using namespace std;
#include "employee.h"
int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll(cout);
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll(cout);
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll(cout);
	highfink hf(ma, "Curly Kew");
	hf.ShowAll(cout);
	cout << "Press a key for next phase:\n";

	cin.get();
	highfink hf2;
	hf2.SetAll(cin);
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for(int i = 0; i < 4; ++i)
	{
		tri[i]->ShowAll(cout);
	}
	// abstr_emp - abstract class, because he has pure virtual func
	//abstr_emp tri2[4] = {em, fi, hf, hf2};
	//for(int i = 0; i < 4; ++i)
	//{
	//	tri2[i].ShowAll(cout);
	//}
	//
	// Testing cin and cout polimorphism
	abstr_emp * tri2[4] = {&em, &fi, &hf, &hf2};
	for(int i = 0; i < 4; ++i)
	{
		cin >> *tri2[i];
	}
	for(int i = 0; i < 4; ++i)
	{
		cout << *tri2[i];
	}
	return 0;
}
