#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
using namespace std;

int main()
{
	size_t N = 10'000'000;
	// Part a. of task
	clock_t start = clock();
	vector<int> vi0(N);
	generate(vi0.begin(), vi0.end(), rand);
	cout << "vector<int> vi0 creation with " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	//vector<int> arr;
	//generate_n(back_inserter(arr), N, rand);
	//copy(arr.begin(), arr.end(), ostream_iterator<int, char>(cout, "\n"));
	
	
	// Part b. of task
	start = clock();
	list<int> li(vi0.begin(), vi0.end());
	cout << "list<int> li creation with " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	
	
	start = clock();
	vector<int> vi(vi0.begin(), vi0.end());
	cout << "vector<int> vi creation with " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;


	// Part c. of task
	start = clock();
	sort(vi.begin(), vi.end());
	cout << "vector<int> sorting " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	
	start = clock();
	li.sort();
	cout << "list<int> sorting(method) " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;

	
	// Part d. of task
	copy(vi0.begin(), vi0.end(), li.begin()); // setting list to unsorted
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	cout << "list<int> sorting(copy to vector vi, sorting vector vi and copy to li) " << N << " elements: "  
		<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;

	cout << "li is sorted really? " << is_sorted(li.begin(), li.end()) << endl;
	return 0;
}
