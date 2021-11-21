#include <iostream>

using namespace std;

const int buffer_size = 40;


int main()
{

	char fname[buffer_size];
	char lname[buffer_size];
	char grade;
	unsigned short age; 
	cout << "What is your first name? ";
	cin.getline(fname, buffer_size);
	if(cin.fail())
	{
		cout << "Too long first name" << endl;
		cin.clear();
		while(cin.get() != '\n') continue;
	}
	cout << "What is your last name? ";
	cin.getline(lname, buffer_size);
	if(cin.fail())
	{
		cout << "Too long last name" << endl;
		cin.clear();
		while(cin.get() != '\n') continue;
	}
	cout << "What letter grade do you deserve? ";
	grade = cin.get();
	while(cin.get() != '\n') continue;
	cout << "What is your age? ";
	cin >> age;
	while(cin.get() != '\n') continue;
	cout << "Name: " 
		<< lname << ", " << fname 
		<< "\nGrade: " << (++grade) 
		<< "\nAge: " << age << endl;
	return 0;
}
