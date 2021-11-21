#include "exceptions_mean.h"

//bad_hmean::bad_hmean(double a, double b) : v1(a), v2(b)
//{
//}
//
//void bad_hmean::mesg()
//{
//	std::cout << "hmean(" << v1 << ", " << v2 << "): "
//		<< "invalid arguments: a = -b\n";
//}
//
//bad_gmean::bad_gmean(double a, double b) : v1(a), v2(b)
//{
//
//}
//
//const char* bad_gmean::mesg()
//{
//	return "gmean() arguments should be >= 0\n";
//}

mean_error::mean_error(double a, double b) : v1(a), v2(b), std::logic_error("")
{
}

mean_error::~mean_error(){};

const double& mean_error::v1_ref() const
{
	return v1;
}

const double& mean_error::v2_ref() const
{
	return v2;
}




bad_hmean::bad_hmean(double a, double b) : mean_error(a, b)
{
}


const char* bad_hmean::what() const noexcept
{
	return "invalid arguments: a = -b in hmean function";
}

void bad_hmean::mesg() const
{
	using std::cout;
	using std::endl;
	cout << "hmean(" << v1_ref() << ", " << v2_ref() << "): "
		<< what() << endl;
}


bad_gmean::bad_gmean(double a, double b) : mean_error(a, b)
{
}

const char* bad_gmean::what() const noexcept
{
	return "gmean() arguments should be >= 0";
}

void bad_gmean::mesg() const
{
	using std::cout;
	using std::endl;
	cout << "gmean(" << v1_ref() << ", " << v2_ref() << "): "
		<< what() << endl;
}
