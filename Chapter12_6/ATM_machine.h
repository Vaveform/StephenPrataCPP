#ifndef ATM_MACHINE
#define ATM_MACHINE

#include "queue2.h"

class ATM_Machine{
	private:
		Queue queue;
		int wait_time;
		long line_length;
		friend class BankFacade;
	public:
		ATM_Machine(const ATM_Machine& other) = delete;
		ATM_Machine& operator=(const ATM_Machine& other) = delete;
		ATM_Machine(int qs = 10);
	
};


#endif
