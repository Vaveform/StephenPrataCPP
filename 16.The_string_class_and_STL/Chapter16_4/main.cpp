#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int reduce(long ar[], int n);


int main()
{
	const int N = 10;
	long arr[N] = {1l,2l,1l,1l,3l,3l,3l,4l,5l,4l};
	cout << "Reduced array size: " << reduce(arr, N) << endl;
	return 0;
}

int reduce(long ar[], int n)
{
	cout << "Input array: ";
	copy(ar, ar + n, ostream_iterator<long, char>(cout, " "));
	cout << endl;

	sort(ar, ar + n);
	cout << "After sort() function: ";
	copy(ar, ar + n, ostream_iterator<long, char>(cout, " "));
	cout << endl;
	
	// we have sorted array. For sorted array unique
	// move all duplicates to the end of array(copy/swaping)
	// returned value - iterator (pointer) to begin of 
	// duplicated value part.
	long* it = unique(ar, ar + n);
	cout << "After unique() function: ";
	// it - end of expected array (without duplicates)
	copy(ar, it, ostream_iterator<long, char>(cout, " "));
	cout << endl;
	// For stl containers we should use methods to erase/deleted
	// 'tail' of container with duplicates
	return it - ar;
}
