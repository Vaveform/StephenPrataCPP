#include <iostream>

using namespace std;

#include <cstring>

struct stringy{
	char * str;
	int ct;
};


void set(stringy& dest, const stringy& source);

void set(stringy& dest, const char* source);

void show(const stringy& s, int n = 1);

void show(const char* s, int n = 1);


int main()
{
	stringy beany;
	char testing[] = "Reality isn't what is used to be.";
	set(beany, testing);

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	delete[] beany.str;

	return 0;
}



void set(stringy& dest, const char* source)
{
	size_t source_l = strlen(source); // strlen count symbols before \0 - \0 not count
	dest.str = new char[source_l + 1];
	strcpy(dest.str, source);
	//dest.str[source_l] = '\0'; // strcpy copy null terminator
}

void show(const stringy& s, int n)
{
	show(s.str, n);
}

void show(const char* s, int n)
{
	while(n != 0) 
	{
		cout << s << endl;
		n--;
	}
}
