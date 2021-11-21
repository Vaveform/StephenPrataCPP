#include <iostream>
#include <iterator>
#include <fstream>
#include <set>
#include <algorithm>
#include <ios>
#include <string>

int main()
{
	using namespace std;
	ifstream mat_friends_input("mat.dat", ios_base::in);
	if(!mat_friends_input.is_open())
	{
		cerr << "Cannot to open mat.dat file" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream pat_friends_input("pat.dat", ios_base::in);
	if(!pat_friends_input.is_open())
	{
		cerr << "Cannot to open pat.dat file" << endl;
		exit(EXIT_FAILURE);
	}
	set<string> mat_friends;
	set<string> pat_friends;
	copy(istream_iterator<string>(mat_friends_input), 
			istream_iterator<string>(), 
			insert_iterator<set<string>>(mat_friends, mat_friends.begin()));
	cout << "Mat friends sorted by names:\n";
	copy(mat_friends.begin(), mat_friends.end(), ostream_iterator<string, char>(cout, "\n"));
	copy(istream_iterator<string>(pat_friends_input), 
			istream_iterator<string>(), 
			insert_iterator<set<string>>(pat_friends, pat_friends.begin()));
	cout << "Pat friends sorted by names:\n";
	copy(pat_friends.begin(), pat_friends.end(), ostream_iterator<string, char>(cout, "\n"));

	ofstream output("matnpat.dat", ios_base::out | ios_base::trunc);
	if(!output.is_open())
	{
		cerr << "Cannot to open/create matnpat.dat" << endl;
		exit(EXIT_FAILURE);
	}

	set_union(mat_friends.begin(), mat_friends.end(),
			pat_friends.begin(), pat_friends.end(),
			ostream_iterator<string, char>(output, "\n"));
	return 0;

}
