#include <iostream>

long double probability(unsigned numbers, unsigned picks);

long double probability_mega_number(unsigned numbers);

int main()
{
	using namespace std;
	double total, choices;


	cout << "You have probability to win in lotto, where\n";
	cout << "you should select five numbers from 1-47 range\n";
	cout << "and one number from 1-27 range: ";
	cout << probability(47, 5) * probability_mega_number(27);
	cout << " of winning.\n";
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for(n = numbers, p = picks; p > 0; n--, p--)
		result = result * p / n;
	return result;
}
long double probability_mega_number(unsigned numbers)
{
	long double p_mega_number = 1.0 / numbers;
	return p_mega_number;
}
