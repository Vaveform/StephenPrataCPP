#include <iostream>
#include "golffunc.h"
using namespace std;


// This programm can be improved by dynamic allocation memory
// and using OOP



int main()
{
	int golf_results[array_len];
	size_t read_elements = read_golf_results(golf_results, array_len);
	print_results(golf_results, 
			read_elements, 
			mean_of_results(golf_results, read_elements));

	return 0;
}
