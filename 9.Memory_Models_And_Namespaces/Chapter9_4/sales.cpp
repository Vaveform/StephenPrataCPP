#include <iostream>
#include <iomanip>

#include "sales.h"


namespace SALES{
	void setSales(Sales& s, const double ar[], int n){
		s.average = 0.0;
		for(int i = 0; i < QUARTERS; ++i){
			if(i < n){
				s.sales[i] = ar[i];
				s.average += s.sales[i];
				if(i == 0) s.min = s.max = s.sales[i];
				else{
					if(s.sales[i] < s.min) s.min = s.sales[i];
					if(s.sales[i] > s.max) s.max = s.sales[i];
				}
			}
			else{
				s.sales[i] = 0.0;
			}
		}
		s.average /= ((n < QUARTERS) ? n : QUARTERS);
	}

	void setSales(Sales& s){
		for(int i = 0; i < QUARTERS; ++i){
			std::cout << "Input number of sales for quarter #" << i + 1 << ": ";
			std::cin >> s.sales[i];
		}
		setSales(s, s.sales, QUARTERS);
	}

	void showSales(const Sales& s){
		std::cout << "Sales per quarters:" << std::endl;
		for(int i = 0; i < QUARTERS; ++i){
			std::cout << "Quarter #" << i+1 << " has sales: " << s.sales[i] << std::endl;
		}
		std::cout << "Average: " << s.average << std::endl;
		std::cout <<  "Min: " << s.min << std::endl;
		std::cout << "Max: " << s.max << std::endl;
	}
}
