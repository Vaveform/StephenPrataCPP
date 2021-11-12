#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR{
	class Vector{
		public:
			enum Mode {RECT, POL};
			// RECT - режим прямоугольных координат.
			// POL - для режима полярных координат.
		private:
			double x;	// горизонтальная координата
			double y;	// вертикальная координата
			Mode mode;	// RECT или POL

			// Закрытые методы для установки значений
			double calc_mag() const;
			double calc_ang() const;
			void set_x(const double& _mag, const double& _ang);
			void set_y(const double& _mag, const double& _ang);
		public:
			Vector();
			// Не нужно писать Mode::RECT - элементы enum доступны 
			// If form == POL, n2 in degrees
			Vector(double n1, double n2, Mode form = RECT);
			// If calling reset wtih form = RECT it is interpreted
			// as x - n1 and y - n2, else mag - n1 and ang - n2
			// In this task if form = POL n1 and n2 parametrs 
			// translated to x and y 
			void reset(double n1, double n2, Mode form = RECT);
			~Vector();
			double xval() const { return this->x; }
			double yval() const { return this->y; }
			double magval() const { return calc_mag(); }
			double angval() const {return calc_ang(); }
			// Set POL mode
			void polar_mode();
			// Set RECT mode
			void rect_mode();

			// Operators overloading
			Vector operator+(const Vector& b) const;
			Vector operator-(const Vector& b) const;
			Vector operator-() const;
			Vector operator*(double n) const;

			// Друзья
			friend Vector operator*(double n, const Vector& a);
			friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif
