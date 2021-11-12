#include <iostream>
#include "cpmv.h"

using namespace std;

Cpmv CreateCpmv()
{
	return Cpmv("Default", "Code");
}



int main()
{
	cout << "Cpmv first;" << endl;
	Cpmv first;
	first.Display();
	cout << "Cpmv second(\"Hello\", \"World\");" << endl;
	Cpmv second("Hello", "World");
	second.Display();
	cout << "Cpmv third = CreateCpmv();" << endl;
	Cpmv third = CreateCpmv();
	third.Display();
	cout << "Cpmv fourth = second + third;" << endl;
	Cpmv fourth = second + third; 
	fourth.Display();
	cout << "fourth = third + second;" << endl;
	fourth = third + second;
	fourth.Display();
	cout << "Cpmv fifth(second);" << endl;
	Cpmv fifth(second);
	fifth.Display();
	cout << "fifth = third;" << endl;
	fifth = third;
	fifth.Display();
	cout << "Cpmv sixth(move(fourth));" << endl;
	Cpmv sixth(move(fourth));
	sixth.Display();
	fourth.Display();
	cout << "sixth = move(third);" << endl;
	sixth = move(third);
	sixth.Display();
	third.Display();
	cout << "Cpmv seventh(CreateCpmv());" << endl;
	Cpmv seventh(CreateCpmv());
	seventh.Display();


	return 0;
}
