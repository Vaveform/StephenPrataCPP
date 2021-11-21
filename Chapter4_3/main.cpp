#include <iostream>
#include <cstring>

const int buffer_size = 20;

int main()
{
	using namespace std;
	char name_buffer[buffer_size];
	//char lname[buffer_size];
	char concatenated[2 * buffer_size + 2];

	cout << "Enter your first name: ";
	// reads buffer_size - 1 symbols and append \0
	cin.getline(name_buffer, buffer_size);

	if(cin.fail())
	{
		cout << "First name too long" << endl;
		cin.clear();
		while(cin.get() != '\n') continue;
	}

	cout << "Enter your last name: ";
	cin.getline(concatenated, buffer_size);

	if(cin.fail())
	{
		cout << "Last name too long" << endl;
		cin.clear();
		while(cin.get() != '\n') continue;
	}

	strcat(concatenated, ", ");
	strcat(concatenated, name_buffer);

	cout << "Here's the information in a single string: " << concatenated << endl;


	return 0;
}
