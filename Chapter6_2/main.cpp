#include <iostream>

using namespace std;

const int LEN = 10;


int main()
{
	double donations[LEN];
	int i = 0;
	double sum = 0.0;
	cout << "Enter donations (max: " << LEN << " donations)\n";
	cout << "To end entering enter some symbol or word\n";
	cout << "Enter donation #" << i + 1 << ": ";
	while(cin >> donations[i]){
		sum += donations[i++];
		while(cin.get() != '\n') continue;
		if(i < LEN) cout << "Enter donation #" << i + 1 << ": ";
		else{ break; }
	}

	if(i <= 0){
		cout << "No donations." << endl;
		return 0;
	}


	int count = 0;
	for(int j = 0; j < i; ++j)
	{
		if(donations[j] > sum / i) count++;
	}
	cout << "Avarage size of donation: " << sum / i << endl;
	cout << "Number of donations which bigger then avarage: " << count << endl;
	return 0;
}
