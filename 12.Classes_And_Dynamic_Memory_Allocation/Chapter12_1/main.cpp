#include "cow.h"


int main(){
	Cow first; // Default constructor
	Cow second("Klian", "Sleeping and swamming", 43.0);
	Cow third(first); // copy constructor
	Cow forth = second; // copy constructor and assignment operator
	first.ShowCow();
	second.ShowCow();
	third.ShowCow();
	forth.ShowCow();
	third = second;
	second.ShowCow();
	third.ShowCow();
	first = second;
	first.ShowCow();
	// Dynmaic allocated object
	Cow* fifth = new Cow("Alex Morgan", "Playing and sorting", 32.19);
	fifth->ShowCow();
	first = *fifth;
	first.ShowCow();
	delete fifth;
	return 0;
}
