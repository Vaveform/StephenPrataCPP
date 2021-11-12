#include <iostream>


#include "sales.h"


namespace SALES{
	void Sales::CalculateSales(const double ar[], int n){
		this->average = 0.0;
		for(int i = 0; i < QUARTERS; ++i){
			if(i < n){
				this->sales[i] = ar[i];
				this->average += this->sales[i];
				if(i == 0) this->min = this->max = this->sales[i];
				else{
					if(this->sales[i] < this->min) this->min = this->sales[i];
					if(this->sales[i] > this->max) this->max = this->sales[i];
				}
			}
			else{
				this->sales[i] = 0.0;
			}
		}
		this->average /= ((n < QUARTERS) ? n : QUARTERS);
	}
	Sales::Sales(const double ar[], int n){
		std::cout << "Calling constructor" << std::endl;
		this->CalculateSales(ar, n);
	}
	void Sales::setSales(){
		for(int i = 0; i < QUARTERS; ++i){
			std::cout << "Input number of sales for quarter #" << i + 1 << ": ";
			std::cin >> this->sales[i];
		}
		Sales tmp(this->sales, QUARTERS);
		*this = tmp;
	}
	void Sales::showSales() const {
		std::cout << "Sales per quarters:" << std::endl;
		for(int i = 0; i < QUARTERS; ++i){
			std::cout << "Quarter #" << i+1 << " has sales: " << this->sales[i] << std::endl;
		}
		std::cout << "Average: " << this->average << std::endl;
		std::cout <<  "Min: " << this->min << std::endl;
		std::cout << "Max: " << this->max << std::endl;

	}
	Sales::~Sales(){
		std::cout << "Destructor called" << std::endl;
	}


}
