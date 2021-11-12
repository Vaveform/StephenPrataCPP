#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class Complex{
	private:
		double real;
		double im;
	public:
		Complex(double _real = 0.0, double _im = 0.0);
		~Complex();
		friend std::ostream& operator<<(std::ostream&, const Complex&);
		friend std::istream& operator>>(std::istream&, Complex&);
		Complex operator+(const Complex&) const;
		Complex operator-(const Complex&) const;
		Complex operator*(const Complex&) const;
		Complex operator*(double x) const;
		friend Complex operator*(double x, const Complex&);
		Complex operator~() const;


};

#endif
