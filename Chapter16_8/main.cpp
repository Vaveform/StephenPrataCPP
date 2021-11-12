#include <set>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	set<string> Mat_friends;
	set<string> Pat_friends;
	size_t friends_number;
	cout << "Enter Mat friends number: ";
	cin >> friends_number;
	cout << "Enter names of Mat friends:" << endl;
	copy_n(istream_iterator<string>(cin), 
			friends_number, 
			insert_iterator<set<string>>(Mat_friends, Mat_friends.begin()));

	cout << "Enter Pat friends number: ";
	cin >> friends_number;
	cout << "Enter names of Pat friends:" << endl;
	copy_n(istream_iterator<string>(cin), 
			friends_number, 
			insert_iterator<set<string>>(Pat_friends, Pat_friends.begin()));
	cout << "Union of Mat's and Pat's friends: " << endl;
	set_union(Mat_friends.begin(), Mat_friends.end(), 
			Pat_friends.begin(), Pat_friends.end(), 
			ostream_iterator<string, char>(cout, " "));
	cout << endl;

	return 0;
}
