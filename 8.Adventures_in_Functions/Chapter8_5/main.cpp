#include <iostream>


using namespace std;


const int LEN = 5;


template<class T>
auto max5(T arr[]) -> decltype(arr[0]);

template<class T>
void printArr(T arr[]);


int main()
{
	double darr[LEN] = {1.5, -2.156, 5.678, 3.4, -18.9};
	int iarr[LEN] = {4, -10, 19, 4, 3};
	double* pdarr[LEN] = {&darr[0], &darr[1], &darr[2], &darr[3], &darr[4]};

	cout << "Array of doubles: ";
	printArr(darr);
	cout << " max value: " << max5(darr) << endl;


	cout << "Array of integers: ";
	printArr(iarr);
	cout << " max value: " << max5(iarr) << endl;

	cout << "Array of pointers to doubles: ";
	printArr(pdarr);
	cout << " max value: " << max5(pdarr) << endl;
	return 0;
}

template<class T>
auto max5(T arr[]) -> decltype(arr[0])
{
	int max = 0;
	for(int i = 1; i < LEN; ++i)
	{
		if(arr[max] < arr[i])
			max = i;
	}
	return arr[max];
}


template<class T>
void printArr(T arr[])
{
	for(int i = 0; i < LEN; ++i)
		cout << arr[i] << " ";
}
