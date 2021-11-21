#include <iostream>


void first_output();

void second_output(void);



int main()
{

	first_output();
	first_output();

	second_output();
	second_output();
	return 0;
}


void first_output()
{
	using namespace std;
	cout << "Three blind mice" << endl;
}

void second_output()
{
	using std::cout;
	using std::endl;
	cout << "See how they run" << endl;
}
