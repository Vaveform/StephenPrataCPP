#include <iostream>
#include <string>
#include <cctype>
#include <functional>
#include <algorithm>
#include <iterator>
#include <ios>
using namespace std;

void count_words(const string& str, size_t& b_f_vowels, size_t& b_f_consonants, size_t& others, istream& input)
{
	if(str == "q") {
		input.clear(ios_base::eofbit);
		return;
	}
	char ch = str[0];
	if(isalpha(ch)){
		if(
				(ch >= 66 && ch <= 68) || 
				(ch >= 98 && ch <= 100) || 
				(ch >= 70 && ch <= 72) ||
				(ch >= 102 && ch <= 104) ||
				(ch >= 74 && ch <= 78) ||
				(ch >= 106 && ch <= 110) ||
				(ch >= 80 && ch <= 84) ||
				(ch >= 112 && ch <= 116) ||
				(ch >= 86 && ch <= 88) ||
				(ch >= 118 && ch <= 120) ||
				ch == 90 || ch == 122
				) ++b_f_consonants;
		else
			++b_f_vowels;
	}
	else
		++others;
}



int main()
{
	string read_word;
	size_t others = 0;
	// vowels: A, E, I, O, U, Y 
	size_t beginning_from_vowels = 0;
	// consonants: B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Z
	size_t beginning_from_consonants = 0;
	cout << "Enter words (q to quit): " << endl;
	//while(cin >> read_word && read_word != "q")
	//{
	//	char ch = read_word[0];
	//	if(isalpha(ch)){
	//		if(
	//				(ch >= 66 && ch <= 68) || 
	//				(ch >= 98 && ch <= 100) || 
	//				(ch >= 70 && ch <= 72) ||
	//				(ch >= 102 && ch <= 104) ||
	//				(ch >= 74 && ch <= 78) ||
	//				(ch >= 106 && ch <= 110) ||
	//				(ch >= 80 && ch <= 84) ||
	//				(ch >= 112 && ch <= 116) ||
	//				(ch >= 86 && ch <= 88) ||
	//				(ch >= 118 && ch <= 120) ||
	//				ch == 90 || ch == 122
	//				) beginning_from_consonants++;
	//		else
	//			beginning_from_vowels++;
	//	}
	//	else
	//		++others;
	//}


	// STL style without cycles
	// I write function, but we can write lambda and capture context
	auto counter_functor = bind(count_words, placeholders::_1, ref(beginning_from_vowels), ref(beginning_from_consonants), ref(others), ref(cin));
	for_each(istream_iterator<string>(cin), istream_iterator<string>(), counter_functor);
	cin.clear();
	while(cin && cin.get() != '\n') continue; // cleaning input

	cout << beginning_from_vowels << " words beginning with vowels" << endl;
	cout << beginning_from_consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;
	return 0;
}
