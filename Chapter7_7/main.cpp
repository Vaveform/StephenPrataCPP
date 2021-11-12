#include <iostream>
const int Max = 5;

double* fill_array(double* begin,  double* end);
void show_array(const double* begin,const double* end);
void revalue(double* begin, double* end, double r);

int main()
{
	using namespace std;
	double properties[Max];
	double* end_ptr = fill_array(properties, properties + Max);
	show_array(properties, end_ptr);
	if(end_ptr - properties > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while(!(cin >> factor))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(properties, end_ptr, factor);
		show_array(properties, end_ptr);
	}
	cout << "Done.\n";
	//cin.get();
	//cin.get();
	return 0;
}

double* fill_array(double* begin, double* end)
{
	using namespace std;
	double temp;
	double* _b = nullptr;
	for(_b = begin; _b < end; _b++)
	{
		cout << "Enter value #" << ((_b - begin) + 1) << ": ";
		cin >> temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n') continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if(temp < 0)
			break;
		*_b = temp;
	}
	return _b;
}

void show_array(const double *begin, const double* end)
{
	using namespace std;
	const double* _b = nullptr;
	for(_b = begin; _b < end; ++_b)
	{
		cout << "Property #" << ((_b - begin) + 1) << ": $";
		cout << *_b << endl;
	}
}

void revalue(double* begin, double* end, double r)
{
	double* _b = nullptr;
	for(_b = begin; _b < end; ++_b)
		*_b *= r;
}
