#include <iostream>

using namespace std;


struct CandyBar
{
	enum{LEN = 30};
	char title[LEN];
	double weight;
	int calories;
};


void setCandyBar(CandyBar& cb, const char* t, double w, int c)
{
	// Copying to title second argument
	int i = 0;
	for(; i < CandyBar::LEN - 1 && t[i]; ++i)
		cb.title[i] = t[i];
	cb.title[i] = '\0';
	cb.weight = w;
	cb.calories = c;
}

void showCandyBar(const CandyBar& cb)
{
	cout << "CandyBar with title " << cb.title;
	cout << " has weight: " << cb.weight;
	cout << " and calories: " << cb.calories << endl;
}

void eat_line()
{
	while(cin && cin.get() != '\n') continue;
}



int main()
{
	cout << "Enter size of box with candybars: ";
	size_t s = 0;
	cin >> s;
	eat_line();

	CandyBar* box = new CandyBar[s];

	char title_buffer[CandyBar::LEN];
	double weight_buffer;
	int calories_buffer;
	size_t entered = 0;
	for(; entered < s; entered++)
	{
		cout << "Enter title of #" << entered + 1 << " candybar: ";
		cin.get(title_buffer, CandyBar::LEN);
		eat_line();
		if(!cin) break;
		cout << "Enter weight of #" << entered + 1 << " candybar: ";
		cin >> weight_buffer;
		eat_line();
		if(!cin) break;
		cout << "Enter calories of #" << entered + 1 << " candybar: ";
		cin >> calories_buffer;
		eat_line();
		if(!cin) break;
		setCandyBar(box[entered], title_buffer, weight_buffer, calories_buffer);
	}


	cout << "Content of candybar box: " << endl;

	for(size_t i = 0; i < entered; i++) showCandyBar(box[i]);

	delete [] box;
	return 0;
}
