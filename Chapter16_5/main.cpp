#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;



template <typename T>
int reduce(T ar[], int n);


int main()
{
	const int N = 10;
	long arr1[N] = {1l,2l,1l,1l,3l,3l,3l,4l,5l,4l};
	string arr2[N] = {"for", "main", "for", "game", "player", "succesful", "game", "for", "for", "game"};
	int result = reduce(arr1, N);
	cout << "Reduced array size (long type): " << result << endl;
	result = reduce(arr2, N);
	cout << "Reduced array size (std::string type): " << result << endl;
	return 0;
}


template <typename T>
int reduce(T ar[], int n)
{
	cout << "Input array: ";
	copy(ar, ar + n, ostream_iterator<T, char>(cout, " "));
	cout << endl;

	sort(ar, ar + n);
	cout << "After sort() function: ";
	copy(ar, ar + n, ostream_iterator<T, char>(cout, " "));
	cout << endl;
	
	// we have sorted array. For sorted array unique
	// move all duplicates to the end of array(copy/swaping)
	// returned value - iterator (pointer) to begin of 
	// duplicated value part.
	T* it = unique(ar, ar + n);
	cout << "After unique() function: ";
	// it - end of expected array (without duplicates)
	copy(ar, it, ostream_iterator<T, char>(cout, " "));
	cout << endl;
	// For stl containers we should use methods to erase/deleted
	// 'tail' of container with duplicates
	return it - ar;
}
