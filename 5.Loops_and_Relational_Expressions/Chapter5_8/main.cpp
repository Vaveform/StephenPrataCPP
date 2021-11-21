#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	const int buf_size = 30;
	char word[buf_size];
	// cin working with char arr
	int counter = 0;
	cout << "Enter words (for end enter word: done) :" << endl;
	while((cin >> word) && strcmp(word, "done")) counter++;
	cout << "You entered " << counter << " words." << endl;
	return 0;

}
