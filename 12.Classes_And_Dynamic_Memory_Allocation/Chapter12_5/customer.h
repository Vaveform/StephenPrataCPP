#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer
{
	private:
		// Moment of the client arrivement
		long arrive;
		// Duration of the using bank terminal by client
		int processtime;
	public:
		Customer();
		void set(long when);
		long when() const;
		int ptime() const;
};


#endif
