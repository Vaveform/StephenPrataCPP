#ifndef EXCEPTIONS_MEAN_H_
#define EXCEPTIONS_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <string>


class bad_hmean : public std::logic_error
{
	//private:
	//	double v1;
	//	double v2;
	//public:
	//	bad_hmean(double a = 0, double b = 0);
	//	void mesg();
	public:
		bad_hmean(const char* wht = "invalid arguments: a = -b in hmean function");
		//bad_hmean();
		//const char* what() const noexcept;
};

class bad_gmean : public std::logic_error
{
	//public:
	//	double v1;
	//	double v2;
	//	bad_gmean(double a = 0, double b = 0);
	//	const char * mesg();
	public:
		bad_gmean(const char* wht = "gmean() arguments should be >= 0\n");
		//bad_gmean();
		//const char* what() const noexcept;
};


#endif
