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


// First variant
//bad_hmean::bad_hmean() : std::logic_error("")
//{
//}
//
//
//const char* bad_hmean::what() const noexcept
//{
//	return "invalid arguments: a = -b in hmean function";
//}
//
//
//bad_gmean::bad_gmean() : std::logic_error("")
//{
//}
//
//const char* bad_gmean::what() const noexcept
//{
//	return "gmean() arguments should be >= 0";
//}


//Second variant - std::logic_error saving error string info
//in the field - we can set by default value in .h file
//in constructor. When we calling what() in this way, we calling
//std::logic_error::what() version which returning saved string error
//info
bad_hmean::bad_hmean(const char* wht) : std::logic_error(wht)
{

}

bad_gmean::bad_gmean(const char* wht) : std::logic_error(wht)
{

}
