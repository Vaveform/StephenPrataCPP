#ifndef TIME0_H_
#define TIME0_H_
#include <iostream>
class Time
{
	private:
		int hours;
		int minutes;
	public:
		Time();
		Time(unsigned int h, unsigned int m = 0);
		void AddMin(unsigned int m);
		void AddHr(unsigned int h);
		void Reset(unsigned int h = 0, unsigned int m = 0);
		// In declaration of class we should say that these 
		// overloadings are friends and they have access to
		// private section of class Time. But we can using methods
		// for overloading
		friend Time operator+(const Time&, const Time&);
		friend Time operator-(const Time&, const Time&);
		friend Time operator*(const Time&, double n);
		friend Time operator*(double n, const Time&);
		friend std::ostream& operator<<(std::ostream&, const Time&);
};

#endif
