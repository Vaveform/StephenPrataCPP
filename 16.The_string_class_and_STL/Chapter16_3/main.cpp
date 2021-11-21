#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cctype>

std::vector<std::string> ReadWordsFromInput(std::istream& is)
{
	// vector<string> no copy - NRVO optimization
	using std::string;
	using std::vector;
	using std::istream_iterator;
	using std::back_inserter;
	vector<string> result;
	// back_inserter(vec_data) or back_inserter_iterator<vector<string>>(vec_data)
	// back_inserter - convinient function returning back_inserter_iterator
	copy(istream_iterator<string>(is), 
			istream_iterator<string>(), 
			back_inserter(result));
	//cout << "Readed number of strings: " << result.size() << endl;
        //copy(result.begin(), result.end(), ostream_iterator<string, char>(cout, "\n"));

	// Old way reading and cout data of vector
	//while(file >> temporary)
	//{
	//	vec_data.push_back(temporary);
	//}
	//cout << "Readed number of strings: " << vec_data.size() << endl;
	//for(const string& element : vec_data)
	//	cout << element << endl;	
	return result;
}


int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	using std::string;
	string file_name;
	cout << "Enter file name for reading words(or quit): ";
	getline(cin, file_name);
	if(file_name == "quit")
		return 0;
	std::ifstream file;
	file.open(file_name.c_str(), std::ios::in);
	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	std::vector<string> wordList(ReadWordsFromInput(file));
	int NUM = wordList.size();
	std::srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n>";
	cin >> play;
	play = tolower(play);
	while(play == 'y')
	{
		string target = wordList[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters. and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while(guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if(badchars.find(letter) != string::npos
					|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if(loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc]=letter;

				loc = target.find(letter, loc + 1);
				while(loc != string::npos)
				{
					attempt[loc]=letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if(attempt != target)
			{
				if(badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if(guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye\n";
	return 0;
}
