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
	double Vector::calc_mag() const
	{
		return sqrt(this->x * this->x + this->y * y);
	}
	double Vector::calc_ang() const
	{
		double _ang = 0.0;
		if(this->x == 0.0 && this->y == 0.0)
			_ang = 0.0;
		else
			_ang = atan2(this->y, this->x);
		return _ang;
	}
	// Setting x by polar coordinates, _ang in radians
	void Vector::set_x(const double& _mag, const double& _ang)
	{
		this->x = _mag * cos(_ang);
	}
	// Setting y by polar coordinates, _ang in radians
	void Vector::set_y(const double& _mag,const double& _ang)
	{
		this->y = _mag * sin(_ang);
	}
	// Public methods
	Vector::Vector()
	{
		this->x = this->y = 0.0;
		this->mode = RECT;
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		this->mode = form;
		if(form == RECT)
		{
			this->x = n1;
			this->y = n2;
		}
		else if(form == POL)
		{
			// n2 - number of degrees
			// ang = n2 / Rad_to_deg;
			set_x(n1, n2 / Rad_to_deg);
			set_y(n1, n2 / Rad_to_deg);
		}
		else{
			cout << "Incorrect 3rd argument to Vector() -";
			cout << "vector set to 0\n";
			this->x = this->y = 0.0;
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
			// Output in degrees
			os << "(m,a) = (" << v.calc_mag() << ", "
			       << v.calc_ang() * Rad_to_deg << ")";	
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}

}

