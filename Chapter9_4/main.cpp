#include <iostream>

#include "sales.h"


int main(){
	using namespace SALES;
	Sales s1;
	Sales s2;
	double arr[4] = {3.1, 5.4, 2.3, 3.5};

	setSales(s1, arr, 4);
	showSales(s1);
	setSales(s2);
	showSales(s2);
	return 0;
}
