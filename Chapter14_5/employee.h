#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

class abstr_emp
{
	private:
		std::string fname;
		std::string lname;
		std::string job;
	public:
		abstr_emp();
		abstr_emp(const std::string& fn, const std::string& ln,
				const std::string& j);
		virtual std::ostream& ShowAll(std::ostream& os) const;
		virtual std::istream& SetAll(std::istream& is);
		friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
		friend std::istream& operator>>(std::istream& is, abstr_emp& e);
		virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
	public:
		employee();
		employee(const std::string& fn, const std::string& ln,
				const std::string& j);
		virtual std::ostream& ShowAll(std::ostream& os) const;
		virtual std::istream& SetAll(std::istream& is);
};

class manager : virtual public abstr_emp
{
	private:
		int inchargeof;
	protected:
		int InChargeOf() const;
		int& InChargeOf();
	public:
		manager();
		manager(const std::string& fn, const std::string& ln,
				const std::string& j, int ico = 0);
		manager(const abstr_emp& e, int ico);
		manager(const manager& m);
		virtual std::ostream& ShowAll(std::ostream& os) const;
		virtual std::istream& SetAll(std::istream& is);
};

class fink : virtual public abstr_emp
{
	private:
		std::string reportsto;
	protected:
		const std::string ReportsTo() const;
		std::string& ReportsTo();
	public:
		fink();
		fink(const std::string& fn, const std::string & ln,
				const std::string& j, const std::string& rpo);
		fink(const abstr_emp& e, const std::string& rpo);
		fink(const fink & e);
		virtual std::ostream& ShowAll(std::ostream& os) const;
		virtual std::istream& SetAll(std::istream& is);
};

class highfink : public manager, public fink
{
	public:
		highfink();
		highfink(const std::string& fn, const std::string& ln,
				const std::string& j, const std::string& rpo,
				int ico);
		highfink(const abstr_emp& e, const std::string& rpo, int ico);
		highfink(const fink& f, int ico);
		highfink(const manager& m, const std::string & rpo);
		highfink(const highfink& h);
		virtual std::ostream& ShowAll(std::ostream& os) const;
		virtual std::istream& SetAll(std::istream& is);
};

#endif
