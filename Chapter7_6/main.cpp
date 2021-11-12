#include <iostream>
#include "array_func.h"
int main()
{
	using namespace std;
	cout << "Enter array size: " << endl;
	size_t array_size = 0;
	cin >> array_size;
	eat_line();
	double* arr = new double[array_size];
	size_t filled = Fill_array(arr, array_size);
	cout << "Entered array: ";
	Show_array(arr, filled);
	Reverse_array(arr, filled);
	cout << "Reverse entered array: ";
	Show_array(arr, filled);
	delete[] arr;
	return 0;
}
