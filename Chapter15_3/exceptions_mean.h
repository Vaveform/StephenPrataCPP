#ifndef EXCEPTIONS_MEAN_H_
#define EXCEPTIONS_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <string>


class mean_error : public std::logic_error
{
	private:
		double v1;
		double v2;
	protected:
		const double& v1_ref() const;
		const double& v2_ref() const;
	public:
		mean_error(double a = 0, double b = 0);
		virtual void mesg() const = 0;
		virtual ~mean_error() = 0;
};


class bad_hmean : public mean_error
{
	public:
		bad_hmean(double a = 0, double b = 0);
		void mesg() const;
		const char* what() const noexcept;
};

class bad_gmean : public mean_error
{
	public:
		bad_gmean(double a = 0, double b = 0);
		void mesg() const;
		const char* what() const noexcept;
};


#endif
