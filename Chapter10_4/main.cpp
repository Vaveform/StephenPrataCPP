#include <iostream>

#include "sales.h"


int main(){
	using namespace SALES;
	Sales s1;
	s1.showSales();
	s1.setSales();
	double arr[4] = {3.1, 5.4, 2.3, 3.5};
	Sales s2(arr, 4);
	s2.showSales();
	s1.showSales();
	return 0;
}
