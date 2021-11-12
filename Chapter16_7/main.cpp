#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <numeric>
using namespace std;

class RandomFunctor
{
	public:
		// diap - value of end (from)
		int operator()(const int& diap) const
		{
			return rand() % diap;
		}
};


vector<int> Lotto(int player_number, int selected_number)
{
	srand(time(0));
	vector<int> result;
	vector<int> values(player_number);
	iota(values.begin(), values.end(), 1);
	//random_device rd;
	//mt19937 g(rd());
	
	random_shuffle(values.begin(), values.end(), RandomFunctor());

	if(player_number <  selected_number)
		return values;
	copy(values.begin(), values.begin() + selected_number, back_inserter(result));
	return result;

}

int main()
{
	int pl_number;
	int select_players;
	cout << "Enter number players of lotto: ";
	cin >> pl_number;
	while(cin.get() != '\n')
		continue;
	cout << "Enter number of winners: ";
	cin >> select_players;
	while(cin.get() != '\n')
		continue;
	vector<int> test = Lotto(pl_number, select_players);
	copy(test.begin(), test.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;
	return 0;
}
