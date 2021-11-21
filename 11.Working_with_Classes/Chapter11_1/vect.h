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
			double mag;	// длина вектора
			double ang;	// направление вектора в градусах
			Mode mode;	// RECT или POL

			// Закрытые методы для установки значений
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
		public:
			Vector();
			// Не нужно писать Mode::RECT - элементы enum доступны 
			Vector(double n1, double n2, Mode form = RECT);
			void reset(double n1, double n2, Mode form = RECT);
			~Vector();
			double xval() const { return x; }
			double yval() const { return y; }
			double magval() const { return mag; }
			double angval() const {return ang; }
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
