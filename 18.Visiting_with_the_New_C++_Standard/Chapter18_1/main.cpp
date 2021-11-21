#include <iostream>
#include <initializer_list>
#include <numeric>
#include <typeinfo>
#include <algorithm>


template <template <typename ...> typename DataStructure, typename T>
class Printer
{
	std::ostream& os;
	const DataStructure<T>& d_s;
	public:
	Printer(std::ostream& _os, const DataStructure<T>& _d_s) : os(_os), d_s(_d_s){
		std::cout << "Passed initilizer list with size " << d_s.size()
			<< " and type " << typeid(T).name() << " has values: " << std::endl;
	};
	void operator()(const T& to_print)
	{
		os << to_print << std::endl;
	}
};


template<typename T>
T average_list(const std::initializer_list<T>& l)
{
	using namespace std;
	for_each(l.begin(), l.end(), Printer<std::initializer_list, T>(cout, l));
	T init = 0;
	return std::accumulate(l.begin(), l.end(), init) / l.size();
}



int main()
{
	using namespace std;

	auto q = average_list({15.4, 10.7, 9.0});
	cout << "Result: " << q << endl;

	cout << "Result: " << average_list({20, 30, 19, 17, 45, 38}) << endl;

	auto ad = average_list<double>({'A', 70, 65.33});
        cout << "Result: " << ad << endl;
	return 0;	
}
