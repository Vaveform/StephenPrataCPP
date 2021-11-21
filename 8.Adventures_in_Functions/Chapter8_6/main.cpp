#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



template<typename T>
T maxn(T arr[], int size) //->decltype(arr[0])
{
	size_t res = 0;
	for(size_t i = 1; i < size; ++i)
	{
		if(arr[res] < arr[i])
			res = i;
	}
	return arr[res];
}

template<> const char* maxn<const char*>(const char* arr[], int size) //-> const char*
{
	//cout << "Calling with const char* arr[]" << endl;
	size_t i = 0;
	size_t current_max_size = strlen(arr[i]);
	for(size_t j = 1; j < size; ++j)
	{
		size_t tmp_size = strlen(arr[j]);
		if(current_max_size < tmp_size)
		{
			i = j;
			current_max_size = tmp_size;
		}
	}
	//cout << "Index of longest string: " << i << endl;
	return arr[i];
}


template<> char* maxn(char* arr[], int size)
{
	//cout << "Calling with char* arr[]" << endl;
	return const_cast<char*>(maxn(const_cast<const char**>(arr), size));
}


template<class T>
void printArr(T arr[], int size, char delim = ' ')
{
	for(int i = 0; i < size; ++i)
		cout << arr[i] << delim;
	//cout << arr[size - 1];
}




int main()
{
	const char* const_strs[6] = {"asdasd", "velcome adr", "asdsd", "sdfsdff", "velcome adr", "asdc"};
	const char* ptr_to_longest = maxn(const_strs, 6);
	cout << "Array of addresses to char(array of strings): ";
	printArr(const_strs, 6, '|');
	cout << "Longest string: " << ptr_to_longest << endl;
	double darr[4] = {5.3, 1.768, 3.43, 0.678};
	cout << "Array of doubles: ";
	printArr(darr, 4);
	cout << " Biggest value: " << maxn(darr, 4) << endl;
	int iarr[6] = {0, 6, 13, 3, 11, 87};
	cout << "Array of integers: ";
	printArr(iarr, 6);
	cout << "Biggest value: " << maxn(iarr, 6) << endl;


	char* no_const_strs[3];
	const char* temp_first = "AI calls the world";
	const char* temp_second = "Method called by caller";
	const char* temp_third = "Young";

	no_const_strs[0] = new char[strlen(temp_first) + 1];
	strcpy(no_const_strs[0], temp_first);


	no_const_strs[1] = new char[strlen(temp_second) + 1];
	strcpy(no_const_strs[1], temp_second);

	no_const_strs[2] = new char[strlen(temp_third) + 1];
	strcpy(no_const_strs[2], temp_third);

	cout << "Array of no const strs: ";
	printArr(no_const_strs, 3, '|');
	cout << "Longest string: " << maxn(no_const_strs, 3) << endl;

	for(int i = 0; i < 3; ++i)
		delete[] no_const_strs[i];
	return 0;
}
