#include <cmath>
#include "vect.h"	// уже включен iostream
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
namespace VECTOR
{
	// Degrees in one radian
	const double Rad_to_deg = 45.0 /atan(1.0);
	// approximately ~57.2957795130823
	
	// Private methods
	void Vector::set_mag()
	{
		this->mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang()
	{
		if(this->x == 0.0 && this->y == 0.0)
			this->ang = 0.0;
		else
			this->ang = atan2(this->y, this->x);
	}
	// Setting x by polar coordinates
	void Vector::set_x()
	{
		this->x = this->mag * cos(this->ang);
	}
	// Setting y by polar coordinates
	void Vector::set_y()
	{
		this->y = this->mag * sin(this->ang);
	}
	// Public methods
	Vector::Vector()
	{
		this->x = this->y = this->mag = this->ang = 0.0;
		this->mode = RECT;
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		this->mode = form;
		if(form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if(form == POL)
		{
			mag = n1;
			// n2 - number of degrees
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument to Vector() -";
			cout << "vector set to 0\n";
			this->x = this->y = this->mag = this->ang = 0.0;
			this->mode = RECT;
		}
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		this->reset(n1, n2, form);
	}
	Vector::~Vector()
	{
	}
	void Vector::polar_mode()
	{
		this->mode = POL;
	}
	void Vector::rect_mode()
	{
		this->mode = RECT;
	}

	// Overloading operations
	// Sum of two vectors
	Vector Vector::operator+(const Vector& b) const
	{
		// Calling constructor of Vector with default 
		// parametr (Mode = RECT). Returning object
		// has RECT mode.
		return Vector(this->x + b.x, this->y + b.y);
	}
	// Diff of two vectors (a - b, where a - caller)
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(this->x - b.x, this->y - b.y);
	}
	// Changing sign of vector (multiply with -1)
	Vector Vector::operator-() const
	{
		// For fields x and y (standard type - double) of Vector 
		// unary minus already overloaded.
		return Vector(-(this->x), -(this->y));
	}
	// Vector * n - multiply Vector with n.
	Vector Vector::operator*(double n) const
	{
		return Vector(n * this->x, n * this->y);
	}
	// n * Vector - multiply n with Vector
	// Using friend function for providing correct
	// order operands. If we use overloading as function-member
	// we fix one of the operand (caller) on the first place
	Vector operator*(double n, const Vector& a)
	{
		// Calling member function operator overloading
		return a*n;
	}

	// Showing coordinates
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if(v.mode == Vector::RECT)
			os << " (x,y) = (" << v.x << ". " << v.y << ")";
		else if(v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", "
			       << v.ang * Rad_to_deg << ")";	
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}

}

