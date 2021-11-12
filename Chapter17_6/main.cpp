#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ios>
using namespace std;
#include "employee.h"


ostream& operator<<(ostream& os, const shared_ptr<abstr_emp>& obj)
{
	os << *obj;
	return os;
}

istream& operator>>(istream& is, shared_ptr<abstr_emp>& obj)
{
	if(is.peek() == EOF)
	{
		is.get();
		//cout << "EOF detected" << endl;
		return is;
	}
	//cout << "Reading from file" << endl;
	string employee_type;
	is >> employee_type;
	if(!is || employee_type != "Category:")
	{
		is.setstate(ios::badbit);
		cerr << "Bad opened file" << endl;
		return is;
	}
	is >> employee_type;
	while(is.get() != '\n') { continue; }
	obj = CreateEmployee(employee_type[0]);
	is >> *obj;
	return is;
}

void ShowingFileOption(const string& file_name)
{
	ifstream for_reading(file_name.c_str(), ios_base::in);
	if(!for_reading.is_open())
	{
		cerr << "Cannot to open file employee.dat for reading" << endl;
		exit(EXIT_FAILURE);
	}
	
	// For writing we should unset with hint input (for ifstream)
	abstr_emp::ChangeHintStatus(false);
	vector<shared_ptr<abstr_emp>> readed_objects;
	copy(istream_iterator<shared_ptr<abstr_emp>>(for_reading),
			istream_iterator<shared_ptr<abstr_emp>>(), 
			back_inserter(readed_objects));

	cout << "Readed number of objects: " << readed_objects.size() << endl;
	// For user we show hint (for cout)
	cout << "Current list of employers:" << endl;
	abstr_emp::ChangeHintStatus(true);
	copy(readed_objects.begin(), readed_objects.end(), 
			ostream_iterator<shared_ptr<abstr_emp>, char>(cout, "\0"));
	for_reading.clear();
	for_reading.close();
}

void AddingToFileOption(const string& file_name)
{
	ofstream for_writing(file_name.c_str(), ios_base::out | ios_base::app);
	if(!for_writing.is_open())
	{
		cerr << "Cannot to open file employee.dat for writing" << endl;
		exit(EXIT_FAILURE);
	}
	string employee_type;
	int number_of_objects = 0;
	cout << "Enter number of object for insertion: ";
	cin >> number_of_objects;
	if(!cin) 
	{
		cout << "Wrong input in entering number of insertion." << endl; 
		cin.clear();
		return;
	}
	while(cin && cin.get() != '\n') { 
		continue; 
	}
	for(int i = 0; i < number_of_objects; ++i){
		cout << "Available employers:\n\t"
			<< "e - employee\n\t"
			<< "m - manager\n\t"
			<< "f - fink\n\t"
			<< "h - highfink" << endl;
		cout << "Enter type of employer for " << i + 1 << " object number: ";
		getline(cin, employee_type);
		try{
			shared_ptr<abstr_emp> inserted_object(CreateEmployee(employee_type[0])); 
			abstr_emp::ChangeHintStatus(true);
			inserted_object->SetAll(cin);
			abstr_emp::ChangeHintStatus(false);
			for_writing << inserted_object;
		}
		catch(exception& ex)
		{
			exit(EXIT_FAILURE);
		}
	}
	for_writing.clear();
	for_writing.close();

}


int main(int argc, char* argv[])
{	
	string file_name;
	if(argc < 2)
	{
		cout << "File not passed. Will be using employee.dat" << endl;
		file_name = string("employee.dat");
	}
	else
	{
		file_name = string(argv[1]);
	}
	cout << "Welcome to employer saver programm." << endl;
	char mode;
	while(true)
	{
		cout << "Enter mode\n\tShow file - s\n\tInsert to file - i\n\tQuit - q\n";
		cin >> mode;
		while(cin.get() != '\n')
			continue;
		switch(mode){
			case 'i':
				AddingToFileOption(file_name);
				break;
			case 's':
				ShowingFileOption(file_name);
				break;
			case 'q':
				exit(EXIT_SUCCESS);
			default:
				continue;
		}
	}
	
	return 0;
}
