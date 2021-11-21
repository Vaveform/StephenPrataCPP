#ifndef SALES_H_
#define SALES_H_

// Here we can wrtie #pragma once instead #ifndef #define #endif

#include <iostream>

namespace SALES{
	static double default_arr[] = {0.0, 0.0, 0.0, 0.0};
	class Sales{
		private:
			// Это не переменная член класса! 
			// Это просто символическое имя, 
			// которое компилятор заменяет на число 4, 
			// когда встречает его в области видимости класса
			// Это первый способ задания константы для размера массива
			// (общая между объектами)
			// enum {QUARTERS = 4};
			// Второй способ - использовать static в области видимости класса
			// Общая переменная для всех объектов (разделяемая).
			// Размер этой переменной не входит в размер объекта и живет
			// все время работы программы
			static const int QUARTERS = 4;


			// static variables and unused enums(or static enums) do not exist
			// in sizeof(T) - size of variable(type)
			//
			// Elements of enum accessible in all class namespace 
			// (область видимости класса). But in C++ there are
			// enum classes in which elements inaccessable
			// and we can not implicitly cast enum class type (we should use
			// static_cast for example or C-style). 
			// Also in enum class/struct or enum available
			// to set size of this type, by using inheritance syntax for example:
			// enum class DAYS : char {A,B,C} - sizeof(DAY) - 1 byte;
			double sales[QUARTERS];
			double average;
			double max;
			double min;
			void CalculateSales(const double ar[], int n);
		public:
			// Default and parametr constructor
			Sales(const double ar[] = default_arr, int n = 4);
			~Sales();
			void setSales();
			void showSales() const;



	};
}


#endif
