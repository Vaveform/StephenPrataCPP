#include "time0.h"
Time::Time()
{
	this->hours = this->minutes = 0;
}
Time::Time(unsigned int h, unsigned int m)
{
	this->Reset(h, m);
}
void Time::AddMin(unsigned int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(unsigned int h)
{
	this->hours += h;
}
void Time::Reset(unsigned int h, unsigned int m)
{
	this->hours = h;
	this->minutes = 0;
	this->AddMin(m);
}
// In definition (cpp) we should not write word friend
Time operator+(const Time& l_s, const Time& r_s) {
	return Time(l_s.hours + r_s.hours, l_s.minutes + r_s.minutes);
}


Time operator-(const Time& l_s, const Time& r_s){
	unsigned long long l_hsum = l_s.hours * 60 + l_s.minutes;
	unsigned long long r_hsum = r_s.hours * 60 + r_s.minutes;
	if(l_hsum < r_hsum){
		std::cout << "Warning! Left hand time value smaller than right hand" << std::endl;
		return Time();
	}
	
	return Time((l_hsum - r_hsum) / 60, (l_hsum - r_hsum) % 60);
}

Time operator*(const Time& l_s, double n){
	unsigned long long summary = n * (l_s.hours * 60 + l_s.minutes);
	return Time(summary / 60, summary % 60);
}

Time operator*(double n, const Time& r_s){
	return r_s * n;
}

std::ostream& operator<<(std::ostream& os, const Time& t){
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

