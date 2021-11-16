#include <iostream>

using namespace std;

int main()
{
	int nums = 0;
	cout << "Enter number of lines: ";
	cin >> nums;
	if(nums < 0) return EXIT_FAILURE;
	char* line = new char[nums + 1];
	for(int i = 0; i < nums; ++i)
		line[i] = '.';
	line[nums] = '\0';
	for(int i = nums - 1; i >= 0; --i){
		line[i] = '*';
		cout << line << endl;
	}
	delete[] line;
	return 0;
}
