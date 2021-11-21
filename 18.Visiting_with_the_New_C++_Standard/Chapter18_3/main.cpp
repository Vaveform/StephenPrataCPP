#include <iostream>

using namespace std;


long double sum_values()
{
	cout << "Called based function" << endl;
	return 0;
}

template<typename T, typename ...Argc>
long double sum_values(T val,Argc... argc){
	static int initiated = 0;
	initiated++;
	cout << "Initiated: " << initiated << endl;
	cout << "Unpakced type: " << typeid(T).name() << " with value: " << val << endl;
	return val + sum_values(argc...);
}


int main()
{
	cout << sum_values(1.5, 2, 0, 1000L, 'A', 'B', 5.9) << endl;
	return 0;
}
