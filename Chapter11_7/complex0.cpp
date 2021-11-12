#include "complex0.h"


Complex::Complex(double _real, double _im){
	this->real = _real;
	this->im = _im;
}

Complex::~Complex(){
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
	os << "(" << c.real << "," << c.im << "i)";
	return os;
}
std::istream& operator>>(std::istream& is, Complex& c){
	std::cout << "real: ";
	// If we input (cin) q or not number, next line of cout print Done!
	// without if(is >> c.real) - imaginary: Done!
	if(is >> c.real)
		std::cout << "imaginary: ";
		is >> c.im;
	return is;
}

Complex Complex::operator+(const Complex& r_h) const{
	return Complex(this->real + r_h.real, this->im + r_h.im);
}

Complex Complex::operator-(const Complex& r_h) const{
	return Complex(this->real - r_h.real, this->im - r_h.im);
}

Complex operator*(double x, const Complex& r_h){
	return Complex(x * r_h.real, x * r_h.im);
}

Complex Complex::operator*(double x) const{
	return x * (*this);
}

Complex Complex::operator*(const Complex& r_h) const {
	return Complex(this->real * r_h.real - this->im * r_h.im, 
			this->real * r_h.im + this->im * r_h.real);
}

Complex Complex::operator~()const{
	return Complex(this->real, -(this->im));
}



