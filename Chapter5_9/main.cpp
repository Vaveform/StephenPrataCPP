#include <iostream>
#include <string>
using namespace std;


int main()
{
	string word;
	// cin working with char arr
	int counter = 0;
	cout << "Enter words (for end enter word: done) :" << endl;
	while((cin >> word) && word != "done") counter++;
	cout << "You entered " << counter << " words." << endl;
	return 0;

}
