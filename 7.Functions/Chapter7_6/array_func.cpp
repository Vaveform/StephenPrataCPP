#include "array_func.h"



bool eat_line()
{
	while(std::cin && std::cin.get() != '\n') continue;
	return true;
}

size_t Fill_array(double arr[], size_t size)
{
	if(size <= 0) return size;
	using namespace std;
	size_t read_values = 0;
	cout << "Enter value for " << read_values + 1 << " element of array: ";
	while(cin >> arr[read_values++] && eat_line() && read_values < size){
		cout << "Enter value for " << read_values << " element of array: ";
	}
	return read_values;
}

void Show_array(double arr[], size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void Reverse_array(double arr[], size_t size)
{
	if(size <= 1) return;
	double* begin = arr;
	double* end = arr + size - 1;
	double tmp;
	while(begin < end)
	{
		tmp = *begin;
		*(begin++) = *end;
		*(end--) = tmp;
	}
}
