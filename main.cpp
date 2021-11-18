#include <iostream>
#include <string>

using namespace std;


struct Sponsor
{
	string name;
	double donate;
};

int main()
{
	int s = 0;

	cout << "Enter number of sponsors: ";
	cin >> s;
	while(cin && cin.get() != '\n') continue;
	if(s < 0 || !s){
		cerr << "Entered size of sponsors invalid" << endl;
		exit(EXIT_FAILURE);
	}

	Sponsor * sponsors = new Sponsor[s];


	// Reading from cin stream 
	int read_elements;
	for(read_elements = 0; cin && read_elements < s; ++read_elements)
	{
		cout << "Enter name of sponsor #" << read_elements + 1 << ": ";
		getline(cin, sponsors[read_elements].name);
		if(sponsors[read_elements].name[0] == '\n') break;
		if(cin){
			cout << "Enter donate from sponsor #" << read_elements + 1 << ": ";
			cin >> sponsors[read_elements].donate;
			while(cin && cin.get() != '\n') continue;
			if(sponsors[read_elements].donate <= 0) break;
		}
	}
	
	if(read_elements == 0 || read_elements < 0)
	{
		cerr << "No sponsors" << endl;
		exit(EXIT_FAILURE);
	}


	// Array of pointers to sorted
	Sponsor** sp_ptrs = new Sponsor*[read_elements];

	// >= 10 000 $ donation - Grand Patrons, < 100000 Patrons
	int left = 0, right = read_elements - 1;
	for(int i = 0; i < read_elements; ++i)
	{
		if(sponsors[i].donate > 10000)
			sp_ptrs[left++] = &sponsors[i];
		else
			sp_ptrs[right--] = &sponsors[i];
	}


	// left - pointer to end of grand sponsors
	cout << "Grand Patrons: " << endl;
	for(int i = 0; i < left; ++i)
	{
		cout << sp_ptrs[i]->name << " with donate $" << sp_ptrs[i]->donate << endl;
	}
	if(left == 0) cout << "none." << endl;
	cout << "Patrons: " << endl;
	for(int i = left; i < read_elements; ++i)
	{
		cout << sp_ptrs[i]->name << " with donate $" << sp_ptrs[i]->donate << endl;
	}
	if(left == read_elements) cout << "none" << endl;


	delete[] sp_ptrs;
	delete[] sponsors;

	return 0;
}
