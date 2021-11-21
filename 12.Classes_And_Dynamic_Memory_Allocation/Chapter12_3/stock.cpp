#include <iostream>
#include "stock.h"

Stock::Stock(const char* ptr, long n, double pr)
{
	std::cout << "Constructor of " << this << std::endl;
	company = new char[std::strlen(ptr) + 1];
	std::strcpy(company, ptr);
	if(n < 0){
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::Stock(const Stock& other) : shares(other.shares), share_val(other.share_val) {
	std::cout << "Copy constructor of " << this << " with object " << &other << std::endl; 
	set_tot();
	company = new char[std::strlen(other.company) + 1];
	std::strcpy(company, other.company);

}

Stock& Stock::operator=(const Stock& other){
	std::cout << "Assign " << &other << " to " << this << std::endl;
	if(this == &other){
		return *this;
	}
	delete[] company;
	company = new char[std::strlen(other.company) + 1];
	std::strcpy(company, other.company);
	shares = other.shares;
	share_val = other.share_val;
	set_tot();
}
Stock::~Stock(){
	std::cout << "Destructor of object " << this << std::endl;
	delete [] company;
}
void Stock::buy(long num, double price)
{
	if(num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if(num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if(num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
std::ostream& operator<<(std::ostream& os, const Stock& st) {
	using std::cout;
	using std::ios_base;
	// Setting #.### format
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	os << "Company: " << st.company
		<< " Shares: " << st.shares << '\n';
        os << " Share Price: $" << st.share_val << '\n';
	// Setting format #.##
	os.precision(2);
	os << " Total Worth: $" << st.total_val; 
	// Setting previous format
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}

const Stock& Stock::topval(const Stock& s) const
{
	if(s.total_val > total_val)
		return s;
	else
		return *this;
}
