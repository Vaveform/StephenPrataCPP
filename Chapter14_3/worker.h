#ifndef WORKER_H_
#define WORKER_H_

#include <string>


class Worker
{
	private:
		std::string fullname;
		long id;
	protected:
		// For setting and getting data for every part
		// of inheritence
		virtual void Data() const; // Print fullname and id
		virtual void Get(); // Setting from std input
	public:
		Worker();
		Worker(const std::string& s, long n);
		virtual ~Worker();
		virtual void Set() = 0;
		virtual void Show() const = 0;

};

class Waiter : virtual public Worker
{
	private:
		int panache;
	protected:
		void Data() const;
		void Get();
	public:
		Waiter();
		Waiter(const std::string& s, long n, int p = 0);
		Waiter(const Worker& wk, int p = 0);
		void Set();
		void Show() const;
		~Waiter();
};

class Singer : virtual public Worker
{
	protected:
		enum{other, alto, contralto, soprano, bass, baritone, tenor};
		enum{Vtypes = 7};
		void Data() const;
		void Get();
	private:
		static char *pv[Vtypes];
		int voice;
	public:
		Singer();
		Singer(const std::string& s, long n, int v = other);
		Singer(const Worker& wk, int v = other);
		void Set();
		void Show() const;
		~Singer();
};

class SingingWaiter : public Singer, public Waiter
{
	protected:
		void Data() const;
		void Get();
	public:
		SingingWaiter();
		SingingWaiter(const std::string& s, long n, int p = 0, 
				int v = other);
		SingingWaiter(const Worker& wk, int p = 0, int v = other);
		SingingWaiter(const Singer& wt, int p = 0);
		SingingWaiter(const Waiter& ww, int v = other);
		void Set();
		void Show() const;
		~SingingWaiter();

};


#endif
