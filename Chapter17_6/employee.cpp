#include "employee.h"

using std::cout;
using std::cin;
using std::endl;


abstr_emp::abstr_emp() : fname("Null"), lname("Null"), job("abstr_emp")
{
	
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
		const std::string& j) : fname(fn), lname(ln), job(j)
{

}

abstr_emp::~abstr_emp()
{
}

bool abstr_emp::with_hint = false;

void abstr_emp::ChangeHintStatus(bool _with_hint) { with_hint = _with_hint; }

bool abstr_emp::HintStatus() { return with_hint; }

std::ostream& abstr_emp::ShowAll(std::ostream& os) const
{
	if(HintStatus()) os << "First name: ";
	os << fname << endl;
	if(HintStatus()) os << "Last name: ";
	os << lname << endl;
	if(HintStatus()) os << "Job: ";
	os << job << endl;
	return os;
}

std::istream& abstr_emp::SetAll(std::istream& is)
{
	if(HintStatus()) cout << "Enter first name: ";
	getline(is, fname);
	if(HintStatus()) cout << "Enter last name: ";
	getline(is, lname);
	if(HintStatus()) cout << "Enter job: ";
	getline(is, job);
	return is;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	// Here will be polimorphism
	// ref abstr_emp& can ref to all object from
	// current hierarchy
	return e.ShowAll(os);
}

std::istream& operator>>(std::istream& is, abstr_emp& e)
{
	return e.SetAll(is);
}

employee::employee() : abstr_emp()
{

}

employee::employee(const std::string& fn, const std::string& ln,
		const std::string& j) : abstr_emp(fn, ln, j)
{

}

std::ostream& employee::ShowAll(std::ostream& os) const
{
	os << "Category: employee" << endl;
	return abstr_emp::ShowAll(os);
}

std::istream& employee::SetAll(std::istream& is)
{
	if(HintStatus()) cout << "Enter data for employee." << endl;
	return abstr_emp::SetAll(is);
}

manager::manager() : abstr_emp(), inchargeof(0)
{

}

manager::manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{

}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof)
{

}

int manager::InChargeOf() const
{
	return inchargeof;
}

int& manager::InChargeOf()
{
	return inchargeof;
}

std::ostream& manager::ShowAll(std::ostream& os) const
{
	os << "Category: manager" << endl;
	abstr_emp::ShowAll(os);
	if(HintStatus()) os << "In charge of(number): ";
        os << inchargeof << endl;
	return os;
}

std::istream& manager::SetAll(std::istream& is)
{
	if(HintStatus()) cout << "Enter data for manager." << endl;
	abstr_emp::SetAll(is);
	if(HintStatus()) cout << "Enter number of wards: ";
	is >> inchargeof;
	while(is.get() != '\n')
		continue;
	return is;
}

fink::fink() : abstr_emp(), reportsto("Null")
{

} 

fink::fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), 
	reportsto(rpo)
{

}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto)
{

}

const std::string fink::ReportsTo() const
{
	return reportsto;
}

std::string& fink::ReportsTo()
{
	return reportsto;
}

std::ostream& fink::ShowAll(std::ostream& os) const
{
	os << "Category: fink" << endl;
	abstr_emp::ShowAll(os);
	if(HintStatus()) os << "This fink reports to: "; 
	os << reportsto << endl;
	return os;
}

std::istream& fink::SetAll(std::istream& is)
{
	if(HintStatus()) cout << "Enter data for fink." << endl;
	abstr_emp::SetAll(is);
	if(HintStatus()) cout << "Enter name for report to: ";
	getline(is, reportsto);
	return is;
}

highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo,
		int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), 
	fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e),
	manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager& m, const std::string& rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h)
{

}

std::ostream& highfink::ShowAll(std::ostream& os) const
{
	os << "Category: highfink" << endl;
	abstr_emp::ShowAll(os);
	if(HintStatus()) os << "In charge of(number): ";
        os << InChargeOf() << endl;
	if(HintStatus()) os << "This highfink reports to: "; 
	os << ReportsTo() << endl;
	return os;
}

std::istream& highfink::SetAll(std::istream& is)
{
	if(HintStatus()) cout << "Enter data for highfink." << endl;
	abstr_emp::SetAll(is);
	if(HintStatus()) cout << "Enter number of wards: ";
	int& ico_ref = InChargeOf();
	is >> ico_ref;
	while(is.get() != '\n')
		continue;
	if(HintStatus()) cout << "Enter name for report to: ";
	std::string& rpo_ref = ReportsTo();
	getline(is, rpo_ref);

}

std::unique_ptr<abstr_emp> CreateEmployee(char _type)
{
	std::unique_ptr<abstr_emp> result(nullptr);
	switch(_type){
		case 'e': 
			result = std::make_unique<employee>();
			break;
		case 'm':
			result = std::make_unique<manager>();
			break;
		case 'f':
			result = std::make_unique<fink>();
			break;
		case 'h':
			result = std::make_unique<highfink>();
			break;
		default:
			throw std::bad_alloc();
	}
	return result;
}
